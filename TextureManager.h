#pragma once

#include "Texture.h"
#include <string>

class TextureManager {
public:
	static Texture* registerTexture(SDL_Renderer *renderer, std::string path);
};