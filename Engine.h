#ifndef INC_2DENGINE_ENGINE_H
#define INC_2DENGINE_ENGINE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL_ttf.h>

class Engine {

public:

    static Engine* getInstance(int screenWidth, int screenHeight, char *namePtr);
    static Engine* getInstance();
    bool init(int screenWidth, int screenHeight, const char *namePtr);
    SDL_Window* getWindow() { return gWindow; }
    SDL_Renderer* getRenderer() { return gRenderer; }
    void kill();
private:
    int sW, sH;
    const char *nPtr;
    SDL_Window *gWindow;
    SDL_Renderer *gRenderer;

    static Engine* instance;

    Engine() = default;
};


#endif //INC_2DENGINE_ENGINE_H
