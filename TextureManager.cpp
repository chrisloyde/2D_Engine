#include "TextureManager.h"

Texture* TextureManager::registerTexture(SDL_Renderer *renderer, std::string path) {
	Texture *tex = new Texture();

	if (tex->loadFromFile(renderer, path)) {
		return tex;
	}

	std::cerr << "Texture " << path << " was unable to register." << std::endl;
	return nullptr;

}