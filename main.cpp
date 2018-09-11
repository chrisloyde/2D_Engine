#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdio>
#include <string>
#include <sstream>
#include "textures/Texture.h"
#include "textures/sprites/renderers/headers/TileRenderer.h"
#include "objects/headers/Timer.h"
#include "objects/entity/headers/EntityPlayer.h"
#include "objects/block/headers/Tile.h"
#include "objects/headers/World.h"
#include <SDL_ttf.h>

// define program variables
// defines number of pixels for the height and width of the world.
// should be divisible by tile size (width and height) for clean results.
const int WORLD_WIDTH = 1920;
const int WORLD_HEIGHT = 1920;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Window *window = nullptr; //The window being rendered to
SDL_Surface *screenSurface = nullptr; // The surface contained by the window
SDL_Renderer *renderer = nullptr; // window renderer
//SDL_Texture *texture = nullptr; // texture to render.
SDL_Color systemTextColor = {0,0,0,255};
TTF_Font *systemFont = nullptr;

TileRenderer tileRenderer(4,32,32);
Texture fpsTextTexture;

SDL_Rect camera = {0,0,SCREEN_WIDTH, SCREEN_HEIGHT};
World world(WORLD_WIDTH/32, (WORLD_HEIGHT/32), 32, 32);
EntityPlayer player(WORLD_WIDTH/2, (WORLD_HEIGHT/2));

// define functions
bool init();
bool loadMedia();
void close();

int main(int argv, char** args) {

    bool quit = false;

    init(); //Initialize
    SDL_Event e; // event handler

    Timer fpsTimer;
    std::stringstream fpsText;

    //start counting fps
    int countedFrames = 0;
    fpsTimer.start();

    // load media
    if (!loadMedia()) {
        std::cerr << "Failed to load media!" << std::endl;
    } else {
        // Application loop (game loop)
        while (!quit) {
            //Handle events in queue
            while (SDL_PollEvent(&e) != 0) {
                //user requested quit (presses X in top right corner of window)
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
                    // Get keyboard input events
                else if (e.type == SDL_KEYDOWN) {
                    // send keyboard input events to whoever needs them
                    player.handleEvent(e);
                }
                // send mouse events to world
                world.handleEvent(&e, camera);
            }

            //Call Updaters
            player.update();

            // Adjust Camera
            // center camera on player
            camera.x = (player.getXPos() + 32/2)-SCREEN_WIDTH/2;
            camera.y = (player.getYPos() +32/2)-SCREEN_HEIGHT/2;
            //keep camera in bounds
            if (camera.x < 0) {
                camera.x = 0;
            }
            if (camera.y < 0) {
                camera.y = 0;
            }
            if (camera.x > WORLD_WIDTH - camera.w) {
                camera.x = WORLD_WIDTH - camera.w;
            }
            if (camera.y > WORLD_HEIGHT - camera.h) {
                camera.y = WORLD_HEIGHT - camera.h;
            }


            //Clear Screen
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(renderer); // clear screen

            //Call Renderers
            world.render(&tileRenderer, renderer, camera); // render world
            player.render(renderer, camera); // render player


            fpsTextTexture.render(renderer, 0, 0); // render fps
            SDL_RenderPresent(renderer); // update screen

            // calculate FPS
            float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
            if (avgFPS > 2000000) { // ensure fps doesn't get too high
                avgFPS = 0;
            }
            fpsText.str("");
            fpsText << "FPS: " << avgFPS;
            if (!fpsTextTexture.loadFromRenderedText(renderer, fpsText.str().c_str(), systemFont, systemTextColor)) {
                std::cerr << "Unable to render FPS texture!" << std::endl;
            }

            ++countedFrames;
        }
    }
   close();

    return 0;
}

bool init() {
    bool success = true;
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        success = false;
    } else {
        // create window
        window = SDL_CreateWindow("2D Engine",
                                  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            success = false;
        } else {
            // create a renderer for the window.
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == nullptr) {
                std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
                success = false;
            } else {
                // initialize renderer color
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

                // initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    std::cerr << "SDL_image could not be initialized! SDL_image error: " << SDL_GetError() << std::endl;
                    success = false;
                }

                //initialize SDL ttf
                if (TTF_Init() == -1) {
                    std::cerr << "SDL ttf could not be initialized! SDL_ttf Error: " << TTF_GetError() << std::endl;
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia() {
    bool success = true;
    tileRenderer.init(renderer,"./textures/sprites/tiles.png"); // load spritesheet for tileRenderer
    player.init(renderer, "./textures/sprites/player.png"); // initilaize player
    systemFont = TTF_OpenFont("./fonts/rpg.otf", 12); // load systemfont
    if (systemFont == NULL) {
        std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
        success = false;
    }
    return success;
}

void close() {
    tileRenderer.free();

    // destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;

    //quit subsystems
    IMG_Quit();
    SDL_Quit();
}