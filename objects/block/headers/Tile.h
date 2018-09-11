#ifndef INC_2DENGINE_TILE_H
#define INC_2DENGINE_TILE_H


class Tile {
public:
    enum tileTypes {
        tile_dirt, tile_grass, tile_water
    };
    bool isSolid;
    Tile(int x, int y, bool isSolid, tileTypes type);
    ~Tile();
    int getXPos();
    int getYPos();
    bool getSolid();
    tileTypes getType();
private:
    int xPos, yPos;
    tileTypes tType;
};


#endif //INC_2DENGINE_TILE_H
