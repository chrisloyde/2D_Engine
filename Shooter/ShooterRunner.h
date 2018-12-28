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
protected:
	bool init() override;
	void addEvents(SDL_Event &e) override;
	void addUpdates(float timeStep) override;
	void addRenders(SDL_Renderer *renderer) override;
	void addDeallocations() override;
private:
	EntityGunman *player;

	int screenWidth;
	int screenHeight;
	float scaleSizeX;
	float scaleSizeY;

	SDL_Rect camera;
};