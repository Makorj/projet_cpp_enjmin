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
	if (_previousMovement != nullptr)
		dir = *_previousMovement;
	MapTile* concernedTile = Data::getInstance().GetGameMap()->GetTileAtPosition(&dir.xDisplacement, &dir.yDisplacement);

	return dir;
}
