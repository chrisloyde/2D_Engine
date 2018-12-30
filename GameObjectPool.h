#pragma once

#include <SDL.h>
#include <map>
#include <vector>
#include "GameObject.h"

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
	void add(GameObject &object);						// adds a GameObject to the pool.

	struct SimpleGameObject {
		int key;
		int yAxis;
		SimpleGameObject(int keyIn) {
			key = keyIn;
		}
	};

private:
	static GameObjectPool* instance;
	//int key;											// the current key.
	std::map<int, GameObject*> pool;					// object pool map, stores GameObject pointers.
	std::vector<struct SimpleGameObject> keys;					// vector which holds keys for object pool map.
	GameObjectPool();

	int* handleCollisions();							// returns an int array (length 2) which contains the map keys of the Game Objects collding.
	int findValidKey();


	struct order
	{
		bool operator() (struct SimpleGameObject lhs, struct SimpleGameObject rhs) {
			//if (lhs != NULL && rhs != NULL) {
			return (lhs.yAxis > rhs.yAxis);
			//}
			return false;
		}
	} orderByYPos;
};

