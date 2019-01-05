#include "GameObject.h"


GameObject::GameObject() {
    xPos = 0;
    yPos = 0;
    xOffset = 0;
    yOffset = 0;
    width = 32;
    height = 32;
    isSolid = false;
	randomTickChance = 100;
	numberOfFramesBeforeTick = 100 * 10; // 10 seconds
	tickCounter = 0;
}
GameObject::~GameObject() {
    free();
}

bool GameObject::checkCollision(SDL_Rect a, SDL_Rect b) {
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	// calculate sides of the rectangles
	leftA = a.x; rightA = a.x + a.w; topA = a.y; bottomA = a.y + a.h;
	leftB = b.x; rightB = b.x + b.w; topB = b.y; bottomB = b.y + b.h;
	// check for any intersections between A and B
	if (bottomA <= topB) {
		return false;
	}
	if (topA >= bottomB) {
		return false;
	}
	if (rightA <= leftB) {
		return false;
	}
	if (leftA >= rightB) {
		return false;
	}

	return true;
}

float GameObject::getDistance(SDL_Rect a, SDL_Rect b, int divisor) {
	float xDist;
	float yDist;
	// get center points of rectangles for distance calculations
	xDist = abs((a.x + a.w / 2) - (b.x + b.w / 2));
	yDist = abs((a.y + a.h / 2) - (b.y + b.h / 2));
	// return whichever distance is larger
	// divide by tile size to determine how many tiles away
	return (xDist < yDist ? yDist : xDist) / divisor;
}

void GameObject::init(SDL_Renderer *r, Texture *texture, int *numOfSpritesIn, int animNum, int sWidth, int sHeight) {
	gTexture = texture;
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

    if (numOfAnims > 1) {
        // initialize 2D array for spriteStorage. Each animation is a row, each column is a sprite within the animation.
        // numOfAnims controls the number of rows, while numOfSpritesIn controls the number of columns per row.
        spriteStorage = new SDL_Rect *[numOfAnims]; // Anims would be all rows
        for (int i = 0; i < numOfAnims; i++) {
            spriteStorage[i] = new SDL_Rect[numOfSpritesIn[numOfAnims]](); // number of sprites at the particular animation.
        }
        generateSpriteClips();
    }

	delete numOfSpritesIn; // delete number of sprites in since its no longer required.
}
// assign the rectangles in spriteStorage positions for clipping the image.
void GameObject::generateSpriteClips() {
    for (int i = 0; i < numOfAnims; i++) {
        for (int j = 0; j < numOfSprites[i]; j++) {
            spriteStorage[i][j].x = (j * spriteW);
            spriteStorage[i][j].y = (i * spriteH);
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
		++animFrame;															// increment animation frame
		if ((animFrame / numOfSprites[anim]) >= numOfSprites[anim]) {			// Determine if animation frame should be reset to 0.
			animFrame = 0;
			onAnimationEnd();
		}

		currentFrame = spriteStorage[anim][animFrame / numOfSprites[anim]];		// Update current frame of animation.
	}
}

void GameObject::tick() {

	if ((rand() % randomTickChance) == 0) {										// Determine if randomTick should be called.
		randomTick();
	}

	if (tickCounter >= numberOfFramesBeforeTick) {								// Determine if the number of ticks have been reached to call slowTick.
		tickCounter = 0;
		slowTick();
	}

	++tickCounter;																// increment tickCounter because another tick has passed.
}

void GameObject::randomTick() {
}

void GameObject::slowTick() {
}

void GameObject::handleEvent(SDL_Event &e) {
    if (GameObject::checkCollision(GUI::getMouseBoundsInWorld(*cam), bounds)) {
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

void GameObject::onAnimationEnd() {

}

void GameObject::displayInfo() {
    std::cout << getId() << " bounds: x: " << bounds.x << " y: " << yPos << " w: " << bounds.w << " h: " << bounds.w << std::endl;
}
void GameObject::addCamera(SDL_Rect *camera) {
    cam = camera;
}
void GameObject::render(SDL_Renderer *renderer) {
	if (gTexture != nullptr) {
		if (GameObject::checkCollision(bounds, *cam)) {
			if (numOfAnims <= 1) {
				gTexture->render(renderer, (int)xPos - cam->x, (int)yPos - cam->y, nullptr);
			}
			else {
				gTexture->render(renderer, (int)xPos - cam->x, (int)yPos - cam->y, &currentFrame);
			}
		}
	}

}
void GameObject::handleCollision(GameObject *other) {
    //printf("Collision: %s - %s\n", getId(), other->getId());
}
float GameObject::readDistance(GameObject *other) {
    return GameObject::getDistance(bounds, other->bounds, bounds.w);
}

void GameObject::setId(std::string str) {
	strcpy_s(id, 64, str.c_str());
}

const char* GameObject::getId() {
	return id;
}

void GameObject::free() {
    if (numOfAnims > 1) {
        for (int i = 0; i < numOfAnims; i++) {
            delete[]  spriteStorage[i];
        }
    }
    delete[] spriteStorage;
    delete[] numOfSprites;
    cam = nullptr;
	gTexture = nullptr;
}

