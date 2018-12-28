#pragma once

#include "../TextureManager.h"

class ShooterTextures {
public:
	static Texture* TEXTURE_PLAYER;
	static Texture* TEXTURE_BULLET;

	ShooterTextures(SDL_Renderer *r);
};