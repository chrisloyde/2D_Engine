#include "Engine.h"

Engine* Engine::instance = 0;

Engine* Engine::getInstance(int screenWidth, int screenHeight, char *namePtr) {
	if (instance == 0) {
		instance = new Engine;
		instance->init(screenWidth, screenHeight, namePtr);
	}

	return instance;
}

Engine *Engine::getInstance() {
	if (instance == 0) {
		return nullptr;
	}
	return instance;
}

bool Engine::init(int screenWidth, int screenHeight, const char *namePtr) {
	sW = screenWidth;
	sH = screenHeight;
	nPtr = namePtr;

	printf("Initializing Engine...\n");
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else {
		//create window
		gWindow = SDL_CreateWindow(nPtr,
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			sW, sH, SDL_WINDOW_SHOWN);
		if (gWindow == nullptr) {
			std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
			success = false;
		}
		else {
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == nullptr) {
				std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
				success = false;
			}
			else {
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					std::cerr << "SDL_image could not be initialized! SDL_image error: " << SDL_GetError() << std::endl;
					success = false;
				}

				//initialize SDL ttf
				if (TTF_Init() == -1) {
					std::cerr << "SDL ttf could not be initialized! SDL_ttf Error: " << TTF_GetError() << std::endl;
					success = false;
				}
			}
		}
	}
	if (success) {
		printf("Engine initialized successfully\n");
	}
	else {
		std::cerr << "Engine could not be initialized" << std::endl;
	}
	return success;
}

void Engine::kill() {
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;
	gRenderer = nullptr;

	IMG_Quit();
	SDL_Quit();
	printf("Engine Killed\n");
}
