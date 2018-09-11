#ifndef INC_2DENGINE_ENTITYPLAYER_H
#define INC_2DENGINE_ENTITYPLAYER_H


#include "../../headers/UpdateAndRender.h"
#include "../../../textures/Texture.h"

class EntityPlayer: UpdateAndRender {
public:
    enum directions {north,south,east,west};
    EntityPlayer(int worldX, int worldY);
    ~EntityPlayer();
    void init(SDL_Renderer *renderer, std::string path);
    void render(SDL_Renderer *renderer, SDL_Rect camera);
    void update();
    void handleEvent(SDL_Event& e);
    void move(directions direction);

    int getXPos(); // retrieves world position
    int getYPos(); // retrieves world position
private:
    int worldXPos, worldYPos;
    directions facing;
    Texture texture;
};


#endif //INC_2DENGINE_ENTITYPLAYER_H
