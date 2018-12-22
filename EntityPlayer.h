#pragma once

#include "Texture.h"
#include "GameObject.h"
#include "World.h"

class EntityPlayer: public GameObject {
public:

    int speed = 240;						// player speed which is used to calculate velocity.
    enum directions {north,south,east,west};// 

    EntityPlayer(int worldX, int worldY,int width, int height);
    void render(SDL_Renderer *renderer) override;				// Called every render cycle.
    void update(float timeStep);								// Called every update cycle.
    void handleEvent(SDL_Event& e) override;					// Called when a SDL event occurs.
    void handleCollision(GameObject *other) override;			// Called when player collides with another object.
    void move(float timeStep);									// move the player according to xVel and yVel set during the update cycle.
    void unMove(float timeStep);								// Negate movement of player according to xVel and yVel set during the update cylce.
																// Currently used for collision detection, but isn't precise enough in its current state.

    int getXPos(); // retrieves world position
    int getYPos(); // retrieves world position
private:
	// Velocities are calculated from speed and timestep
	float yVel = 0;
	float xVel = 0;
    directions facing;
    float step;			// holds timestep which is updated every update cycle.

};
