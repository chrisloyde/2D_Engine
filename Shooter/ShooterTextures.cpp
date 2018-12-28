#include "ShooterTextures.h"

Texture* ShooterTextures::TEXTURE_PLAYER;
Texture* ShooterTextures::TEXTURE_BULLET;

ShooterTextures::ShooterTextures(SDL_Renderer *r) {
	TEXTURE_PLAYER = TextureManager::registerTexture(r, "Shooter/sprites/gunman.png");
	TEXTURE_BULLET = TextureManager::registerTexture(r, "Shooter/sprites/bullet.png");
}