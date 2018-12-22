#include "SimpleGameObject.h"



SimpleGameObject::SimpleGameObject(int objectKey) {
	k = objectKey;
	y = 0;
}

void SimpleGameObject::update(int nY) {
	y = nY;
}

SimpleGameObject::~SimpleGameObject()
{
}
