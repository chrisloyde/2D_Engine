//
// Created by Chris on 9/9/2018.
//

#ifndef PLANETARYRESEARCHFACILITY_TEXTURE_H
#define PLANETARYRESEARCHFACILITY_TEXTURE_H

#include <iostream>
#include <cstdio>
#include <SDL_rect.h>
#include <string>
#include <SDL_render.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Texture {
public:
    Texture(); // constructor
    ~Texture(); // deallocates memory
    bool loadFromFile(SDL_Renderer *renderer, std::string path); // load image from path
    void free(); //deallocates texture
    void render(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip = nullptr); // renders texture at point
    bool loadFromRenderedText(SDL_Renderer *renderer,std::string textureText, TTF_Font *font, SDL_Color textColor);

    //getters
    int getWidth();
    int getHeight();

private:
    SDL_Texture *hTexture; // hardware texture
    int width;
    int height;

};


#endif //PLANETARYRESEARCHFACILITY_TEXTURE_H
