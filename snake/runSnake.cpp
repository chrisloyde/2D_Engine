#include <iostream>
#include "../../src/Engine.h"
#include "../../src/objects/handlers/headers/GameObjectHandler.h"
#include "EntitySnake.h"
#include "../../src/objects/headers/Timer.h"
#include "Fruit.h"
#include <ctime>
#include <sstream>

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SPRITE_SIZE = 16;
char NAME[24] = "Engine Example: Snake";
SDL_Rect camera = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
SDL_Color fontColor = {255,255,255,255};
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
    Timer updateTimer;
    int countedFrames = 0;
    int currentTime = 0; int previousTime = -1;
    bool shouldUpdate = false;
    stringstream score;
    Texture scoreTex;
    stepTimer.start();
    updateTimer.start();

    printf("Game Started Successfully!\n");

    while(!quit) {
        currentTime = updateTimer.getTicks()/100;
        // Handle Events
        shouldUpdate = currentTime != previousTime;

        while(SDL_PollEvent(&e) != 0) {
            if(e.type == SDL_QUIT) {
                quit = true;
            } else {
                oHandler->handleEvents(e, camera);
            }
        }
        float timeStep = stepTimer.getTicks()/1000.f;
        // Update Cycle
        if (shouldUpdate) {
            oHandler->update(timeStep);
        }

        stepTimer.start();
        // Render Cycle
        SDL_SetRenderDrawColor(engine->getRenderer(), 0, 0, 0, 0);
        SDL_RenderClear(engine->getRenderer());
        // Call Renderers
        oHandler->render(engine->getRenderer(), camera);
        scoreTex.render(engine->getRenderer(), 0,0);

        SDL_RenderPresent(engine->getRenderer()); // update screen
        oHandler->removeFlagged();

        //Update Screen Text
        score.str("");
        score << "Score: " << player->score;
        if (!scoreTex.loadFromRenderedText(engine->getRenderer(), score.str().c_str(), font, fontColor)) {
            cerr << "Unable to render Score Texture" << endl;
        }
        previousTime = currentTime;
    }
}

bool loadGameObjects() {
    bool success = true;
    printf("Loading Game Objects...\n");
    player = new EntitySnake((SCREEN_WIDTH/2)-16,(SCREEN_HEIGHT/16)+16,SPRITE_SIZE,SCREEN_WIDTH/16, SCREEN_HEIGHT/16);
    player->addCamera(&camera);
    player->init(engine->getRenderer(), "../example_projects/ex_snake/sprites/snake_block.png", new int[1]{1}, 1, SPRITE_SIZE, SPRITE_SIZE, true);
    player->setId(new string("Player"));
    oHandler->add(player);

    for (int i = 0; i < 1; i++) {
        Fruit *fruit = new Fruit((SCREEN_WIDTH / 16), (SCREEN_HEIGHT / 16), SPRITE_SIZE);
        fruit->init(engine->getRenderer(), "../example_projects/ex_snake/sprites/fruit_block.png", new int[1]{1}, 1,
                    SPRITE_SIZE, SPRITE_SIZE);
        fruit->addCamera(&camera);
        fruit->setId(new string("Fruit"));
        oHandler->add(fruit);
    }

    font = TTF_OpenFont("./fonts/rpg.otf", 12);
    if (font == nullptr) {
        cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << endl;
        success = false;
    }

    if (success) {
        printf("Game Objects loaded successfully\n");
    } else {
        cerr << "Error Loading Game Objects" << endl;
    }
    return success;
}


