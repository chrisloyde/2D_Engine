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
#include "objects/gui/headers/GUI.h"
#include "objects/handlers/headers/GUIHandler.h"
#include "objects/handlers/headers/GameObjectHandler.h"

#include <SDL_ttf.h>

// define program variables
// defines number of pixels for the height and width of the world.
// should be divisible by tile size (width and height) for clean results.
const static int WORLD_WIDTH = 1920;
const static int WORLD_HEIGHT = 1920;

const static int SCREEN_WIDTH = 640;
const static int SCREEN_HEIGHT = 480;
SDL_Window *window = nullptr; //The window being rendered to
SDL_Surface *screenSurface = nullptr; // The surface contained by the window
SDL_Renderer *renderer = nullptr; // window renderer
//SDL_Texture *texture = nullptr; // texture to render.
SDL_Color systemTextColor = {0,0,0,255};
TTF_Font *systemFont = nullptr;

TileRenderer tileRenderer(4,32,32);
GUIHandler gHandler;
GameObjectHandler oHandler;

SDL_Rect camera = {0,0,SCREEN_WIDTH, SCREEN_HEIGHT};
World world(WORLD_WIDTH/32, (WORLD_HEIGHT/32), 32, 32);
EntityPlayer player((WORLD_WIDTH/2)-32, (WORLD_HEIGHT/2)-32, 32, 32);

// define functions
bool init();
bool loadMedia();
void close();

int main(int argv, char** args) {

    bool quit = false;

    init(); //Initialize
    SDL_Event e; // event handler

    Texture fpsTextTexture;
    Texture playerInfoTexture;

    Timer fpsTimer;
    Timer stepTimer;
    std::stringstream fpsText;
    std::stringstream playerInfo;
    // center camera on player
    camera.x = (player.getXPos() + player.width/2)-SCREEN_WIDTH/2;
    camera.y = (player.getYPos() +player.height/2)-SCREEN_HEIGHT/2;

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
                else {
                    oHandler.handleEvents(e, camera);
                    world.handleEvent(e, camera);
                    gHandler.handleEvents(e);
                }
            }

            //Call Updaters, updaters should be placed in between stepTimer calls
            //If an update requires frame independance this will provide it.
            float timeStep = stepTimer.getTicks() /1000.f;

            world.update();
            oHandler.update(timeStep);
            gHandler.update();

            stepTimer.start();

            //Clear Screen
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(renderer); // clear screen


            //Call Renderers
            world.render(&tileRenderer, renderer, camera); // render world
            oHandler.render(renderer, camera); // render player
            gHandler.render(renderer);

            // update text renderers
            fpsTextTexture.render(renderer, 0, 0); // render fps
            playerInfoTexture.render(renderer,0,24);


            SDL_RenderPresent(renderer); // update screen

            // calculate FPS
            float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
            if (avgFPS > 2000000) { // ensure fps doesn't get too high
                avgFPS = 0;
            }
            // Update Texts
            fpsText.str("");
            fpsText << "FPS: " << (int)avgFPS;

            if (!fpsTextTexture.loadFromRenderedText(renderer, fpsText.str().c_str(), systemFont, systemTextColor)) {
                std::cerr << "Unable to render FPS texture!" << std::endl;
            }

            playerInfo.str("");
            playerInfo << "xVel: " << player.xVel << " yVel: " << player.yVel;
            if (!playerInfoTexture.loadFromRenderedText(renderer, playerInfo.str().c_str(), systemFont, systemTextColor)) {
                std::cerr << "Unable to render Player Info texture" <<std::endl;
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
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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
    systemFont = TTF_OpenFont("./fonts/rpg.otf", 12); // load systemfont
    if (systemFont == nullptr) {
        std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
        success = false;
    }
    // initialize player
    int playerAnimArr[2] {4,3};
    player.init(renderer, "./textures/sprites/ss_player.png", playerAnimArr,2, 32, 32); // initialize player
    player.addCamera(&camera);
    // add GameObject elements to handler
    oHandler.add(&player);
    SDL_Rect rock;
    rock.x = 64; rock.y = 64; rock.w = 32; rock.h = 48;
    oHandler.createBasicAndAdd(rock, 0, 16, renderer, "./textures/sprites/rock.png", 32, 48, &camera);
    rock.x = 96; rock.y = 64; rock.w = 32; rock.h = 48;
    oHandler.createBasicAndAdd(rock, 0, 16, renderer, "./textures/sprites/rock.png", 32, 48, &camera);
    rock.x = 32*24; rock.y = 32*24; rock.w = 32; rock.h = 48;
    oHandler.createBasicAndAdd(rock, 0, 16, renderer, "./textures/sprites/rock.png", 32, 48, &camera);
    rock.x = 32*16; rock.y = 32; rock.w = 32; rock.h = 48;
    oHandler.createBasicAndAdd(rock, 0, 16, renderer, "./textures/sprites/rock.png", 32, 48, &camera);

    // add GUI elements to handler
    gHandler.createAndAdd((SCREEN_WIDTH/2)-48,SCREEN_HEIGHT-64,96,32,renderer,"./textures/gui/basic_button.png");
    gHandler.createAndAdd((SCREEN_WIDTH/2)-144,SCREEN_HEIGHT-64,96,32,renderer,"./textures/gui/basic_button.png");

    return success;
}

void close() {
    tileRenderer.free();
    gHandler.free();
    // destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;

    //quit subsystems
    IMG_Quit();
    SDL_Quit();
}