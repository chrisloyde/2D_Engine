#include "headers/GameObjectHandler.h"
GameObjectHandler::GameObjectHandler() {
}
GameObjectHandler::~GameObjectHandler() {
    free();
}
void GameObjectHandler::add(GameObject *o) {
    elements.push_back(o);
}
void GameObjectHandler::createBasicAndAdd(SDL_Rect bounds, int xOff, int yOff, SDL_Renderer *renderer, std::string path, int spriteWidth, int spriteHeight, SDL_Rect *cam) {
    GameObject *gO = new GameObject();
    gO->init(renderer, path, new int[1]{1}, 1, 32, 48); // load image
    gO->setPos(bounds.x+xOff, bounds.y+yOff);
    gO->setBounds(bounds.x+xOff, bounds.y+yOff,bounds.w-xOff,bounds.h-yOff,xOff,yOff);
    gO->setSolid(false);
    gO->addCamera(cam);
    add(gO);
}

void GameObjectHandler::update(float timeStep) {
    std::sort(elements.begin(), elements.end(), order_yPos);
    if (!elements.empty()) {
        for (auto &element : elements) {
            element->update(timeStep);
        }
    }
}

void GameObjectHandler::render(SDL_Renderer *r, SDL_Rect camera) {
    if (!elements.empty()) {
        for (auto &element : elements) {
            element->render(r);
        }
    }
}

void GameObjectHandler::handleEvents(SDL_Event &e, SDL_Rect cam) {
    if (!elements.empty()) {
        for (auto element : elements) {
            element->handleEvent(e, cam);
        }
    }
}

void GameObjectHandler::free() {
    if (!elements.empty()) {
        for (auto &element : elements) {
            element->free();
        }
    }
    elements.clear();
}



