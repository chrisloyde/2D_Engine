#include "EntityPlayer.h"
EntityPlayer::EntityPlayer(int worldX, int worldY) {
    worldXPos = worldX;
    worldYPos = worldY;
    facing = south;
}
EntityPlayer::~EntityPlayer() {
    texture.free();
}
void EntityPlayer::init(SDL_Renderer *renderer, std::string path) {
    //load media
    texture.loadFromFile(renderer, path);
}
void EntityPlayer::render(SDL_Renderer *renderer, SDL_Rect camera) {
    texture.render(renderer,worldXPos-camera.x, worldYPos-camera.y);
}
void EntityPlayer::update() {
}
void EntityPlayer::handleEvent(SDL_Event &e) {
    // key presses
    switch (e.key.keysym.sym) {
        case SDLK_UP:
        case SDLK_w:
            move(north);
            break;
        case SDLK_DOWN:
        case SDLK_s:
            move(south);
            break;
        case SDLK_LEFT:
        case SDLK_a:
            move(west);
            break;
        case SDLK_RIGHT:
        case SDLK_d:
            move(east);
            break;
        default:
            // essentially any key that isn't explicitly listed
            break;

    }
}

void EntityPlayer::move(EntityPlayer::directions direction) {
    facing = direction;
    switch(facing) {
        case north:
            worldYPos -= 32;
            break;
        case south:
            worldYPos += 32;
            break;
        case east:
            worldXPos += 32;
            break;
        case west:
            worldXPos -= 32;
            break;
    }
}

int EntityPlayer::getXPos() {return worldXPos;}
int EntityPlayer::getYPos() {return worldYPos;}