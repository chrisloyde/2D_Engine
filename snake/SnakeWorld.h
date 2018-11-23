#pragma once


#include "../World.h"
#include "EntitySnake.h"

class SnakeWorld: public World {
public:
    SnakeWorld(int xTileNum, int yTileNum, int tileWidth, int tileHeight);
    SnakeWorld();
    static void getNextPosition(int currentPosition[], EntitySnake::directions facing);
private:
};

