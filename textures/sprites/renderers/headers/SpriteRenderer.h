#ifndef INC_2DENGINE_SPRITERENDERER_H
#define INC_2DENGINE_SPRITERENDERER_H


#include <SDL2/SDL_render.h>
#include "../../../../objects/headers/GameObject.h"

class SpriteRenderer {
public:
    SpriteRenderer(int numOfSprites, int spriteW, int spriteH);
    ~SpriteRenderer();
    void free();
    bool init(SDL_Renderer *renderer, std::string path);
    void generateClips();
    void renderSprite(SDL_Renderer *r, SDL_Rect camera, GameObject obj);
private:
    Texture *spritesheet;
    SDL_Rect *clipStorage;
    int numOfSprites, spriteW, spriteH, currentFrame{0};
};


#endif //INC_2DENGINE_SPRITERENDERER_H
