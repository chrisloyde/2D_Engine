
#include "headers/World.h"

World::World(int xTileNum, int yTileNum, int tileWidth, int tileHeight) {
    // 1 is added to each of these to add another row and column of tiles
    // I do this because the level size may not be evenly divisible by
    // the tile width or height, so adding an extra row and column will ensure
    // tiles cover the entire level.
    wTileNum = xTileNum+1;
    hTileNum = yTileNum+1;
    tileW = tileWidth;
    tileH = tileHeight;
    // intialize 2D array of tiles to represent world
    world = new Tile*[hTileNum];
    for (int i = 0; i < hTileNum; i++) {
        world[i] = new Tile[wTileNum]();
    }

    initWorld();
}

void World::initWorld() {
    for (int i = 0; i < hTileNum; i++) {
        for (int j = 0; j < wTileNum; j++) {
            world[i][j].setPos(j*tileW, i*tileH);
            world[i][j].setType(Tile::tile_grass);
            world[i][j].isSolid = false;

            SDL_Rect *rect = new SDL_Rect;
            rect->x = j*tileW; rect->y = i*tileH;
            rect->w = tileW; rect->h = tileH;

            world[i][j].setBounds(*rect);
        }
    }
}

void World::handleEvent(SDL_Event* e, SDL_Rect camera) {
    for (int i = 0; i < hTileNum; i++) {
        for (int j = 0; j < wTileNum; j++) {
            world[i][j].handleEvent(e, camera);
        }
    }
}

void World::update() {
    for (int i = 0; i < hTileNum; i++) {
        for (int j = 0; j < wTileNum; j++) {
            world[i][j].update();
        }
    }
}

void World::render(TileRenderer *tr, SDL_Renderer *renderer, SDL_Rect camera) {
    for (int i = 0; i < hTileNum; i++) {
        for (int j = 0; j < wTileNum; j++) {
            tr->renderTile(renderer, camera, world[i][j]);
        }
    }
}