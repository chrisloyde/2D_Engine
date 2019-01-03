#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

/*
Ruin2D Engine
Engine follows semantic revisions of MAJOR.MINOR.PATCH-BUILD
MAJOR - Incompatible changes, requires update of project to support engine.
MINOR - Adds more functionality, but backwards compatible.
PATCH - backwarsds compatible bug fixes.
BUILD - a(alpha), b(beta), r(release).
*/

class Engine
{
public:
	static Engine* getInstance(int screenWidth, int screenHeight, char *namePtr);	// Create Engine instance and retrieve it. 
	static Engine* getExistingInstance();											// Get an existing Engine Instance.

	bool init(int screenWidth, int screenHeight, const char *namePtr);				// Initialize Engine
	bool assignSystemFont(const char *path, int size);								// Change Font loaded into Engine
	void assignWindowName(const char *name);										// Change Name of Engine Window
	void assignWindowSize(int width, int height);									// Change Size of Engine Window
	bool assignRenderScale(float scaleX, float scaleY);								// Change Drawing Scale for Rendering

	SDL_Window* getWindow() { return gWindow; }										// Get Engine Window	
	SDL_Renderer* getRenderer() { return gRenderer; }								// Get Engine Renderer
	TTF_Font* getSystemFont() { return sysFont; }									// Get Font loaded in Engine
	const char* getVersionNumber() { return version; }
	const char* getWindowTitle() { return nPtr; }
	int getScreenHeight() { return sH; }
	int getScreenWidth() { return sW; }
	float getScaleX() { return sX; }
	float getScaleY() { return sY; }
	void kill();																	// Kill Engine and free memory.
	~Engine();
private:
	const char version[24] = "1.0.1-alpha";
	int sW, sH;					// screen width, screen height
	float sX = 1, sY = 1;		// scale X, scale Y
	const char		*nPtr;
	SDL_Window		*gWindow;
	SDL_Renderer	*gRenderer;
	TTF_Font		*sysFont;

	static Engine	*instance;

	Engine() = default;
};

