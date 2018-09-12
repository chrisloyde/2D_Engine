#ifndef INC_2DENGINE_GUI_H
#define INC_2DENGINE_GUI_H

#include <iostream>
#include <SDL2/SDL_events.h>
#include "../../block/headers/Tile.h"
#include "../../../textures/Texture.h"

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

    SDL_Rect rect;
    SDL_Rect mouseBounds;
    int xPos, yPos, height, width;
    bool mouseEnter = false;
    Texture *gTexture;

private:
};

#endif //INC_2DENGINE_GUI_H
