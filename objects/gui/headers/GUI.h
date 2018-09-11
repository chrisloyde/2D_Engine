#ifndef INC_2DENGINE_GUI_H
#define INC_2DENGINE_GUI_H

#include <iostream>
#include <SDL2/SDL_events.h>
#include "../../block/headers/Tile.h"
#include "../../../textures/Texture.h"

class GUI {

public:
    GUI();
    void setBounds(SDL_Rect r);
    void setBounds(int x, int y, int w, int h);
    void loadMedia(SDL_Renderer *renderer, std::string path);
    void update();
    void handleEvent(SDL_Event &e);
    void render(SDL_Renderer *renderer); // don't use camera in gui

    void onClick(SDL_Event &e);
    void onHover();
    void displayInfo();
    void free();

private:
    SDL_Rect rect;
    int xPos, yPos, height, width;
    bool mouseEnter = false;
    Texture *gTexture;
};

#endif //INC_2DENGINE_GUI_H
