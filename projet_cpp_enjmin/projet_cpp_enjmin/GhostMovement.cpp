#include "GhostMovement.h"



GhostMovement::GhostMovement()
{
}


GhostMovement::~GhostMovement()
{
}

Movement::Direction& GhostMovement::Move()
{
	Movement::Direction dir;
	dir.xDisplacement = 0;
	dir.yDisplacement = 0;
	return dir;
}
