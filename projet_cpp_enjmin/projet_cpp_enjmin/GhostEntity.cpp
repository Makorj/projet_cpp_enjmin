#include "GhostEntity.h"



GhostEntity::GhostEntity()
{
	_ghostMovement = new GhostMovement();
}

GhostEntity::GhostEntity(int*x, int*y)
{
	_posX = *x;
	_posY = *y;
	_ghostMovement = new GhostMovement();
}


GhostEntity::~GhostEntity()
{
}

void GhostEntity::UpdateEntity()
{
	Movement::Direction dir = _ghostMovement->Move();
	MapTile* concernedTile = Data::getInstance().GetGameMap()->GetTileAtPosition(&dir.xDisplacement, &dir.yDisplacement);

	Data::getInstance().GetGameMap()->GetTileAtPosition(&_posX, &_posY)->addEntity(nullptr);
	_posX += dir.xDisplacement;
	_posY += dir.yDisplacement;
	Data::getInstance().GetGameMap()->GetTileAtPosition(&_posX, &_posY)->addEntity(this);
}
