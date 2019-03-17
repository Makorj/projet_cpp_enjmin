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
	Movement::Direction dir = _ghostMovement->Move(&_posX,&_posY);
	int xPos = _posX + dir.xDisplacement;
	int yPos = _posY + dir.yDisplacement;
	if (dir.xDisplacement == 0 && dir.yDisplacement == 0)
		return;

	MapTile* concernedTile = Data::getInstance().GetGameMap()->GetTileAtPosition(&xPos, &yPos);

	//verifier qu'on touche pas le joueur 

	Data::getInstance().GetGameMap()->GetTileAtPosition(&_posX, &_posY)->addEntity(nullptr);
	_posX += dir.xDisplacement;
	_posY += dir.yDisplacement;
	Data::getInstance().GetGameMap()->GetTileAtPosition(&_posX, &_posY)->addEntity(this);
}
