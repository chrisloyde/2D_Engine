#include "TilePool.h"

void TilePool::createTile(Texture *texture, int xPos, int yPos, int layer, SDL_Rect *clip) {
	struct Tile *tile = new struct Tile(texture, xPos, yPos, layer, clip);
	tiles[tile->layer].push_back(tile);
	++tilesInPool;
}

void TilePool::render(SDL_Renderer *renderer, int layer) {
	for (auto t : tiles[layer]) {
		if (cam != nullptr) {
			t->texture->render(renderer, t->xPos - cam->x, t->yPos - cam->y, t->clip);
		}
		else {
			t->texture->render(renderer, t->xPos, t->yPos, t->clip);
		}
	}
}

bool TilePool::isEmpty() {
	return (this->tilesInPool <= 0);
}

bool TilePool::isLayerEmpty(int layer) {
	return (tiles[layer].empty());
}

TilePool::~TilePool() {
	for (int l = 0; l < 10; l++) {
		for (std::vector<struct Tile*>::iterator it = tiles[l].begin(); it != tiles[l].end();) {
			if (*it != nullptr) {
				delete *it;
			}
			tiles[l].erase(it);
			it = tiles[l].begin();
		}
	}
}