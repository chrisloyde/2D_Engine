#include "GameRunner.h"

int GameRunner::run() {
	char windowName[24] = "Ruin2D is working";
	attachEngine(*Engine::getInstance(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, windowName));
	attachObjectPool(*GameObjectPool::getInstance());
	init();
	gameLoop();
	kill();
	return 0;
}

bool GameRunner::attachEngine(Engine &inEngine) {
	engine = &inEngine;
	return engine != nullptr;
}

bool GameRunner::attachObjectPool(GameObjectPool &inPool) {
	pool = &inPool;
	return pool != nullptr;
}


int GameRunner::gameLoop() {
	if (engine == nullptr || pool == nullptr) {
		std::cerr << "Unable to start game loop, Engine or GameObjectPool not initalized" << std::endl;
		return -1;
	}

	bool quit = false;
	SDL_Event e;
	Timer stepTimer;

	stepTimer.start();

	float timeStep = 0;
	float timePassed = 0;
	int tickCounter = 0;

	while (!quit) {
		/*
		**********
		EVENT CYCLE
		**********
		*/

		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			else {
				addEvents(e);											// Send Event singals to objects outside of GameObject pool.
				pool->handleEvents(e);									// Signal pool to send events to all GameObjects.
			}
		}

		/*
		**********
		UPDATE CYCLE
		**********
		*/

		addUpdates(timeStep);											// Update objects outside of GameObject Pool.

		pool->update(timeStep);											// Call Dynamic updates on GameObjects within Pool.


		if (timePassed >= (timeStep / 1000.f) && tickCounter < 10) {
			pool->tick();
			timePassed -= timeStep;
			tickCounter++;
		}
		tickCounter = 0;

		pool->removeFlagged();											// Signal pool to remove all flagged GameObjects from the pool.
		/*
		**********
		RENDER CYCLE
		**********
		*/
		SDL_SetRenderDrawColor(engine->getRenderer(), 0, 0, 0, 0);		// Set background draw color (black)
		SDL_RenderClear(engine->getRenderer());							// Clear window (also assigns background draw color to renderer)
			/* Call Renderers */
		pool->render(engine->getRenderer());							// Singal pool to render all GameObjects.
		addRenders(engine->getRenderer());								// Render additional Render tasks.

		SDL_RenderPresent(engine->getRenderer());						// Update screen.

		/* Update timers */
		timeStep = stepTimer.getTicks() / 1000.f;
		stepTimer.start();
		timePassed += timeStep;
	}
	return 0;
}

void GameRunner::kill() {
	addDeallocations();
}

GameRunner::~GameRunner() {
	delete pool;
	delete engine;
}