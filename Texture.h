#pragma once

#include "ITexture.h"
#include <iostream>
#include <SDL_rect.h>
#include <SDL_image.h>

class Texture : public ITexture {
public:
    Texture();
    ~Texture() override;	
	bool loadFromFile(SDL_Renderer *renderer, std::string path) override;
    void free();															
	void render(SDL_Renderer *renderer, int posX, int posY) override;
    void render(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip);
    bool loadFromRenderedText(SDL_Renderer *renderer,std::string textureText, TTF_Font *font, SDL_Color textColor) override;		

    int getWidth();
    int getHeight();

private:
    //SDL_Texture *hTexture; // hardware texture
    int width;
    int height;

};

