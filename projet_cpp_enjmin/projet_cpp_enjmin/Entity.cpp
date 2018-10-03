#include "Entity.h"

Entity::Entity()
{
}

Entity::Entity(int x, int y)
{
	_posX = x;
	_posY = y;
}



int & Entity::getPosX()
{
	return _posX;
}

int & Entity::getPosY()
{
	return _posY;
}