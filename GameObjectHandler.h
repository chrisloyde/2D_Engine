#pragma once

#include <vector>
#include <algorithm>
#include "GameObject.h"
#include "EntityPlayer.h"

class GameObjectHandler {
public:
    ~GameObjectHandler();
    static GameObjectHandler* getInstance();			// Create or retrive existing instance of object handler.
    void update(float timeStep);						// Sends update signals to all objects contained in handler.
    void render(SDL_Renderer *r, SDL_Rect camera);		// Sends render signals to all objects contained in handler.
    void handleEvents(SDL_Event &e);					// Sends event signals to all objects contained in handler.
    
	// only use for single sprites, auto sets to solid
    void createBasicAndAdd(SDL_Rect bounds, int xOff, int yOff, SDL_Renderer *, std::string , int spriteWidth, int SpriteHeight, SDL_Rect *cam);

    void removeFlagged();								// remove flagged objects from handler.
    void add(GameObject *o);							// add object to handler.
    void free();
private:
    static GameObjectHandler* instance;
    std::vector<GameObject *> elements;
	int* handleCollisions(); // returns an array (length 2) which provides the two objects colliding in the elements list.
    // struct for ordering vector to move elements depending on their y position.
    // We do this to make objects render above and below eachother.
    GameObjectHandler();
    struct order
    {
        bool operator() (GameObject *lhs, GameObject *rhs) {
            if (lhs != NULL && rhs != NULL) {
                return (lhs->bounds.y < rhs->bounds.y);
            }
            return false;
        }
    } order_yPos;
};

