#include "headers/GUIHandler.h"
GUIHandler::GUIHandler() {
}
void GUIHandler::add(GUI *g) {
    elements.push_back(*g);
}
void GUIHandler::createAndAdd(int xPos, int yPos, int width, int height, SDL_Renderer *r, std::string path) {
    GUI gNew;
    gNew.setBounds(xPos, yPos, width, height);
    gNew.loadMedia(r, path);
    GUI *pG = &gNew; // create pointer for gui object
    elements.push_back(*pG);
}
void GUIHandler::update() {
    if (!elements.empty()) {
        for (auto &element : elements) {
            element.update();
        }
    }
}
void GUIHandler::handleEvents(SDL_Event &e) {
    if (!elements.empty()) {
        for (auto element : elements) {
            element.handleEvent(e);
        }
    }
}
void GUIHandler::render(SDL_Renderer *r) {
    if (!elements.empty()) {
        for (auto &element : elements) {
            element.render(r);
        }
    }
}
void GUIHandler::free() {
    if (!elements.empty()) {
        for (auto &element : elements) {
            element.free();
        }
    }
    elements.clear();
}