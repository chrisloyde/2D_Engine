#include "SnakeRunner.h"



SnakeRunner::SnakeRunner() {
	engine = nullptr;
	pool = nullptr;
	screenWidth = 0;
	screenHeight = 0;
	scaleSizeX = 0;
	scaleSizeY = 0;
}

int SnakeRunner::run() {
	srand(time(0));
	char windowName[24] = "2DEngine: Snake";
	engine = Engine::getInstance(SCREEN_WIDTH, SCREEN_HEIGHT, windowName);
	engine->assignRenderScale(1.25F, 1.25F);

	if (engine == nullptr) {
		std::cerr << "Engine was not attached, creating one using defaults" << std::endl;
		engine = Engine::getInstance(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, nullptr);
		engine->assignRenderScale(1.0f, 1.0f);
	}

	if (pool == nullptr) {
		std::cerr << "Game Object Pool was not attached, creating one usign defaults" << std::endl;
		pool = GameObjectPool::getInstance();
	}

	init();
	gameLoop();

	addDeallocations();
	kill();

	return 0;
}

bool SnakeRunner::attachEngine(Engine &inEngine) {
	engine = &inEngine;

	return (pool != nullptr);
}

bool SnakeRunner::attachObjectPool(GameObjectPool &inPool) {
	pool = &inPool;

	return (pool != nullptr);
}

void SnakeRunner::kill() {
	delete pool;
	delete engine;
}

bool SnakeRunner::init() {
	bool success = true;

	int screenWidth = engine->getScreenWidth();																						// Get screen and scale values from engine.
	int screenHeight = engine->getScreenHeight();
	float scaleX = engine->getScaleX();
	float scaleY = engine->getScaleY();

	std::cout << "Loading Game Objects..." << std::endl;
	player = new EntitySnake(( screenWidth / 2) - SPRITE_SIZE, (screenHeight / 16) + SPRITE_SIZE, SPRITE_SIZE, 
		((screenWidth / 16) / scaleX), ((screenHeight / 16) / scaleY));																// Create player according to size and scale of screen.

	camera = { 0, 0, (int)(screenWidth / scaleX), (int)(screenHeight / scaleY) };													// Create camera according to size and scale of screen.
	
	/* Initialize Player */
	player->addCamera(&camera);
	player->init(engine->getRenderer(), "snake/sprites/snake_block.png", new int[1]{ 1 }, 1, SPRITE_SIZE, SPRITE_SIZE, true);		
	player->setId(std::string("Player"));

	pool->add(*player);																												// Add Player to object pool.

	/* Initialize Fruits */
	for (int i = 0; i < 4; i++) {																									// Use a loop to create and intialize fruit objects then add them to the object pool.
		Fruit *fruit = new Fruit((screenWidth / 16) / scaleX, (screenHeight / 16) / scaleY, SPRITE_SIZE);
		fruit->init(engine->getRenderer(), "snake/sprites/fruit_block.png", new int[1]{ 1 }, 1, SPRITE_SIZE, SPRITE_SIZE);
		fruit->addCamera(&camera);
		fruit->setId(std::string("Fruit"));
		pool->add(*fruit);
	}

	if (success) {
		std::cout << "Game Objects loaded succesfuly" << std::endl;
	}
	else {
		std::cerr << "Error loading Game Objects" << std::endl;
	}

	return success;
}

int SnakeRunner::gameLoop() {
	bool quit = false;
	SDL_Event e;
	Timer stepTimer;

	stepTimer.start();

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
		float timeStep = stepTimer.getTicks() / 1000.f;

		/*
		**********
		UPDATE CYCLE
		**********
		*/

		addUpdates(timeStep);											// Update objects outside of GameObject Pool.

		pool->update(timeStep);											// Signal pool to update all GameObjects.
		stepTimer.start();

		pool->removeFlagged();											// Signal pool to remove all flagged GameObjects from the pool.
		/*
		**********
		RENDER CYCLE
		**********
		*/
		SDL_SetRenderDrawColor(engine->getRenderer(), 0, 0, 0, 0);		// Set background draw color (black)
		SDL_RenderClear(engine->getRenderer());							// Clear window (also assigns background draw color to renderer)
		/* Call Renderers */
		addRenders(engine->getRenderer());								// Render additional Render tasks.
		pool->render(engine->getRenderer());							// Singal pool to render all GameObjects.

		SDL_RenderPresent(engine->getRenderer());						// Update screen.


	}

	return 0;
}

void SnakeRunner::addEvents(SDL_Event &e) {

}

void SnakeRunner::addUpdates(float timeStep) {

}

void SnakeRunner::addRenders(SDL_Renderer *renderer) {
	score.str("");
	score.seekp(0);
	score << "Score: " << player->score;
	if (!scroreTexture.loadFromRenderedText(renderer, score.str().c_str(), engine->getSystemFont(), SDL_Color() = { 255,255,255,255 })) {
		std::cerr << "Unable to render Score Texture" << std::endl;
	}
}

void SnakeRunner::addDeallocations() {
	score.flush();
}

SnakeRunner::~SnakeRunner() {
}
