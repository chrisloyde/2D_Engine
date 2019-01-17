#pragma once
#include "Texture.h"
#include <array>
#include <vector>
class TilePool {
public:
	TilePool() = default;
	void createTile(Texture *texture, int xPos, int yPos, int layer, SDL_Rect *clip);
	void render(SDL_Renderer *renderer, int layer = 0);
	bool isEmpty();
	bool isLayerEmpty(int layer);
	~TilePool();

	SDL_Rect *cam = nullptr;
protected:
private:
	struct Tile {
		Texture *texture;			// Tilesheet texture.
		int xPos;					// Where to render tile on screen.
		int yPos;					
		int layer;					// Layer tile is stored.
		SDL_Rect *clip;				// Where the tile is on tilesheet.

		Tile(Texture *texture, int xPos, int yPos, int layer, SDL_Rect *clip) {
			this->texture = texture;
			this->xPos = xPos;
			this->yPos = yPos;
			this->clip = clip;
			if (layer < 0) {
				this->layer = 0;
			}
			else if (layer > 9) {
				this->layer = 9;
			}
			else {
				this->layer = layer;
			}
		}
	};

	std::array<std::vector<struct Tile*>, 10> tiles;

	int tilesInPool = 0;
};