#include "../headers/EntityPlayer.h"
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
    texture.render(renderer,(int)worldXPos-camera.x, (int)worldYPos-camera.y);
}
void EntityPlayer::update(float timeStep) {
    move(timeStep);
}
void EntityPlayer::handleEvent(SDL_Event &e) {
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        switch(e.key.keysym.sym) {
            case SDLK_w:
            case SDLK_UP:
                yVel -= SPEED; facing = north; break;
            case SDLK_s:
            case SDLK_DOWN:
                yVel += SPEED; facing = south; break;
            case SDLK_a:
            case SDLK_LEFT:
                xVel -= SPEED; facing = east; break;
            case SDLK_d:
            case SDLK_RIGHT:
                xVel += SPEED; facing = west; break;
        }
    } else
    if(e.type == SDL_KEYUP && e.key.repeat == 0) {
        switch(e.key.keysym.sym) {
            case SDLK_w: case SDLK_UP: yVel += SPEED; break;
            case SDLK_s: case SDLK_DOWN: yVel -= SPEED; break;
            case SDLK_a: case SDLK_LEFT: xVel += SPEED; break;
            case SDLK_d: case SDLK_RIGHT: xVel -= SPEED; break;
        }
    }
}

void EntityPlayer::move(float timeStep) {
    worldXPos += xVel * timeStep;
    worldYPos += yVel * timeStep;
}

int EntityPlayer::getXPos() {return (int)worldXPos;}
int EntityPlayer::getYPos() {return (int)worldYPos;}