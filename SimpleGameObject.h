#pragma once

/*
Holds minimal data on game objects.
*/
class SimpleGameObject
{
public:
	SimpleGameObject(int objectKey);
	void update(int y);
	int getKey() { return k; }
	int getY() { return y; }
	~SimpleGameObject();
private:
	int k;
	int y;
};

