#include "headers/GameObject.h"
#include "gui/headers/GUI.h"

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
void GameObject::init(SDL_Renderer *r, std::string path, int *numOfSpritesIn, int animNum, int sWidth, int sHeight) {
    // numOfSprites is the number of sprites per animation row in the spritesheet
    // from the integer array provided, we can determine the number of sprites per animation
    // and copy into a local array in the game object.
    // It is EXTREMELY important that the integers within the numOfSpritesIn array equal the number
    // of sprites per animation (from top to bottom).
    numOfSprites = new int[animNum];
    for (int i = 0; i < animNum; i++) {
        numOfSprites[i] = numOfSpritesIn[i];
    }
    spriteW = sWidth;
    spriteH = sHeight;
    numOfAnims = animNum;

    gTexture->loadFromFile(r, path);
    // initialize 2D array for spriteStorage. Each animation is a row, each column is a sprite within the animation.
    // numOfAnims controls the number of rows, while numOfSpritesIn controls the number of columns per row.
    spriteStorage = new SDL_Rect*[numOfAnims]; // Anims would be all rows
    for(int i = 0; i < numOfAnims; i++) {
        spriteStorage[i] = new SDL_Rect[numOfSpritesIn[numOfAnims]](); // number of sprites at the particular animation.
    }
    generateSpriteClips();
}
// assign the rectangles in spriteStorage positions for clipping the image.
void GameObject::generateSpriteClips() {
    for (int i = 0; i < numOfAnims; i++) {
        for (int j = 0; j < numOfSprites[i]; j++) {
            spriteStorage[i][j].x = (j * spriteW);
            spriteStorage[i][j].y = (i*spriteH);
            spriteStorage[i][j].w = spriteW;
            spriteStorage[i][j].h = spriteH;
        }
    }
}
void GameObject::setBounds(int x, int y, int w, int h) {
    bounds.x = x;
    bounds.y = y;
    bounds.w = w;
    bounds.h = h;
}
void GameObject::setPos(int x, int y) {
    xPos = x;
    yPos = y;
}
void GameObject::update(float timeStep) {
    ++animFrame; // increment animation frame
    if ((animFrame/numOfSprites[anim]) >= numOfSprites[anim]) {
        animFrame = 0;
    }
    // if position has changed, update bounds.
    if (bounds.x != xPos || bounds.y != yPos) {
        setBounds((int) xPos, (int) yPos, width, height);
    }

    // update currentFrame of animation.
    currentFrame = spriteStorage[anim][animFrame/numOfSprites[anim]];
}
void GameObject::handleEvent(SDL_Event &e, SDL_Rect camera) {
    if (Tile::checkCollision(GUI::getMouseBoundsInWorld(camera), bounds)) {
        switch(e.type) {
            case SDL_MOUSEBUTTONDOWN:
                if (e.button.button == SDL_BUTTON_LEFT) {
                    displayInfo();
                }
                break;
            default: break;
        }
    }
}
void GameObject::displayInfo() {
    std::cout << id << std::endl;
}
void GameObject::render(SDL_Renderer *renderer, SDL_Rect camera) {
    gTexture->render(renderer,(int)xPos-camera.x, (int)yPos-camera.y, &currentFrame);
}
void GameObject::free() {

}