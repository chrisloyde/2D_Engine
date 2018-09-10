#include "TileRenderer.h"
TileRenderer::TileRenderer(int numOfSpritesIn, int w, int h) {
    numOfSprites = numOfSpritesIn;
    spriteW = w;
    spriteH = h;
    rawW = 0;
    rawH = 0;
    SDL_spriteSheet = nullptr;
    clipStorage = new SDL_Rect[numOfSpritesIn];

}
TileRenderer::~TileRenderer() {
    free();
}

void TileRenderer::free() {
    if (SDL_spriteSheet != nullptr) {
        SDL_DestroyTexture(SDL_spriteSheet);
        SDL_spriteSheet = nullptr;
        rawH = 0;
        rawW = 0;
    }
}

bool TileRenderer::init(SDL_Renderer *renderer, std::string path) {
    free();

    spriteSheet.loadFromFile(renderer, path);
    generateClips();

}

void TileRenderer::generateClips() {
    for (int i = 0; i < numOfSprites; i++) {
        clipStorage[i].x = (i*spriteW);
        clipStorage[i].y = 0;
        clipStorage[i].w = spriteW;
        clipStorage[i].h = spriteH;
    }
}

void TileRenderer::render(SDL_Renderer *renderer, int x, int y, tileTypes type) {
    switch(type) {
        case tile_grass:
            spriteSheet.render(renderer, x, y, &clipStorage[1]);
            break;
        case tile_water:
            spriteSheet.render(renderer, x, y, &clipStorage[2]);
            break;
        default:
            spriteSheet.render(renderer, x, y, &clipStorage[0]);
            break;
    }
}