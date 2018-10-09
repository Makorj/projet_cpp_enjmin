#include "Entity.h"
#include "GraphicalEntity.h"

//CONSTRUCTOR & DESTRUCTOR_________________________________________________________________________

Entity::Entity()
{
}

Entity::Entity(int &x, int &y): _posX(x),_posY(y)
{
}

//ACCESSER & GETTER_______________________________________________________________________________

int & Entity::getPosX()
{
	return _posX;
}

int & Entity::getPosY()
{
	return _posY;
}

GraphicalEntity& Entity::GetRenderer()
{
	return renderer;
}
