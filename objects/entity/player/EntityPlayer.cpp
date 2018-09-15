#include "../headers/EntityPlayer.h"
#include "../../headers/World.h"

EntityPlayer::EntityPlayer(int worldX, int worldY, int width, int height) {
    xPos = worldX;
    yPos = worldY;
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
    step = timeStep;

    move(timeStep);

    // change animation state
    if (xVel != 0 || yVel !=0) {
        anim = 1;
    } else {
        anim = 0;
    }

    // update camera to follow player and keep camera in bounds.
    if (cam->x < World::WORLD_WIDTH - cam->w) {
        // handle right
        if (xPos >= cam->x + (cam->w) - World::SCREEN_WIDTH / 2.5) {
            if (xVel > 0) {
                cam->x += xVel * timeStep;
            }
        }
    }
    if (cam->x > 0) {
        // handle left
        if ((xPos + width) - World::SCREEN_WIDTH / 2.5 <= cam->x) {
            if (xVel < 0) {
                cam->x += xVel * timeStep;
            }
        }
    }
    if (cam->y < World::WORLD_HEIGHT - cam->h) {
        // handle down
        if (yPos >= cam->y + (cam->h) - World::SCREEN_HEIGHT / 2.5) {
            if (yVel > 0) {
                cam->y += yVel * timeStep;
            }
        }
    }
    if (cam->y > 0) {
        // handle up
        if ((yPos + height) - World::SCREEN_HEIGHT / 2.5 <= cam->y) {
            if (yVel < 0) {
                cam->y += yVel * timeStep;
            }
        }
    }
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

void EntityPlayer::handleCollision(GameObject *other) {
    if (other->isSolid) {
        while(readDistance(other) <= 1) {
            unMove(step);
        }
    }
}

void EntityPlayer::move(float timeStep) {
    // moving right
    xPos += xVel * timeStep;
    yPos += yVel * timeStep;
    setPos((int)xPos, (int)yPos);
    setBounds((int)xPos, (int)yPos, width, height, (int)xOffset,(int)yOffset);
}
void EntityPlayer::unMove(float timeStep) {
    xPos -= (xVel) * timeStep;
    yPos -= (yVel) * timeStep;
    // reset position and bounds since update won't be called.
    setPos((int)xPos, (int)yPos);
    setBounds((int)xPos, (int)yPos, width, height, (int)xOffset,(int)yOffset);
}

int EntityPlayer::getXPos() {return (int)xPos;}
int EntityPlayer::getYPos() {return (int)yPos;}