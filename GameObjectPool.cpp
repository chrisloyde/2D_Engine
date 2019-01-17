#include "GameObjectPool.h"

GameObjectPool* GameObjectPool::instance = 0;

GameObjectPool::GameObjectPool() {
	nLayers = 10;
}

GameObjectPool* GameObjectPool::getInstance() {
	if (instance == 0) {
		instance = new GameObjectPool();
	}
	return instance;
}

void GameObjectPool::add(GameObject &object, int layer) {	
	int key = recursiveFindValidKey(0,0);
	std::cout << "Creating object with Key [" << key << "] With ID: " << object.getId();
	std::cout << "\t\tMemory Address {" << &(object) << "}" << std::endl;
	pool[key] = &object;														// add object to map according to current key.
	keys[layer].push_back(struct SimpleGameObject(layer, key));					// add key to keys vector.
		
}

void GameObjectPool::update(float timeStep) {
	for (int l = 0; l < nLayers; l++) {
		int i = 0;
		for (auto k : keys[l]) {
			auto it = pool.find(k.key);
			if (it != pool.end()) {
				it->second->update(timeStep);									// update game object
				keys[l][i].yAxis = it->second->bounds.y;
			}
			i++;
		}
	}

	handleCollisions();

	for (int l = 0; l < nLayers; l++) {
		std::sort(keys[l].begin(), keys[l].end(), orderByYPos);					// sort objects by y axis.
	}
}

void GameObjectPool::tick() {
	int i = 0;
	for (int l = 0; l < nLayers; l++) {
		i = 0;
		for (auto k : keys[l]) {
			auto it = pool.find(k.key);
			if (it != pool.end()) {
				it->second->tick();
			}
			++i;
		}
	}
}

void GameObjectPool::handleCollisions() {
	std::vector<struct CollisionObject> colliders;
	for (int l = 0; l < nLayers; l++) {
		for (auto k : keys[l]) {
			auto it = pool.find(k.key);
			if (it != pool.end()) {
				SDL_Rect rect = it->second->bounds;
				colliders.push_back(CollisionObject(rect.x, rect.y, rect.w, rect.h, k.key));
			}
		}
	}
	for (int i = 0; i < colliders.size(); i++) {
		for (int j = i + 1; j < colliders.size(); j++) {
			if (GameObject::checkCollision(colliders.at(i).bounds, colliders.at(j).bounds)) {
				int keyA, keyB;
				keyA = colliders.at(i).key;
				keyB = colliders.at(j).key;
				pool.find(keyA)->second->handleCollision(pool.find(keyB)->second);
				pool.find(keyB)->second->handleCollision(pool.find(keyA)->second);
			}
		}
	}
	colliders.clear();
}

std::vector<GameObject*>* GameObjectPool::getObjectsById(std::string id) {
	std::vector<GameObject*> *objects = new std::vector<GameObject*>();
	for (int l = 0; l < nLayers; l++) {
		for (auto k : keys[l]) {
			auto it = pool.find(k.key);
			if (it != pool.end()) {
				if (strcmp(it->second->getId(), id.c_str()) == 0) {
					objects->push_back(it->second);
				}
			}
		}
	}
	return objects;
}

void GameObjectPool::render(SDL_Renderer *renderer) {
	for (int l = 0; l < nLayers; l++) {

		/* render tile layer before objects. */
		if (tiles != nullptr) {
			if (!tiles->isEmpty()) {
				if (!tiles->isLayerEmpty(l)) {
					tiles->render(renderer, l);
				}
			}
		}

		std::vector<struct SimpleGameObject> j = keys[l];
		for (auto k : keys[l]) {
			auto it = pool.find(k.key);
			if (it != pool.end()) {
				pool.find(k.key)->second->render(renderer);
			}
		}
	}
}

void GameObjectPool::handleEvents(SDL_Event &e) {
	for (int l = 0; l < nLayers; l++) {
		for (auto k : keys[l]) {
			auto it = pool.find(k.key);
			if (it != pool.end()) {
				it->second->handleEvent(e);
			}
		}
	}
}

void GameObjectPool::clearPool(std::string preserveObjectId) {
	for (int l = 0; l < nLayers; l++) {
		for (auto k : keys[l]) {
			auto it = pool.find(k.key);
			if (it != pool.end()) {
				if (strcmp(preserveObjectId.c_str(), it->second->getId()) != 0) {
					it->second->flagged = true;
				}
			}
		}
	}
	removeFlagged();
}

void GameObjectPool::removeFlagged() {
	int i = 0;
	int key = 0;
	for (int l = 0; l < nLayers; l++) {
		for (std::vector<struct SimpleGameObject>::iterator it = keys[l].begin(); it != keys[l].end();) {
			key = it->key;
			auto pIt = pool.find(key);
			if (pIt != pool.end()) {
				if (pIt->second->flagged) {
					std::cout << "Deleting Object with Key [" << key << "] With ID: " << pIt->second->getId();
					std::cout << "\t\tMemory Address {" << &(*(pIt->second)) << "}" << std::endl;
					delete pIt->second;										// Free GameObject in pool.
					pool.erase(key);										// Erase GameObject space from pool.
					keys[l].erase(it);										// Erase integer from keys.
					it = keys[l].begin();									// reset iterators to iterate from beginning.
					i = 0;
				}
				else {
					++i;
					++it;
				}
			}
			else {
				break;
			}
		}
	}
}

int GameObjectPool::recursiveFindValidKey(int layer, int key) {
	if (layer > MAX_LAYERS) {											// Base case: once we reach the max number of layers, return the key since it's valid.
		return key;
	}

	int checkKey = key;													// Current key to check.
	for (auto k : keys[layer]) {
		for (auto k2 : keys[layer]) {									// Nested loop to find any available keys.
			if (checkKey == k2.key) {									// If a key is determined invalid, break and increment key.
				break;
			}
		}
		++checkKey;
	}
	return recursiveFindValidKey(layer+1, checkKey);					// Check if next layer contains key.	
}

GameObjectPool::~GameObjectPool() {
	for (int l = 0; l < nLayers; l++) {
		for (auto k : keys[l]) {
			pool[k.key]->flagged = true;								// Flag all GameObjects for removal.
		}

		removeFlagged();												// Remove all flagged GameObjects.
		keys[l].clear();
	}
	
	instance = 0;
}
