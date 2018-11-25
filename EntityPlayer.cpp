#include "EntityPlayer.h"

EntityPlayer::EntityPlayer(int worldX, int worldY, int width, int height) {
    xPos		= worldX;
    yPos		= worldY;
    facing		= south;
    gTexture	= new Texture();
    id			= "Player";

	setBounds(worldX, worldY, width, height, 0, 0);
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

	// Update camera to follow player and keep camera in bounds.
	// Camera doesn't keep player exactly in the center, but allows a dead zone before panning.
	// Camera is also dependent on player x and y velocity, which should be used for moving the player.
    if (cam->x < World::WORLD_WIDTH - cam->w) {
        // handle right
        if ((bounds.x+bounds.w) >= cam->x + (cam->w) - World::SCREEN_WIDTH / 2.5) {
            if (xVel > 0) {
                cam->x += xVel * timeStep;
            }
        }
    }
    if (cam->x > 0) {
        // handle left
        if ((bounds.x) - World::SCREEN_WIDTH / 2.5 <= cam->x) {
            if (xVel < 0) {
                cam->x += xVel * timeStep;
            }
        }
    }
    if (cam->y < World::WORLD_HEIGHT - cam->h) {
        // handle down
        if ((bounds.y+bounds.h) >= cam->y + (cam->h) - World::SCREEN_HEIGHT / 2.5) {
            if (yVel > 0) {
                cam->y += yVel * timeStep;
            }
        }
    }
    if (cam->y > 0) {
        // handle up
        if ((bounds.y) - World::SCREEN_HEIGHT / 2.5 <= cam->y) {
            if (yVel < 0) {
                cam->y += yVel * timeStep;
            }
        }
    }
}
void EntityPlayer::handleEvent(SDL_Event &e) {
    GameObject::handleEvent(e); // run parent event handling.

	// Key press, no repeating.
	// Key press repetition is better handled by checking when the key is released.
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        switch(e.key.keysym.sym) {
            // strictly horizontal and vertical movement
            case SDLK_w:
            case SDLK_UP:
                yVel -= speed;	// subtract speed from y-axis velocity to create negative velocity for northern movement.
				facing = north; // assign facing.
				break;
            case SDLK_s:
            case SDLK_DOWN:
                yVel += speed;	// add speed to y-axis velocity to create positive velocity for southern movement.
				facing = south; // assign facing.
				break;
            case SDLK_a:
            case SDLK_LEFT:
                xVel -= speed;	// subtract speed from x-axis velocity to create negative velocity for eastern movement
				facing = east;	// assign facing.
				break;
            case SDLK_d:
            case SDLK_RIGHT:
                xVel += speed;	// add speed to x-axis velocity to create positive velocity for western movement.
				facing = west;	// assign facing.
				break;
            default: 
				break;
        }

    } else
	// Key release, no repeating.
    if(e.type == SDL_KEYUP && e.key.repeat == 0) {
        switch(e.key.keysym.sym) {
			// Does the opposite of what each key press does, essentially bringing the respective velocities back to 0 to halt movement.
            case SDLK_w: case SDLK_UP: 
				yVel += speed; 
				break;
            case SDLK_s: case SDLK_DOWN: 
				yVel -= speed; 
				break;
            case SDLK_a: case SDLK_LEFT: 
				xVel += speed; 
				break;
            case SDLK_d: case SDLK_RIGHT: 
				xVel -= speed; 
				break;
            default: 
				break;
        }
    }
}

void EntityPlayer::handleCollision(GameObject *other) {
	// Only solid objects alter player movment.
	// specific objects can be found using id (e.g other->id).
    if (other->isSolid) {
		// unmove entity repeatedly while the distance between both objects is <= 1
        while(GameObject::readDistance(other) <= 1) {
            unMove(step);
        }
    }
}

void EntityPlayer::move(float timeStep) {
    xPos += xVel * timeStep;	
    yPos += yVel * timeStep;
	// set position and bounds
    setPos((int)xPos, (int)yPos);
    setBounds((int)xPos, (int)yPos, width, height, (int)xOffset,(int)yOffset);
}
void EntityPlayer::unMove(float timeStep) {
    xPos -= (xVel) * timeStep;
    yPos -= (yVel) * timeStep;
    // set position and bounds.
    setPos((int)xPos, (int)yPos);
    setBounds((int)xPos, (int)yPos, width, height, (int)xOffset,(int)yOffset);
}

int EntityPlayer::getXPos() {return (int)xPos;}
int EntityPlayer::getYPos() {return (int)yPos;}