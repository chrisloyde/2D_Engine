#include <iostream>
#include "headers/Tile.h"
#include "../gui/headers/GUI.h"

Tile::Tile() {
    xPos = 0;
    yPos = 0;
    width = 32;
    height = 32;
    isSolid = false;
    tType = tile_default;
    displayOverlay = false;
}
Tile::Tile(int x, int y, int w, int h, bool isSolidIn, tileTypes type) {
    xPos = x; height = h;
    yPos = y; width = w;
    cBox.x = xPos; cBox.y = yPos;
    cBox.w = width; cBox.h = height;
    isSolid = isSolidIn;
    tType = type;
    displayOverlay = false;
}
bool Tile::checkCollision(SDL_Rect a, SDL_Rect b) {
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    // calculate sides of the rectangles
    leftA = a.x; rightA = a.x + a.w; topA = a.y; bottomA = a.y + a.h;
    leftB = b.x; rightB = b.x + b.w; topB = b.y; bottomB = b.y + b.h;
    // check for any intersections between A and B
    if (bottomA <= topB) {
        return false;
    }
    if (topA >= bottomB) {
        return false;
    }
    if (rightA <= leftB) {
        return false;
    }
    if (leftA >= rightB) {
        return false;
    }

    return true;
}
float Tile::getDistance(SDL_Rect a, SDL_Rect b, int tileSize) {
    float xDist;
    float yDist;
    // get center points of rectangles for distance calculations
    xDist = abs((a.x+a.w/2)-(b.x+b.w/2));
    yDist = abs((a.y+a.h/2)-(b.y+b.h/2));
    // return whichever distance is larger
    // divide by tile size to determine how many tiles away
    return (xDist < yDist ? yDist : xDist)/tileSize;
}
void Tile::handleEvent(SDL_Event &e, SDL_Rect camera) {
    if(e.type == SDL_MOUSEMOTION) {
        if (Tile::checkCollision(GUI::getMouseBoundsInWorld(camera), cBox)) {
            displayOverlay = true;
        } else {
            displayOverlay = false;
        }
    }
}
void Tile::update() {
}
void Tile::setPos(int x, int y) {
    xPos = x; yPos = y;
    cBox.x = x; cBox.y = y;
}
void Tile::setType(tileTypes type) {
    tType = type;
}
void Tile::setSolid(bool b) {
    isSolid = b;
}
SDL_Rect Tile::getBounds() {
    return cBox;
}

void Tile::setBounds(SDL_Rect rect) {
    cBox = rect;
}

int Tile::getXPos() {return xPos;}
int Tile::getYPos() {return yPos;}
bool Tile::getSolid() {return isSolid;}
bool Tile::isOverlayDisplayed() {return displayOverlay;}
Tile::tileTypes Tile::getType() {
    return tType;
}

Tile::~Tile() {

}