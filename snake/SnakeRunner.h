#pragma once
#include <iostream>
#include <ctime>
#include <sstream>
#include "../GameRunner.h"
#include "../Timer.h"
#include "EntitySnake.h"
#include "Fruit.h"

#define SPRITE_SIZE 16
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class SnakeRunner : public GameRunner
{
public:
	SnakeRunner();
	int run() override;
	bool attachEngine(Engine &engine) override;
	bool attachObjectPool(GameObjectPool &pool) override;
	void kill() override;
	~SnakeRunner() override;
protected:
	bool init() override;
	int gameLoop() override;
	void addEvents(SDL_Event &e) override;
	void addUpdates(float timeStep) override;
	void addRenders(SDL_Renderer *renderer) override;
	void addDeallocations() override;

private:
	Engine *engine;
	GameObjectPool *pool;
	EntitySnake *player;
	int screenWidth;
	int screenHeight;
	float scaleSizeX;
	float scaleSizeY;

	SDL_Rect camera;
	std::stringstream score;
	Texture scroreTexture;
};

