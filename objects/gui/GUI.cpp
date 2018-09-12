#include "headers/GUI.h"


GUI::GUI() {
    gTexture = new Texture();
    setBounds(0,0,32,32);
}
void GUI::setBounds(SDL_Rect r) {
    rect = r;
}
void GUI::setBounds(int x, int y, int w, int h) {
    rect.x = xPos = x;
    rect.y = yPos = y;
    rect.w = width = w;
    rect.h = height = h;
}
void GUI::loadMedia(SDL_Renderer *renderer, std::string path) {
    gTexture->loadFromFile(renderer, path);
}
void GUI::update() {
    int mouseX, mouseY, mouseW, mouseH;
    SDL_GetMouseState(&mouseX, &mouseY);
    mouseW = 1; mouseH = 1;
    // create a bounding box for the mouse
    mouseBounds.x = mouseX; mouseBounds.y = mouseY;
    mouseBounds.w = mouseW; mouseBounds.h = mouseH;
}
void GUI::handleEvent(SDL_Event &e) {
    if (Tile::checkCollision(mouseBounds, rect)) {
        mouseEnter = true;
        switch(e.type) {
            case SDL_MOUSEBUTTONDOWN: onClick(e); break;
            default: break;
        }
    } else {
        mouseEnter = false;
    }
}
void GUI::render(SDL_Renderer *r) {
    gTexture->render(r,rect.x,rect.y);
}
void GUI::onClick(SDL_Event &e) {
    // left click
    if (e.button.button == SDL_BUTTON_LEFT) {
        displayInfo();
    }
}
void GUI::onHover() {
}

void GUI::displayInfo() {
    std::cout << "GUI Bounds: " << xPos << " " << yPos << " " << height << " " << width << std::endl;
}
void GUI::free() {
    gTexture->free();
}