#include <iostream>
#include <ctime>
#include <sstream>
#include "Engine.h"
#include "GameObjectHandler.h"
#include "Timer.h"
#include "snake/EntitySnake.h"
#include "snake/Fruit.h"


using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SPRITE_SIZE = 16;
char NAME[24] = "Engine Example: Snake";
SDL_Rect camera = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
SDL_Color fontColor = { 255,255,255,255 };
TTF_Font *font = nullptr;

Engine* engine = nullptr;
GameObjectHandler *oHandler = nullptr;
EntitySnake *player = nullptr;

void gameLoop();
bool loadGameObjects();

int main(int argv, char** args) {

	printf("Hello World Snake\n");
	srand(time(0));
	engine = Engine::getInstance(SCREEN_WIDTH, SCREEN_HEIGHT, NAME);
	oHandler = GameObjectHandler::getInstance();

	loadGameObjects();
	gameLoop();

	engine->kill();

	return 0;
}

void gameLoop() {
	bool quit = false;

	SDL_Event e;

	Timer stepTimer;
	int countedFrames = 0;
	stringstream score;
	Texture scoreTex;
	stepTimer.start();

	printf("Game Started Successfully!\n");

	while (!quit) {
		// Handle Events

		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			else {
				oHandler->handleEvents(e, camera);
			}
		}
		float timeStep = stepTimer.getTicks() / 1000.f;

		// Update Cycle
		oHandler->update(timeStep);

		stepTimer.start();
		// Render Cycle
		SDL_SetRenderDrawColor(engine->getRenderer(), 0, 0, 0, 0);
		SDL_RenderClear(engine->getRenderer());
		// Call Renderers
		oHandler->render(engine->getRenderer(), camera);
		scoreTex.render(engine->getRenderer(), 0, 0);

		SDL_RenderPresent(engine->getRenderer()); // update screen

		oHandler->removeFlagged();

		//Update Screen Text
		score.str("");
		score << "Score: " << player->score;
		if (!scoreTex.loadFromRenderedText(engine->getRenderer(), score.str().c_str(), font, fontColor)) {
			cerr << "Unable to render Score Texture" << endl;
		}
	}
}

bool loadGameObjects() {
	bool success = true;
	printf("Loading Game Objects...\n");
	player = new EntitySnake((SCREEN_WIDTH / 2) - 16, (SCREEN_HEIGHT / 16) + 16, SPRITE_SIZE, SCREEN_WIDTH / 16, SCREEN_HEIGHT / 16);
	player->addCamera(&camera);
	player->init(engine->getRenderer(), "snake/sprites/snake_block.png", new int[1]{ 1 }, 1, SPRITE_SIZE, SPRITE_SIZE, true);
	player->setId(new string("Player"));
	oHandler->add(player);

	for (int i = 0; i < 4; i++) {
		Fruit *fruit = new Fruit((SCREEN_WIDTH / 16), (SCREEN_HEIGHT / 16), SPRITE_SIZE);
		fruit->init(engine->getRenderer(), "snake/sprites/fruit_block.png", new int[1]{ 1 }, 1,
			SPRITE_SIZE, SPRITE_SIZE);
		fruit->addCamera(&camera);
		fruit->setId(new string("Fruit"));
		oHandler->add(fruit);
	}

	font = TTF_OpenFont("fonts/Vegur-Regular.otf", 24);
	if (font == nullptr) {
		cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << endl;
		success = false;
	}

	if (success) {
		printf("Game Objects loaded successfully\n");
	}
	else {
		cerr << "Error Loading Game Objects" << endl;
	}
	return success;
}