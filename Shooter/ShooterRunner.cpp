#include "ShooterRunner.h"

ShooterRunner::ShooterRunner() {
	engine = nullptr;
	pool = nullptr;
	screenWidth = 0;
	screenHeight = 0;
	scaleSizeX = 0;
	scaleSizeY = 0;
}

int ShooterRunner::run() {
	srand(time(0));
	char windowName[24] = "2DEngine: Shooter";
	engine = Engine::getInstance(SCREEN_WIDTH, SCREEN_HEIGHT, windowName);
	pool = GameObjectPool::getInstance();
	if (engine == nullptr || pool == nullptr) {
		std::cerr << "Something went wrong when adding engine or pool!" << std::endl;
		return 1;
	}
	engine->assignRenderScale(SCALE, SCALE);


	if (!init()) {
		std::cerr << "Something went wrong during intializations!" << std::endl;
		return 1;
	}
	gameLoop();
	kill();

	return 0;
}

bool ShooterRunner::attachEngine(Engine &inEngine) {
	engine = &inEngine;

	return (pool != nullptr);
}

bool ShooterRunner::attachObjectPool(GameObjectPool &inPool) {
	pool = &inPool;

	return (pool != nullptr);
}

bool ShooterRunner::init() {
	bool success = true;

	screenWidth = engine->getScreenWidth();
	screenHeight = engine->getScreenHeight();
	scaleSizeX = engine->getScaleX();
	scaleSizeY = engine->getScaleY();

	std::cout << "Loading Textures..." << std::endl;
	
	ShooterTextures textures(engine->getRenderer());										// initialize textures.

	std::cout << "Loading Game Objects..." << std::endl;

	camera = { 0,0, (int)(screenWidth / scaleSizeX), (int)(screenHeight / scaleSizeY) };

	/* Intialize Player */
	player = new EntityGunman();
	player->addCamera(&camera);
	player->setId("Player");
	player->setPos((screenWidth / 2) - SPRITE_SIZE, screenHeight - (32 * 4));

	player->setBounds(
		(screenWidth/2) - SPRITE_SIZE,
		screenHeight-(32*4), 
		SPRITE_SIZE, SPRITE_SIZE, 
		0, 0 );

	player->init(engine->getRenderer(), ShooterTextures::TEXTURE_PLAYER, new int[1]{ 1 }, 1, SPRITE_SIZE, SPRITE_SIZE);
	player->setWorldWidth(SCREEN_WIDTH);

	pool->add(*player);

	if (success) {
		std::cout << "Game Objects loaded successfully!" << std::endl;
	} 
	else {
		std::cerr << "Error loading Game Objects!" << std::endl;
	}

	return success;
}

int ShooterRunner::gameLoop() {
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
		pool->render(engine->getRenderer());							// Singal pool to render all GameObjects.
		addRenders(engine->getRenderer());								// Render additional Render tasks.

		SDL_RenderPresent(engine->getRenderer());						// Update screen.


	}

	return 0;
}

void ShooterRunner::addEvents(SDL_Event & e)
{
}

void ShooterRunner::addUpdates(float timeStep)
{
}

void ShooterRunner::addRenders(SDL_Renderer * renderer)
{
}

void ShooterRunner::addDeallocations()
{
}

void ShooterRunner::kill() {
	delete pool;
	delete engine;
	delete ShooterTextures::TEXTURE_PLAYER;
	delete ShooterTextures::TEXTURE_BULLET;
}

ShooterRunner::~ShooterRunner()
{
}
