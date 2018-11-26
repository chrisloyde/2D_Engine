#include <iostream>
#include <ctime>
#include <sstream>
#include "Engine.h"
#include "GameObjectHandler.h"
#include "Timer.h"
#include "snake/EntitySnake.h"
#include "snake/Fruit.h"


using namespace std;

Engine* engine				= nullptr;	// REQUIRED
GameObjectHandler *oHandler = nullptr;	// REQUIRED
int SCREEN_WIDTH			= 640;		// SEMI-REQUIRED - Width used for Engine Initialization, but values can be modified
int SCREEN_HEIGHT			= 480;		// SEMI-REQUIRED - Height used for Engine Initialization, but values can be modified.
float SCALE_SIZE_X			= 1.25;		// SEMI-REQUIRED - Scale size is used to determine drawing scale, values can be modified (1 default)
float SCALE_SIZE_Y			= 1.25;
										// SEMI-REQUIRED - Camera represents the view port of what the player sees on screen. Effects what is rendered. Values can be modified
SDL_Rect camera = { 0,0,SCREEN_WIDTH / SCALE_SIZE_X, SCREEN_HEIGHT / SCALE_SIZE_Y };	

/*
**********
GAME SPECIFIC START
*/
#define SPRITE_SIZE 16
char NAME[24]			= "Engine Example: Snake";
EntitySnake *player		= nullptr;

stringstream score;
Texture scoreTex;

/*
GAME SPECIFIC END
**********
*/

void gameLoop();
bool loadGameObjects();						// loadGameObjects is game specific, meaning the entire function needs to change depending on the game.

void gameSpecificEvent(SDL_Event &e);		// gameSpecificEvent() is for event handling game specific events without needing to alter the gameloop.
void gameSpecificUpdates(float timestep);	// gameSpecificUpdates is for updating game specific updates without needing to alter the gameloop.
void gameSpecificRenders(SDL_Renderer *r);	// gameSpecificRenders is for updating game specific renders without needing to alter the gameloop.
void gameSpecificDeallocate();				// gameSpecificDeallocate if for deallocating and killing objects that are specific to the game.

void kill();								// Free memory assosciated with required objects.


int main(int argv, char** args) {

	srand(time(0));
	engine		= Engine::getInstance(SCREEN_WIDTH, SCREEN_HEIGHT, NAME);	// Initalize Engine
	engine->assignRenderScale(SCALE_SIZE_X, SCALE_SIZE_Y);					// Set Window Scale
	oHandler	= GameObjectHandler::getInstance();							// Initialize Game Object Handler

	loadGameObjects();			// load game specific objects
	gameLoop();					// run game loop

	gameSpecificDeallocate();	// Kill and Deallocate Memory from Game Specific Objects.
	kill();						// Kill and Deallocate Memory from Required Objects.

	return 0;
}

void gameLoop() {
	bool quit = false;

	SDL_Event e;

	Timer stepTimer;
	//int countedFrames = 0;

	stepTimer.start();

	printf("Game Started Successfully!\n");

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
				gameSpecificEvent(e);								// Tell Game Specific Objects, that are not in Object Handler, to Handle Events
				oHandler->handleEvents(e);							// Tell Objects to Handle Events in Object Handler
			}
		}
		float timeStep = stepTimer.getTicks() / 1000.f;

		/*
		**********
		UPDATE CYCLE
		**********
		*/
		gameSpecificUpdates(timeStep);								// Update Game Specific Objects that are not in Object Handler

		oHandler->update(timeStep);									// Update Objects in Object Handler

		stepTimer.start();

		oHandler->removeFlagged();									// Remove objects from Object Handler that are flagged for removal.
		/*
		**********
		RENDER CYCLE
		**********
		*/
		SDL_SetRenderDrawColor(engine->getRenderer(), 0, 0, 0, 0);	// Set background draw color (black)
		SDL_RenderClear(engine->getRenderer());						// Clear window (also assigns background draw color to renderer)
		// Call Renderers
		gameSpecificRenders(engine->getRenderer());					// Render Game Specific Objects that are not in Object Handler
		oHandler->render(engine->getRenderer());					// Render Objects in Object Handler
		scoreTex.render(engine->getRenderer(), 0, 0);				// Render Score Texture (Text which displays "score" and how much fruit the player got).

		SDL_RenderPresent(engine->getRenderer());					// update screen


	}
}

bool loadGameObjects() {
	bool success = true;
	printf("Loading Game Objects...\n");
	player = new EntitySnake((SCREEN_WIDTH / 2) - 16, (SCREEN_HEIGHT / 16) + 16, SPRITE_SIZE, ((SCREEN_WIDTH / 16)/SCALE_SIZE_X), ((SCREEN_HEIGHT / 16)/SCALE_SIZE_Y));
	player->addCamera(&camera);
	player->init(engine->getRenderer(), "snake/sprites/snake_block.png", new int[1]{ 1 }, 1, SPRITE_SIZE, SPRITE_SIZE, true);
	player->setId(std::string("Player"));
	oHandler->add(player);

	for (int i = 0; i < 4; i++) {
		Fruit *fruit = new Fruit((SCREEN_WIDTH / 16)/SCALE_SIZE_X, (SCREEN_HEIGHT / 16)/SCALE_SIZE_Y, SPRITE_SIZE);
		fruit->init(engine->getRenderer(), "snake/sprites/fruit_block.png", new int[1]{ 1 }, 1,
			SPRITE_SIZE, SPRITE_SIZE);
		fruit->addCamera(&camera);
		fruit->setId(string("Fruit"));
		oHandler->add(fruit);
	}

	if (success) {
		printf("Game Objects loaded successfully\n");
	}
	else {
		cerr << "Error Loading Game Objects" << endl;
	}
	return success;
}

void gameSpecificEvent(SDL_Event &e) {
	// Do not call events on objects already in GameObjectHandler
}

void gameSpecificUpdates(float timestep) {
	// Do not call update on objects already in GameObjectHandler
}

void gameSpecificRenders(SDL_Renderer *r) {
	// Do no call render on objects already in GameObjectHandler

	//Update Screen Text
	score.str("");							// clear string
	score.seekp(0);							// set position to beginning of string
	score << "Score: " << player->score;	// assign score to stringstream.
	if (!scoreTex.loadFromRenderedText(r, score.str().c_str(), engine->getSystemFont(), SDL_Color() = { 255,255,255,255 })) {
		cerr << "Unable to render Score Texture" << endl;
	}
}

void gameSpecificDeallocate() {
	// Do not deallocate objects that are REQUIRED or alraedy in GameObjectHandler

	score.flush();	// clear score string stream.
}

void kill() {
	delete oHandler;
	delete engine;
}