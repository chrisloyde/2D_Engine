#include "headers/GameObject.h"
GameObject::GameObject() {
    xPos = 0;
    yPos = 0;
    width = 32;
    height = 32;
    gTexture = new Texture();
}
GameObject::~GameObject() {
    free();
}
void GameObject::init(SDL_Renderer *r, std::string path) {
    gTexture->loadFromFile(r, path);
}
void GameObject::setBounds(int x, int y, int w, int h) {
    xPos = bounds.x = x;
    yPos = bounds.y = y;
    width = bounds.w = w;
    height = bounds.h = h;
}
void GameObject::update(float timeStep) {

}
void GameObject::handleEvent(SDL_Event &e) {

}
void GameObject::render(SDL_Renderer *renderer, SDL_Rect camera) {

}
void GameObject::free() {

}