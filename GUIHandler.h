#pragma once


#include <SDL_render.h>
#include <vector>
#include "GUI.h"

class GUIHandler {
public:
    GUIHandler();
    ~GUIHandler();
    void update();
    void render(SDL_Renderer *r);
    void handleEvents(SDL_Event &e);
    void add(GUI *g);
    void createAndAdd(int xPos, int yPos, int width, int height, SDL_Renderer *r, std::string path);
    void free();
private:
    std::vector<GUI *> elements;
};

