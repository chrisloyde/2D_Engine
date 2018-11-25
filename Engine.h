#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
class Engine
{
public:
	static Engine* getInstance(int screenWidth, int screenHeight, char *namePtr);	// Create Engine instance and retrieve it. 
	static Engine* getExistingInstance();											// Get an existing Engine Instance.
	bool init(int screenWidth, int screenHeight, const char *namePtr);				// Initialize Engine
	SDL_Window* getWindow() { return gWindow; }										// Get Engine Window	
	SDL_Renderer* getRenderer() { return gRenderer; }								// Get Engine Renderer
	void kill();																	// Kill Engine and free memory.
	~Engine();
private:
	int sW, sH;
	const char *nPtr;
	SDL_Window *gWindow;
	SDL_Renderer *gRenderer;

	static Engine* instance;

	Engine() = default;
};

