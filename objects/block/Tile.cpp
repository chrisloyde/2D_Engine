#include <iostream>
#include "headers/Tile.h"

Tile::Tile() {
    xPos = 0;
    yPos = 0;
    width = 32;
    height = 32;
    isSolid = false;
    tType = tile_default;
}
Tile::Tile(int x, int y, int w, int h, bool isSolidIn, tileTypes type) {
    xPos = x; height = h;
    yPos = y; width = w;
    cBox.x = xPos; cBox.y = yPos;
    cBox.w = width; cBox.h = height;
    isSolid = isSolidIn;
    tType = type;
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
void Tile::handleEvent(SDL_Event* e, SDL_Rect camera) {
    int mouseX, mouseY, mouseW, mouseH;
    SDL_GetMouseState(&mouseX, &mouseY);
    // add mouse position to camera position so mouse position works with camera scrolling
    mouseX = mouseX+camera.x;
    mouseY = mouseY+camera.y;
    mouseW = 6;
    mouseH = 6;
    // create a bounding box for the mouse
    SDL_Rect rect;
    rect.x = mouseX; rect.y = mouseY;
    rect.w = mouseW; rect.h = mouseH;
    if (Tile::checkCollision(rect,cBox)) {
        setType(tile_grass);
    }
}
void Tile::setPos(int x, int y) {
    xPos = x; yPos = y;
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

Tile::tileTypes Tile::getType() {
    return tType;
}

Tile::~Tile() {

}