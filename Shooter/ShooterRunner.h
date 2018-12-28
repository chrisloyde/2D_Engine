#pragma once

#include "../GameRunner.h"
#include "../TextureManager.h"
#include "../Timer.h"
#include "EntityGunman.h"
#include "ShooterTextures.h"
#include <ctime>
#include <iostream>

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 800
#define SCALE 1.0f
#define SPRITE_SIZE 32

class ShooterRunner :
	public GameRunner {
public:
	ShooterRunner();
	int run() override;
	bool attachEngine(Engine &engine) override;
	bool attachObjectPool(GameObjectPool &pool) override;
	void kill() override;
	~ShooterRunner() override;
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
	EntityGunman *player;

	int screenWidth;
	int screenHeight;
	float scaleSizeX;
	float scaleSizeY;

	SDL_Rect camera;
};