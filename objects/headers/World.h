
#ifndef INC_2DENGINE_WORLD_H
#define INC_2DENGINE_WORLD_H


#include "../block/headers/Tile.h"
#include "../../textures/sprites/renderers/headers/TileRenderer.h"

class World {
public:
    const static int WORLD_WIDTH = 1920;
    const static int WORLD_HEIGHT = 1920;

    const static int SCREEN_WIDTH = 640;
    const static int SCREEN_HEIGHT = 480;

    World(int xTileNum, int yTileNum, int tileWidth, int tileHeight);
    void render(TileRenderer *tr, SDL_Renderer *renderer, SDL_Rect camera);
    void handleEvent(SDL_Event &e, SDL_Rect camera); // send event to all tiles
    void update();
    //~World();
private:
    Tile **world;
    int wTileNum, hTileNum, tileW, tileH;

    void initWorld();
};


#endif //INC_2DENGINE_WORLD_H
