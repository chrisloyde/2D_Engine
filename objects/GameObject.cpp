#include "headers/GameObject.h"
#include "gui/headers/GUI.h"

GameObject::GameObject() {
    xPos = 0;
    yPos = 0;
    xOffset = 0;
    yOffset = 0;
    width = 32;
    height = 32;
    isSolid = false;
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
    if (numOfAnims > 1) {
        // initialize 2D array for spriteStorage. Each animation is a row, each column is a sprite within the animation.
        // numOfAnims controls the number of rows, while numOfSpritesIn controls the number of columns per row.
        spriteStorage = new SDL_Rect *[numOfAnims]; // Anims would be all rows
        for (int i = 0; i < numOfAnims; i++) {
            spriteStorage[i] = new SDL_Rect[numOfSpritesIn[numOfAnims]](); // number of sprites at the particular animation.
        }
        generateSpriteClips();
    }
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
void GameObject::setBounds(int x, int y, int w, int h, int xOff, int yOff) {
    xOffset = xOff;
    yOffset = yOff;
    width = w;
    height = h;
    bounds.x = x + xOff;
    bounds.y = y + yOff;
    bounds.w =  width-xOff;
    bounds.h = height-yOff;
}
void GameObject::setPos(int x, int y) {
    xPos = x;
    yPos = y;
}
void GameObject::setSolid(bool s) {
    isSolid = s;
}
void GameObject::update(float timeStep) {
    // if position has changed, update bounds.
    if (bounds.x != (xPos+xOffset) || bounds.y != (yPos+yOffset)) {
        //setPos(bounds.x, bounds.y);
        setBounds((int) xPos, (int) yPos, width, height, (int)xOffset, (int)yOffset);
    }

    // don't bother updating animation frames if it's just a single image.
    if (numOfAnims > 1) {
        ++animFrame; // increment animation frame
        if ((animFrame / numOfSprites[anim]) >= numOfSprites[anim]) {
            animFrame = 0;
        }
        // update currentFrame of animation.
        currentFrame = spriteStorage[anim][animFrame / numOfSprites[anim]];
    }
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
    std::cout << id << " bounds: x: " << bounds.x << " y: " << yPos << " w: " << bounds.w << " h: " << bounds.w << std::endl;
}
void GameObject::addCamera(SDL_Rect *camera) {
    cam = camera;
}
void GameObject::render(SDL_Renderer *renderer) {
    if (Tile::checkCollision(bounds, *cam)) {
        if (numOfAnims <= 1) {
            gTexture->render(renderer, (int) xPos - cam->x, (int) yPos - cam->y, nullptr);
        } else {
            gTexture->render(renderer, (int) xPos - cam->x, (int) yPos - cam->y, &currentFrame);
        }

        // draw hitbox around objects for debugging purposes
        /*
        SDL_Rect fakeBox;
        fakeBox.x = bounds.x-cam->x;
        fakeBox.y = bounds.y-cam->y;
        fakeBox.w = bounds.w;
        fakeBox.h = bounds.h;
        SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
        SDL_RenderDrawRect(renderer, &fakeBox);
         */
    }

}
void GameObject::handleCollision(GameObject *other) {
    printf("Collision: %s - %s\n", id.c_str(), other->id.c_str());
}
float GameObject::readDistance(GameObject *other) {
    return Tile::getDistance(bounds, other->bounds, bounds.w);
}

void GameObject::setId(std::string *str) {
    id = *str;
}
void GameObject::free() {
    gTexture->free();
    if (numOfAnims > 1) {
        for (int i = 0; i < numOfAnims; i++) {
            delete[]  spriteStorage[i];
        }
    }
    delete[] spriteStorage;
    delete[] numOfSprites;
    cam = nullptr;
}

