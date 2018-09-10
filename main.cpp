#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdio>
#include <string>
#include <sstream>
#include "textures/Texture.h"
#include "textures/sprites/renderers/TileRenderer.h"
#include "Objects/Timer.h"
#include <SDL_ttf.h>

// define program variables
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Window *window = nullptr; //The window being rendered to
SDL_Surface *screenSurface = nullptr; // The surface contained by the window
SDL_Renderer *renderer = nullptr; // window renderer
//SDL_Texture *texture = nullptr; // texture to render.
SDL_Color systemTextColor = {0,0,0,255};
TTF_Font *systemFont = nullptr;

TileRenderer *tileRenderer;
Texture fpsTextTexture;

// Key press codes
enum KeyPress {
    KEY_PRESS_DEFAULT,
    KEY_PRESS_UP,
    KEY_PRESS_DOWN,
    KEY_PRESS_LEFT,
    KEY_PRESS_RIGHT,
    KEY_PRESS_TOTAL
};

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
                    // key presses
                    switch (e.key.keysym.sym) {
                        case SDLK_UP:
                        case SDLK_w:
                            std::cout << "UP pressed" << std::endl;
                            break;
                        case SDLK_DOWN:
                        case SDLK_s:
                            std::cout << "DOWN pressed" << std::endl;
                            break;
                        case SDLK_LEFT:
                        case SDLK_a:
                            std::cout << "LEFT pressed" << std::endl;
                            break;
                        case SDLK_RIGHT:
                        case SDLK_d:
                            std::cout << "RIGHT pressed" << std::endl;
                            break;
                        default:
                            // essentially any key that isn't explicitly listed
                            std::cout << "DEFAULT" << std::endl;
                            break;

                    }
                }
            }

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


            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(renderer); // clear screen

            //Call Renders
            tileRenderer->render(renderer, 0, 0, TileRenderer::tile_default);
            tileRenderer->render(renderer, 32, 0, TileRenderer::tile_grass);
            tileRenderer->render(renderer, 64, 0, TileRenderer::tile_water);

            fpsTextTexture.render(renderer, 0, 0);

            //SDL_RenderCopy(renderer, spriteSheetTexture, nullptr, nullptr); // render texture on screen
            SDL_RenderPresent(renderer); // update screen

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
    tileRenderer = new TileRenderer(3, 32, 32);
    tileRenderer->init(renderer,"./textures/sprites/tiles.png");
    systemFont = TTF_OpenFont("./fonts/rpg.otf", 12);
    if (systemFont == NULL) {
        std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
        success = false;
    }
    return success;
}

void close() {
    tileRenderer->free();

    // destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;

    //quit subsystems
    IMG_Quit();
    SDL_Quit();
}