
#ifndef INC_2DENGINE_WORLD_H
#define INC_2DENGINE_WORLD_H


#include "../block/headers/Tile.h"
#include "../../textures/sprites/renderers/headers/TileRenderer.h"

class World {
public:
    World(int xTileNum, int yTileNum, int tileWidth, int tileHeight);
    void render(TileRenderer *tr, SDL_Renderer *renderer, SDL_Rect camera);
    void handleEvent(SDL_Event* e, SDL_Rect camera); // send event to all tiles
    void update();
    //~World();
private:
    Tile **world;
    int wTileNum, hTileNum, tileW, tileH;

    void initWorld();
};


#endif //INC_2DENGINE_WORLD_H
