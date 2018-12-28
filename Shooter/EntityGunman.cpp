#include "EntityGunman.h"


EntityGunman::EntityGunman() {
	numberOfFramesBeforeTick = 1;
	xVelocity = 0;
	speed = 250;
}

void EntityGunman::handleEvent(SDL_Event &e) {
	GameObject::handleEvent(e);

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
		case SDLK_z:
 			isShooting = true;
			break;
		case SDLK_LEFT:
			xVelocity -= speed;
			break;
		case SDLK_RIGHT:
			xVelocity += speed;
			break;
		}

	}
	if (e.type == SDL_KEYUP && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
		case SDLK_z:
			isShooting = false;
			break;
		case SDLK_LEFT:
			xVelocity += speed;
			break;
		case SDLK_RIGHT:
			xVelocity -= speed;
			break;
		}
	}
}

void EntityGunman::update(float timeStep) {
	GameObject::update(timeStep);

	xPos += xVelocity * timeStep;

	while (bounds.x + bounds.w >= worldWidthBound) {
		xPos -= speed * timeStep;
		setPos(xPos, yPos);
		setBounds(xPos, yPos, width, height, xOffset, yOffset);
	}

	if (bounds.x <= 0) {
		xPos += speed * timeStep;
		setPos(xPos, yPos);
		setBounds(xPos, yPos, width, height, xOffset, yOffset);
	}
}

void EntityGunman::slowTick(float timeStep) {
	GameObject::slowTick(timeStep);

	if (isShooting) {
		EntityBullet *bullet = new EntityBullet();
		bullet->addCamera(cam);
		bullet->setId("Bullet");
		bullet->setPos(xPos + (width/2) -1 , yPos-2);
		bullet->setBounds(xPos + (width / 2), yPos-2, 2, 2, 0, 0);
		bullet->init(Engine::getExistingInstance()->getRenderer(), ShooterTextures::TEXTURE_BULLET, new int[1]{ 1 }, 1, 2, 2);
		GameObjectPool::getInstance()->add(*bullet);
	}
}

void EntityGunman::setWorldWidth(int width) {
	worldWidthBound = width;
}

