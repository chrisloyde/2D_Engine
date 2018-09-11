//
// Created by Chris on 9/9/2018.
//

#ifndef PLANETARYRESEARCHFACILITY_TILEGROUND_H
#define PLANETARYRESEARCHFACILITY_TILEGROUND_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <cstdio>
#include <string>
#include "../../../Texture.h"
#include "../../../../objects/block/headers/Tile.h"

/*
 * TileRenderer is meant to be a controlling and managing class for importing a spritesheet
 * of multiple tile sprites and automating the requirements for rendering.
 * TileRenderer manages clipping the sprite sheet and rendering.
 *
 * TODO: allow row input to specify how many renderers per row so the program can clip in a 2D
 * TODO: space rather then a 1D space.
 */
class TileRenderer {
public:
   // enum tileTypes {tile_dirt, tile_grass, tile_water};
    TileRenderer(int numOfSprites, int spriteW, int spriteH);
    ~TileRenderer();
    void free();
    bool init(SDL_Renderer *renderer, std::string path);
    void generateClips();
    void renderTile(SDL_Renderer *renderer, SDL_Rect camera, Tile tile);
private:
    SDL_Texture *SDL_spriteSheet;
    Texture spriteSheet;
    SDL_Rect *clipStorage;
    int numOfSprites, spriteW, spriteH, rawW, rawH;

    void render(SDL_Renderer *renderer, SDL_Rect camera, int x, int y, Tile::tileTypes type);
};



#endif //PLANETARYRESEARCHFACILITY_TILEGROUND_H
