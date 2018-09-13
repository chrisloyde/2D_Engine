#include "headers/GameObjectHandler.h"
#include "../block/headers/Tile.h"

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
    gO->setSolid(true);
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
    int *chk;
    chk = handleCollisions();
    if (chk[0] != -1 && chk[1] != -1) {
        // ensure both objects are told they are colliding with another object.
        elements[chk[0]]->handleCollision(elements[chk[1]]);
        elements[chk[1]]->handleCollision(elements[chk[0]]);
    }
}

int* GameObjectHandler::handleCollisions() {
    for (int i = 0; i < elements.size(); i++) {
        for (int j = i+1; j < elements.size(); j++) {
            if(Tile::checkCollision(elements[i]->bounds, elements[j]->bounds)){
                return new int[2]{i, j};
            }
        }
    }
    return new int[2]{-1,-1};
}

void GameObjectHandler::render(SDL_Renderer *r, SDL_Rect camera) {
    if (!elements.empty()) {
        if (!elements.empty()) {
            for (auto &element : elements) {
                element->render(r);
            }
        }

        // draw lines between object center points.
        for (int i = 0; i < elements.size(); i++) {
            for (int j = i+1; j < elements.size(); j++) { // add one to intializer since we don't need to check the first element twice
                SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
                SDL_RenderDrawLine(r,
                                   (elements[i]->bounds.x + elements[i]->bounds.w / 2) - camera.x,
                                   (elements[i]->bounds.y + elements[i]->bounds.h / 2) - camera.y,
                                   (elements[j ]->bounds.x + elements[j]->bounds.w / 2) - camera.x,
                                   (elements[j]->bounds.y + elements[j]->bounds.h / 2) - camera.y);
            }
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
    elements.clear();;
}



