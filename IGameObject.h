#pragma once

#include <string>
#include <SDL_render.h>
#include <SDL_events.h>

class IGameObject {
public:
	virtual ~IGameObject() {}

	virtual void update(float deltaTime) = 0;
	virtual void render(SDL_Renderer *renderer) = 0;
	virtual void tick() = 0;
	virtual void handleEvent(SDL_Event &e) = 0;
	virtual void setId(std::string id) = 0;
	virtual const char* getId() = 0;

protected:
	char id[64] = "null";
};