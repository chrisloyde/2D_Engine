#pragma once

#include <iostream>
#include <SDL_events.h>
//#include "Tile.h"
#include "Texture.h"

class GUI {

public:
    GUI();
    virtual void setBounds(SDL_Rect r);
    virtual void setBounds(int x, int y, int w, int h);
    virtual void loadMedia(SDL_Renderer *renderer, std::string path);
    virtual void update();
    virtual void handleEvent(SDL_Event &e);
    virtual void render(SDL_Renderer *renderer); // don't use camera in gui
    virtual void onClick(SDL_Event &e);
    virtual void onHover();
    virtual void displayInfo();
    virtual void free();

    static SDL_Rect getMouseBoundsInWorld(SDL_Rect camera); // static method to retrieve mouse position in relation to the camera.
    static SDL_Rect getGUIMouseBounds(); // static method to retrieve mouse position on screen.

    SDL_Rect rect;
    int xPos, yPos, height, width;
    bool mouseEnter = false;
    Texture *gTexture;

private:
};
