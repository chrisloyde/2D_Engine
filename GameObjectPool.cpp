#include "GameObjectPool.h"

GameObjectPool* GameObjectPool::instance = 0;

GameObjectPool::GameObjectPool() {
}

GameObjectPool* GameObjectPool::getInstance() {
	if (instance == 0) {
		instance = new GameObjectPool();
	}
	return instance;
}

void GameObjectPool::add(GameObject &object) {	
	int key = findValidKey();
	std::cout << "Creating object with Key [" << key << "] With ID: " << object.getId() << std::endl;
	pool[key] = &object;													// add object to map according to current key.
	keys.push_back(struct SimpleGameObject(key));							// add key to keys vector.
		
}

void GameObjectPool::update(float timeStep) {
	int i = 0;
	for (auto k : keys) {
		auto it = pool.find(k.key);
		if (it != pool.end()) {
			it->second->update(timeStep);									// update game object
			keys[i].yAxis = it->second->bounds.y;								// update simple game object with game objects new y position
		}
		++i;
	}

	int *chk;
	chk = handleCollisions();
	if (chk[0] != -1 && chk[1] != -1) {										// tell both GameObjects that they are colliding with eachother.
		pool.find(chk[0])->second->handleCollision(pool.find(chk[1])->second);
		pool.find(chk[1])->second->handleCollision(pool.find(chk[0])->second);
	}
	delete chk;																// free chk since collision has already been performed.

	std::sort(keys.begin(), keys.end(), orderByYPos);						// sort objects by y axis.
}

void GameObjectPool::tick() {
	for (auto k : keys) {
		auto it = pool.find(k.key);
		if (it != pool.end()) {
			it->second->tick();
		}
	}
}

int* GameObjectPool::handleCollisions() {
	for (int i = 0; i < keys.size(); i++) {
		for (int j = i + 1; j < keys.size(); j++) {
			if (GameObject::checkCollision(pool.find(keys[i].key)->second->bounds, pool.find(keys[j].key)->second->bounds)) {
				return new int[2]{ keys[i].key, keys[j].key };	// return 2 length int array of both GameObject's map key.
			}
		}
	}

	return new int[2]{ -1,-1 };												// This is returned when no GameObjects are colliding.
}

void GameObjectPool::render(SDL_Renderer *renderer) {
	for (auto k : keys) {
		pool.find(k.key)->second->render(renderer);
		//pool[k]->render(renderer);
	}
}

void GameObjectPool::handleEvents(SDL_Event &e) {
	for (auto k : keys) {
		pool.find(k.key)->second->handleEvent(e);
		//pool[k]->handleEvent(event);
	}
}

void GameObjectPool::removeFlagged() {
	int i = 0;
	int key = 0;
	for (std::vector<struct SimpleGameObject>::iterator it = keys.begin(); it != keys.end();) {
		key = keys[i].key;
		auto pIt = pool.find(key);
		if (pIt != pool.end()) {
			if (pIt->second->flagged) {
				std::cout << "Deleting Object with Key [" << key << "] With ID: " << pIt->second->getId() << std::endl;
				delete pIt->second;												// Free GameObject in pool.
				pool.erase(key);												// Erase GameObject space from pool.
				keys.erase(it);													// Erase integer from keys.
				it = keys.begin();												// reset iterators to iterate from beginning.
				i = 0;
			}
			else {
				++i;
				++it;
			}
		}
	}
}

int GameObjectPool::findValidKey() {
	if (keys.empty()) {
		return 0;
	}

	int checkKey = 0;							// Current key to check.
	bool validate;								// Key number is vald.
	for (auto k : keys) {
		validate = true;						// Key number is percieved as valid at the start of the loop.
		for (auto k2 : keys) {					// Nested loop to find any available keys.
			if (checkKey == k2.key) {			// If a key is determined invalid, mark validation as false, and move on to next number.
				validate = false;
				break;
			}
		}
		if (validate) {							// if the check key was not found in the pool, return it.
			return checkKey;
		}
		++checkKey;
	}
	return checkKey;							// If all keys are used up, then create a new one. (note since the end of the loop increments, we don't need to increment again here.
}

GameObjectPool::~GameObjectPool() {
	for (auto k : keys) {
		pool[k.key]->flagged = true;			// Flag all GameObjects for removal.
	}

	removeFlagged();							// Remove all flagged GameObjects.
	keys.clear();
	instance = 0;
}
