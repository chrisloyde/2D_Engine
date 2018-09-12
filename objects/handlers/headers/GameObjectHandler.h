
#ifndef INC_2DENGINE_GAMEOBJECTHANDLER_H
#define INC_2DENGINE_GAMEOBJECTHANDLER_H

#include <vector>
#include "../../block/headers/GameObject.h"

class GameObjectHandler {
public:
    GameObjectHandler();
    ~GameObjectHandler();
    void update();
    void render(SDL_Renderer *r, SDL_Rect camera);
    void handleEvents(SDL_Event &e);
    void add(GameObject *o);
private:
    std::vector<GameObject> elements;
};


#endif //INC_2DENGINE_GAMEOBJECTHANDLER_H
