
#pragma once

#include <string>
#include <array>
#include <SDL_render.h>
#include <SDL_events.h>
#include "Texture.h"
#include "GUI.h"

class GameObject {
public:
    GameObject(); // construct default game object
    virtual void init(SDL_Renderer *r, Texture *texture, int *numOfSpritesArr, int animNum, int sWidth, int sHeight);	// initializes and loads media for game object.
	void addCamera(SDL_Rect *camera);													// add camera to object.
	void setId(std::string str);														// assign ID to object.
    virtual void generateSpriteClips();													// clips object's sprite sheet to create animations.
    virtual void setBounds(int x, int y, int width, int height, int xOff, int yOff);	// intialize position and bounding box of game object.
    virtual void setPos(int x, int y);													// assigns object position to a new one.
    virtual void update(float timeStep);												// dynamic updates game object per frame (uses frame independance with timestep).
	virtual void tick();																// fixed updates on game objects per frames.
	virtual void randomTick();															// updates game object randomly.
	virtual void slowTick();															// updates game object after a set number of frames.
    virtual void handleEvent(SDL_Event &e);												// handle events.
    virtual void handleCollision(GameObject *other);									// handle collisions between objects.
    virtual float readDistance(GameObject *other);										// calculate and read distance between two objects.
    virtual void render(SDL_Renderer *renderer);										// render game object per frame.
    virtual void displayInfo();															// prints object information to console.
    virtual void setSolid(bool s);														// assign the object to solid, or not.
    virtual ~GameObject();
    virtual void free();																// deconstruct game object.

    std::string id = "GameObject";
    float xPos, yPos, xOffset, yOffset;
    int width, height;
    SDL_Rect bounds;
    Texture *gTexture;
    bool isSolid; // whether player can go through or not.

    int spriteW, spriteH, animFrame{0}, numOfAnims{0}, anim{0};
    int *numOfSprites;
    SDL_Rect **spriteStorage;
    SDL_Rect currentFrame;
    SDL_Rect *cam = nullptr;
    bool flagged = false;

	int randomTickChance;
	int numberOfFramesBeforeTick;
	int tickCounter;
private:
};
