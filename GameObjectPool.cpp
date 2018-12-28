#include "GameObjectPool.h"

GameObjectPool* GameObjectPool::instance = 0;

GameObjectPool::GameObjectPool() {
	key = 0;
}

GameObjectPool* GameObjectPool::getInstance() {
	if (instance == 0) {
		instance = new GameObjectPool();
	}
	return instance;
}

void GameObjectPool::add(GameObject &object) {		
	pool[key] = &object;													// add object to map according to current key.
	keys.push_back(SimpleGameObject(key));									// add key to keys vector.
	++key;																	// increment key to prepare for the next object.
		
}

void GameObjectPool::update(float timeStep) {
	int i = 0;
	for (auto k : keys) {
		auto it = pool.find(k.getKey());
		if (it != pool.end()) {
			GameObject *temp = it->second;
			temp->update(timeStep);
			keys[i].update(temp->bounds.y);
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

int* GameObjectPool::handleCollisions() {
	for (int i = 0; i < keys.size(); i++) {
		for (int j = i + 1; j < keys.size(); j++) {
			//if (Tile::checkCollision(pool[keys[i]]->bounds, pool[keys[j]]->bounds)) {
			if (Tile::checkCollision(pool.find(keys[i].getKey())->second->bounds, pool.find(keys[j].getKey())->second->bounds)) {
				return new int[2]{ keys[i].getKey(), keys[j].getKey() };	// return 2 length int array of both GameObject's map key.
			}
		}
	}

	return new int[2]{ -1,-1 };												// This is returned when no GameObjects are colliding.
}

void GameObjectPool::render(SDL_Renderer *renderer) {
	for (auto k : keys) {
		pool.find(k.getKey())->second->render(renderer);
		//pool[k]->render(renderer);
	}
}

void GameObjectPool::handleEvents(SDL_Event &e) {
	for (auto k : keys) {
		pool.find(k.getKey())->second->handleEvent(e);
		//pool[k]->handleEvent(event);
	}
}

void GameObjectPool::removeFlagged() {
	int i = 0;
	for (std::vector<SimpleGameObject>::iterator it = keys.begin(); it != keys.end();) {
		if (pool.find(keys[i].getKey())->second->flagged) {
			std::cout << "Deleting " << pool[keys[i].getKey()]->id << std::endl;
			delete pool[keys[i].getKey()];									// Free GameObject in pool.
			pool.erase(keys[i].getKey());									// Erase GameObject space from pool.
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

GameObjectPool::~GameObjectPool() {
	for (auto k : keys) {
		pool[k.getKey()]->flagged = true;						// Flag all GameObjects for removal.
	}

	removeFlagged();											// Remove all flagged GameObjects.
	keys.clear();
	instance = 0;
}
