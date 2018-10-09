#include "PlayerMovement.h"



PlayerMovement::PlayerMovement()
{
}


PlayerMovement::~PlayerMovement()
{
}

Movement::Direction& PlayerMovement::Move()
{
	Movement::Direction dir;
	dir.xDisplacement = 0;
	dir.yDisplacement = 0;
	return dir;
}
