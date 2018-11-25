#include "GUI.h"


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
SDL_Rect GUI::getMouseBoundsInWorld(SDL_Rect camera) {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    mouseX = camera.x+mouseX;
    mouseY = camera.y+mouseY;
    SDL_Rect mouseBounds;
    mouseBounds.x = mouseX; mouseBounds.y = mouseY;
    mouseBounds.w = 1; mouseBounds.h = 1;

    return mouseBounds;
}
SDL_Rect GUI::getGUIMouseBounds() {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    SDL_Rect *mouseBounds;
    mouseBounds = new SDL_Rect();
    mouseBounds->x = mouseX; mouseBounds->y = mouseY;
    mouseBounds->w = 1; mouseBounds->h = 1;

    return *mouseBounds;
}
void GUI::update() {
}
void GUI::handleEvent(SDL_Event &e) {
    if (Tile::checkCollision(GUI::getGUIMouseBounds(), rect)) {
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
    // draw hitbox around objects for debugging purposes
    SDL_Rect fakeBox;
    fakeBox.x = (int)rect.x;
    fakeBox.y = (int)rect.y;
    fakeBox.w = width;
    fakeBox.h = height;
    SDL_SetRenderDrawColor(r, 255, 0, 255, 255);
    SDL_RenderDrawRect(r, &fakeBox);
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