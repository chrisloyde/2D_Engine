#ifndef INC_2DENGINE_UPDATEANDRENDER_H
#define INC_2DENGINE_UPDATEANDRENDER_H


#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>

class UpdateAndRender {
public:
    void init();
    void render(SDL_Renderer *renderer);
    void update();
    void handleEvent(SDL_Event& e);
};


#endif //INC_2DENGINE_UPDATEANDRENDER_H
