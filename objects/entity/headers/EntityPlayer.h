#ifndef INC_2DENGINE_ENTITYPLAYER_H
#define INC_2DENGINE_ENTITYPLAYER_H


#include "../../../textures/Texture.h"
#include "../../headers/GameObject.h"

class EntityPlayer: public GameObject {
public:
    float yVel = 0;
    float xVel = 0;
    const int SPEED = 240;
    enum directions {north,south,east,west};

    EntityPlayer(int worldX, int worldY,int width, int height);
    void render(SDL_Renderer *renderer) override;
    void update(float timeStep);
    void handleEvent(SDL_Event& e, SDL_Rect camera) override;
    void handleCollision(GameObject *other) override;
    //float readDistance(GameObject *other) override;
    void move(float timeStep);
    void unMove(float timeStep);

    int getXPos(); // retrieves world position
    int getYPos(); // retrieves world position
private:
    float worldXPos, worldYPos;
    directions facing;
    float step;

};


#endif //INC_2DENGINE_ENTITYPLAYER_H
