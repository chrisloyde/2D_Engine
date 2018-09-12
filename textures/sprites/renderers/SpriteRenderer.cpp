#include "headers/SpriteRenderer.h"
SpriteRenderer::SpriteRenderer(int numOfSpritesIn, int w, int h) {
    numOfSprites = numOfSpritesIn;
    spriteW = w;
    spriteH = h;
    spritesheet = new Texture();
    clipStorage = new SDL_Rect[numOfSpritesIn];
}
SpriteRenderer::~SpriteRenderer() {
    free();
}
void SpriteRenderer::free() {
    spritesheet->free();
}

bool SpriteRenderer::init(SDL_Renderer *renderer, std::string path) {
    free();
    spritesheet->loadFromFile(renderer, path);
    generateClips();
}

void SpriteRenderer::generateClips() {
    for (int i = 0; i < numOfSprites; i++) {
        clipStorage[i].x = (i*spriteW);
        clipStorage[i].y = 0;
        clipStorage[i].w = spriteW;
        clipStorage[i].h = spriteH;
    }
}