
#pragma once

#include <vector>
#include "../GameObject.h"
#include "../Engine.h"
#include "../GameObjectHandler.h"
#include "../GameObjectPool.h"
#include "../Timer.h"
#include "Point.h"
#include "EntityTail.h"

#define SPEED 100.f

class EntitySnake: public GameObject {
public:
    int score = 0;
    enum directions {north = 0,south = 1,east = 2,west = 3};
    //const int SPEED = 1;
    EntitySnake(int x, int y, int size, int worldWidth, int worldHeight);

    void update(float timeStep) override;
    void render(SDL_Renderer *r) override;
    void handleEvent(SDL_Event& e) override;
    void init(SDL_Renderer *r, std::string path, int *numOfSpritesIn, int animNum, int sWidth, int sHeight, bool isHead);
    void handleCollision(GameObject *other) override ;
    static void getNextPosition(int currentPosition[], directions facing, int worldWidth, int worldHeight);
	~EntitySnake();
private:
    directions facing;
    EntityTail *tail = nullptr;
    float yVel = 0;
    float xVel = 0;
    int worldW, worldH;
	bool canMove = true;
	bool shouldUpdate = false;
	int currentTime = 0;
	int previousTime = -1;
	Timer updateTimer;
};

