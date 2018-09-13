#include "../headers/EntityPlayer.h"
EntityPlayer::EntityPlayer(int worldX, int worldY, int width, int height) {
    worldXPos = worldX;
    worldYPos = worldY;
    setBounds(worldX, worldY, width, height, 0, 0);
    facing = south;
    gTexture = new Texture();
    id = "Player";
}
void EntityPlayer::render(SDL_Renderer *renderer) {
    GameObject::render(renderer);
}
void EntityPlayer::update(float timeStep) {
    GameObject::update(timeStep);

    bounds.x += xVel * timeStep;
    bounds.y += yVel * timeStep;

    // change animation state
    if (xVel != 0 || yVel !=0) {
        anim = 1;
    } else {
        anim = 0;
    }

    // update world positions based off bounds.
    worldXPos = bounds.x;
    worldYPos = bounds.y;

    // update camera to follow player.
    cam->x = (getXPos() + 32/2)-640/2;
    cam->y = (getYPos() +32/2)-480/2;
}
void EntityPlayer::handleEvent(SDL_Event &e, SDL_Rect camera) {
    GameObject::handleEvent(e, camera); // run parent event handling
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        switch(e.key.keysym.sym) {
            // strictly horizontal and vertical movement
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
void EntityPlayer::unMove(float timeStep) {
    worldXPos -= (xVel)*timeStep;
    worldYPos -= (yVel)*timeStep;
    // reset position and bounds since update won't be called.
    setPos((int)worldXPos, (int)worldYPos);
    setBounds((int)worldXPos, (int)worldYPos, width, height, 0,0);
}

int EntityPlayer::getXPos() {return (int)worldXPos;}
int EntityPlayer::getYPos() {return (int)worldYPos;}