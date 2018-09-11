#ifndef INC_2DENGINE_ENTITYPLAYER_H
#define INC_2DENGINE_ENTITYPLAYER_H


#include "../../../textures/Texture.h"

class EntityPlayer {
public:
    float yVel = 0;
    float xVel = 0;
    const int SPEED = 160;
    enum directions {north,south,east,west};
    EntityPlayer(int worldX, int worldY);
    ~EntityPlayer();
    void init(SDL_Renderer *renderer, std::string path);
    void render(SDL_Renderer *renderer, SDL_Rect camera);
    void update(float timeStep);
    void handleEvent(SDL_Event& e);
    void move(float timeStep);

    int getXPos(); // retrieves world position
    int getYPos(); // retrieves world position
private:
    float worldXPos, worldYPos;
    directions facing;
    Texture texture;
};


#endif //INC_2DENGINE_ENTITYPLAYER_H
