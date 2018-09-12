//
// Created by Chris on 9/11/2018.
//

#ifndef INC_2DENGINE_GAMEOBJECT_H
#define INC_2DENGINE_GAMEOBJECT_H


#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>
#include <string>
#include "../../../textures/Texture.h"

class GameObject {
public:
    GameObject(); // construct default game object
    virtual void init(SDL_Renderer *r, std::string path); // initializes and loads media for game object
    virtual void setBounds(int x, int y, int width, int height); // intialize position and bounding box of game object
    virtual void update(float timeStep); // updates game object per frame (uses frame independance with timestep)
    virtual void handleEvent(SDL_Event &e); // handle events
    virtual void render(SDL_Renderer *renderer, SDL_Rect camera); // render game object per frame
    ~GameObject();
    virtual void free(); // deconstruct game object

    int xPos, yPos, width, height;
    SDL_Rect bounds;
    Texture *gTexture;
private:
};

#endif //INC_2DENGINE_GAMEOBJECT_H
