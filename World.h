
#pragma once


#include "Tile.h"
#include "TileRenderer.h"

class World {
public:
    const static int WORLD_WIDTH = 1920;
    const static int WORLD_HEIGHT = 1920;

    const static int SCREEN_WIDTH = 640;
    const static int SCREEN_HEIGHT = 480;

    explicit World(int xTileNum, int yTileNum, int tileWidth, int tileHeight);
    void render(TileRenderer *tr, SDL_Renderer *renderer, SDL_Rect camera);
    void handleEvent(SDL_Event &e, SDL_Rect camera); // send event to all tiles
    void update();
    //~World();
protected:
    World()= default;

    Tile **world;
    int wTileNum, hTileNum, tileW, tileH;

    void initWorld();
private:
};

