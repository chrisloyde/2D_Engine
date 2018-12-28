#pragma once

#include "Engine.h"
#include "GameObjectPool.h"
#include "Timer.h"

#define DEFAULT_SCREEN_WIDTH 640
#define DEFAULT_SCREEN_HEIGHT 480

class GameRunner {
public:
	GameRunner() = default;
	virtual int run();											// Public function to handle setting up the game, running the game loop, reporting error codes, etc.
																// Ideally this function would contain engine and pool creation and calls to init() and gameloop().
																// This function should also handle memory freeing.

	virtual bool attachEngine(Engine &engine);					// Public function to attach an externally created Pool to the game.
	virtual bool attachObjectPool(GameObjectPool &pool);		// Public function to attach an externally created GameObjectPool to the game.
	virtual void kill();										// Public function to kill the game. Ideally this would be used to deallocate/cleanup memory.
	virtual ~GameRunner();
protected:
	Engine *engine;
	GameObjectPool *pool;

	virtual bool init() = 0;									// Protected function for intializing the game. Loading GameObjects/elements, etc.
	virtual int gameLoop();										// Protected functon that should contain the game loop.

	/* Protected functions to handle additional event, update, renders, and memory deallocation calls for objects not in the GameLoop */
	virtual void addEvents(SDL_Event &e) = 0;					
	virtual void addUpdates(float timeStep) = 0;
	virtual void addRenders(SDL_Renderer *renderer) = 0;		
	virtual void addDeallocations() = 0;
private:

};

