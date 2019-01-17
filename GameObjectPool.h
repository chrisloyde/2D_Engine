#pragma once

#include <SDL.h>
#include <SDL_rect.h>
#include <map>
#include <vector>
#include <array>
#include "GameObject.h"
#include "TilePool.h"

/* inclusive of 0 */
#define MAX_LAYERS 9

class GameObjectPool
{
public:
	~GameObjectPool();
	static GameObjectPool* getInstance();				// Create or retrieve an existing instance of object pool.
	void update(float timestep);						// Sends updates to all objects in pool (dynamic updating).
	void tick();										// fixed number of updates per second.
	void render(SDL_Renderer *renderer);				// Sends renders to all objects in pool.
	void handleEvents(SDL_Event &event);				// Sends events to all objects in the pool.

	void removeFlagged();								// remove and free memory of all flagged objects in pool.
	void add(GameObject &object, int layer);			// adds a GameObject to the pool.
	void clearPool(std::string preserveObjectId);		// Removes every object in the pool, except those with id matching paramter.
	std::vector<GameObject*>* getObjectsById(std::string id);

	/* SimpleGameObject: Stores essential information about objects, without storing entire object. */
	struct SimpleGameObject {
		int key;										// key to find object in map.
		int yAxis;										// objects y axis.
		int layer;										// objects layer.

		/* Constructor to easily create SimpleGameObjects. */
		/* Y-axis is not included because that should be managed elsewhere. */
		SimpleGameObject(int layerIn, int keyIn) {
			layer = layerIn;

			if (layer > MAX_LAYERS) {
				layer = MAX_LAYERS;						// ensure layer never goes over max.
			}
			if (layer < 0) {
				layer = 0;								// ensure layer never goes under min.
			}

			key = keyIn;
			yAxis = 0;
		}
	};

	/*CollisionObject: Stores essential information about object collisions, without storing entire objects.*/
	struct CollisionObject {
		SDL_Rect bounds;
		int key;

		/* Constructor to easily create CollisionObjects.*/
		CollisionObject(int x, int y, int w, int h, int keyIn) {
			bounds.x = x;
			bounds.y = y;
			bounds.w = w;
			bounds.h = h;
			key = keyIn;
		}
	};

	TilePool *tiles = nullptr;

private:
	static GameObjectPool* instance;
	std::map<int, GameObject*> pool;							// Object pool map, stores GameObject pointers.
	std::array<std::vector<struct SimpleGameObject>, 10> keys;	// 10 size array containing vectors of SimpleGameObjects, used for layers.
	GameObjectPool();

	void handleCollisions();									// Returns an int array (length 2) which contains the map keys of the Game Objects collding.
	int recursiveFindValidKey(int layer, int key);				// Recursivley search through layers to find any valid keys.
	int nLayers;


	struct order
	{
		bool operator() (struct SimpleGameObject lhs, struct SimpleGameObject rhs) {
			return (lhs.yAxis < rhs.yAxis);
		}
	} orderByYPos;
};

