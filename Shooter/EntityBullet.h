#pragma once
#include "Entity.h"

class EntityBullet :
	public Entity {
public:
	EntityBullet();
	void update(float timeStep) override;
	void slowTick() override;
	void handleCollision(GameObject *other) override;
	~EntityBullet();
private:
	int speed = 750;
};