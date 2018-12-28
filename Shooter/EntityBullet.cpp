#include "EntityBullet.h"

EntityBullet::EntityBullet() {
	numberOfFramesBeforeTick = 100;
}

void EntityBullet::update(float timeStep) {
	GameObject::update(timeStep);

	yPos -= timeStep * speed;

	if (!Tile::checkCollision(bounds, *cam)) {
		flagged = true;								// flag for deletion if outside camera.
	}
}

void EntityBullet::slowTick(float timeStep) {
	GameObject::update(timeStep);
	flagged = true;							// flag for deletion.
}

void EntityBullet::handleCollision(GameObject *other) {
	if (strcmp(id.c_str(), other->id.c_str()) != 0) {
		printf("Collision: %s - %s\n", id.c_str(), other->id.c_str());
	}
}

EntityBullet::~EntityBullet() {
	gTexture = nullptr;
}

