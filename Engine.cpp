#include "Engine.h"

Engine* Engine::instance = 0;

Engine* Engine::getInstance(int screenWidth, int screenHeight, char *namePtr) {
	if (instance == 0) {
		instance = new Engine;
		if (!instance->init(screenWidth, screenHeight, namePtr)) {
			return nullptr;
		}

	}

	return instance;
}

Engine *Engine::getExistingInstance() {
	if (instance == 0) {
		return nullptr;
	}
	return instance;
}

bool Engine::assignSystemFont(const char *path, int size) {
	bool success = true;

	TTF_CloseFont(sysFont);
	sysFont = TTF_OpenFont(path, size);

	if (sysFont == nullptr) {
		std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
		success = false;
	}

	return success;
}

void Engine::assignWindowName(const char* name) {

	if (gWindow != nullptr) {
		nPtr = nullptr;
		nPtr = name;
		SDL_SetWindowTitle(gWindow, nPtr);
	}
}

void Engine::assignWindowSize(int width, int height) {
	if (gWindow != nullptr) {
		// check if the width or height changed
		if (width != sW || height != sH) {
			SDL_SetWindowSize(gWindow, width, height);
			sW = width;
			sH = height;
		}
	}
}

bool Engine::assignRenderScale(float scaleX, float scaleY) {
	int val = 0;
	// check if scalex or scale y changed
	if (scaleX != sX || scaleY != sY) {
		val = SDL_RenderSetScale(gRenderer, scaleX, scaleY);
		if (val != 0) {
			std::cerr << "Unable to set drawing scale: " << SDL_GetError() << std::endl;
		}
		sX = scaleX;
		sY = scaleY;
	}
	return val;
}

void EngineUpdate() {
}

bool Engine::init(int screenWidth, int screenHeight, const char *namePtr) {
	sW = screenWidth;
	sH = screenHeight;

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

	assignWindowName(namePtr);

	// Load Default System Font
	// assignSystemFont should only effect success if success is already true, this prevents initalization from returning a false success.
	if (success) {
		success = assignSystemFont("ruin_engine/fonts/Vegur-Regular.otf", 24);
	}
	else {
		assignSystemFont("ruin_engine/fonts/Vegur-Regular.otf", 24);
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
	TTF_CloseFont(sysFont);
	gWindow = nullptr;
	gRenderer = nullptr;
	sysFont = nullptr;
	nPtr = nullptr;
	instance = nullptr;

	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	printf("Engine Killed\n");
}

Engine::~Engine() {
	kill();
}
