
#ifndef INC_2DENGINE_GAMEOBJECTHANDLER_H
#define INC_2DENGINE_GAMEOBJECTHANDLER_H

#include <vector>
#include <algorithm>
#include "../../headers/GameObject.h"
#include "../../entity/headers/EntityPlayer.h"

class GameObjectHandler {
public:
    ~GameObjectHandler();
    static GameObjectHandler* getInstance();
    void update(float timeStep);
    void render(SDL_Renderer *r, SDL_Rect camera);
    void handleEvents(SDL_Event &e, SDL_Rect cam);
    int* handleCollisions(); // returns an array (length 2) which provides the two objects colliding in the elements list.
    // only use for single sprites, auto sets to solid
    void createBasicAndAdd(SDL_Rect bounds, int xOff, int yOff, SDL_Renderer *, std::string , int spriteWidth, int SpriteHeight, SDL_Rect *cam);
    void add(GameObject *o);
    void free();
private:
    static GameObjectHandler* instance;
    std::vector<GameObject *> elements;
    // struct for ordering vector to move elements depending on their y position.
    // We do this to make objects render above and below eachother.
    GameObjectHandler();
    struct order
    {
        bool operator() (GameObject *lhs, GameObject *rhs) {
            if (lhs != NULL && rhs != NULL) {
                return (lhs->bounds.y < rhs->bounds.y);
            }
        }
    } order_yPos;
};


#endif //INC_2DENGINE_GAMEOBJECTHANDLER_H
