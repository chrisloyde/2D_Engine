#ifndef INC_2DENGINE_ENTITYPLAYER_H
#define INC_2DENGINE_ENTITYPLAYER_H


#include "../../../textures/Texture.h"
#include "../../headers/GameObject.h"

class EntityPlayer: public GameObject {
public:
    float yVel = 0;
    float xVel = 0;
    const int SPEED = 160;
    enum directions {north,south,east,west};

    EntityPlayer(int worldX, int worldY,int width, int height);
    void render(SDL_Renderer *renderer, SDL_Rect camera) override;
    void update(float timeStep) override;
    void handleEvent(SDL_Event& e, SDL_Rect camera) override;
    void move(float timeStep);

    int getXPos(); // retrieves world position
    int getYPos(); // retrieves world position
private:
    float worldXPos, worldYPos;
    directions facing;
};


#endif //INC_2DENGINE_ENTITYPLAYER_H
