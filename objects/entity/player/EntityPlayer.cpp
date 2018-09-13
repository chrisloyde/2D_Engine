#include "../headers/EntityPlayer.h"
EntityPlayer::EntityPlayer(int worldX, int worldY, int width, int height) {
    worldXPos = worldX;
    worldYPos = worldY;
    setBounds(worldX, worldY, width, height);
    facing = south;
    gTexture = new Texture();
    id = "Player";
}
void EntityPlayer::render(SDL_Renderer *renderer, SDL_Rect camera) {
    GameObject::render(renderer,camera);
}
void EntityPlayer::update(float timeStep) {
    GameObject::update(timeStep);
    move(timeStep);
    if (xVel != 0 || yVel !=0) {
        anim = 1;
    } else {
        anim = 0;
    }
}
void EntityPlayer::handleEvent(SDL_Event &e, SDL_Rect camera) {
    GameObject::handleEvent(e, camera); // run parent event handling
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
            default: break;
        }
    } else
    if(e.type == SDL_KEYUP && e.key.repeat == 0) {
        switch(e.key.keysym.sym) {
            case SDLK_w: case SDLK_UP: yVel += SPEED; break;
            case SDLK_s: case SDLK_DOWN: yVel -= SPEED; break;
            case SDLK_a: case SDLK_LEFT: xVel += SPEED; break;
            case SDLK_d: case SDLK_RIGHT: xVel -= SPEED; break;
            default: break;
        }
    }
}

void EntityPlayer::move(float timeStep) {
    worldXPos += xVel * timeStep;
    worldYPos += yVel * timeStep;
    setPos((int)worldXPos, (int)worldYPos);
}

int EntityPlayer::getXPos() {return (int)worldXPos;}
int EntityPlayer::getYPos() {return (int)worldYPos;}