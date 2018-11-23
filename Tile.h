#pragma once

#include <iostream>
#include <SDL_rect.h>
#include <SDL_events.h>
#include <SDL_render.h>
#include "GUI.h"
class Tile {
public:
    enum tileTypes {
        tile_default, tile_dirt, tile_grass, tile_water
    };
    bool isSolid;
    Tile();
    Tile(int x, int y, int h, int w, bool isSolid, tileTypes type);
    ~Tile();
    static bool checkCollision(SDL_Rect a, SDL_Rect b);
    static float getDistance(SDL_Rect a, SDL_Rect b, int tileSize); // gets the number of tiles between 2 rectangles
    void setPos(int x, int y);
    void setBounds(SDL_Rect rect);
    void setType(tileTypes type);
    void setSolid(bool b);
    int getXPos();
    int getYPos();
    SDL_Rect getBounds();
    bool getSolid();
    tileTypes getType();
    void handleEvent(SDL_Event &e, SDL_Rect camera);
    void update();
    bool isOverlayDisplayed();
private:
    int xPos, yPos, height, width;
    bool displayOverlay;
    tileTypes tType;
    SDL_Rect cBox; // collision box
};

