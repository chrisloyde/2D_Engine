#ifndef INC_2DENGINE_GUIHANDLER_H
#define INC_2DENGINE_GUIHANDLER_H


#include <SDL2/SDL_render.h>
#include <vector>
#include "../../gui/headers/GUI.h"

class GUIHandler {
public:
    GUIHandler();
    void update();
    void render(SDL_Renderer *r);
    void handleEvents(SDL_Event &e);
    void add(GUI *g);
    void createAndAdd(int xPos, int yPos, int width, int height, SDL_Renderer *r, std::string path);
    void free();
private:
    std::vector<GUI> elements;
};


#endif //INC_2DENGINE_GUIHANDLER_H
