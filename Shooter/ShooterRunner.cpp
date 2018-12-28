#include "ShooterRunner.h"

ShooterRunner::ShooterRunner() {
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
	GameRunner::gameLoop();
	GameRunner::kill();

	return 0;
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


void ShooterRunner::addEvents(SDL_Event & e) {
}

void ShooterRunner::addUpdates(float timeStep) {
}

void ShooterRunner::addRenders(SDL_Renderer * renderer) {
}

void ShooterRunner::addDeallocations() {
	delete ShooterTextures::TEXTURE_PLAYER;
	delete ShooterTextures::TEXTURE_BULLET;
}
