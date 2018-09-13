
#ifndef INC_2DENGINE_GAMEOBJECT_H
#define INC_2DENGINE_GAMEOBJECT_H


#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>
#include <string>
#include "../../textures/Texture.h"

class GameObject {
public:
    GameObject(); // construct default game object
    virtual void init(SDL_Renderer *r, std::string path,int *numOfSpritesArr, int animNum, int sWidth, int sHeight); // initializes and loads media for game object
    virtual void generateSpriteClips();
    virtual void setBounds(int x, int y, int width, int height); // intialize position and bounding box of game object
    virtual void setPos(int x, int y);
    virtual void update(float timeStep); // updates game object per frame (uses frame independance with timestep)
    virtual void handleEvent(SDL_Event &e, SDL_Rect camera); // handle events
    virtual void render(SDL_Renderer *renderer, SDL_Rect camera); // render game object per frame
    virtual void displayInfo();
    ~GameObject();
    virtual void free(); // deconstruct game object

    std::string id = "GameObject";
    float xPos, yPos;
    int width, height;
    SDL_Rect bounds;
    Texture *gTexture;

    int spriteW, spriteH, animFrame{0}, numOfAnims, anim{0};
    int *numOfSprites;
    SDL_Rect **spriteStorage;
    SDL_Rect currentFrame;
private:
};

#endif //INC_2DENGINE_GAMEOBJECT_H
