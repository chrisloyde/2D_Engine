#pragma once
#include "Entity.h"
#include "EntityBullet.h"
#include "ShooterTextures.h"
#include "../Engine.h"
#include "../GameObjectPool.h"

class EntityGunman :
	public Entity {
public:
	EntityGunman();
	void handleEvent(SDL_Event &e) override;
	void update(float timeStep) override;
	void slowTick() override;
	void setWorldWidth(int width);
private:
	bool isShooting = false;
	int xVelocity;
	int speed;
	int worldWidthBound;
};