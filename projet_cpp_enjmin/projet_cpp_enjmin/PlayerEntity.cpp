#include "PlayerEntity.h"

//ENTITY__________________________________________________________________________________________

void PlayerEntity::UpdateEntity()
{
	Movement::Direction dir = _playerMovement->Move(&_posX,&_posY);
	int xPos = _posX + dir.xDisplacement;
	int yPos = _posY + dir.yDisplacement;
	MapTile* concernedTile = Data::getInstance().GetGameMap()->GetTileAtPosition(&xPos, &yPos);
	
	if ((concernedTile == nullptr) || (concernedTile->getEntityOnTile()!=nullptr))
		//on essaie de bouger hors range du niveau ou dans un ennemis
		return;
	if (concernedTile->isWall())
	{
		//on tape dans un mur
		concernedTile->DamageWall();
		return;
	}
	Data::getInstance().GetGameMap()->GetTileAtPosition(&_posX, &_posY)->addEntity(nullptr);
	_posX += dir.xDisplacement;
	_posY += dir.yDisplacement;
	Data::getInstance().GetGameMap()->GetTileAtPosition(&_posX, &_posY)->addEntity(this);
	if (concernedTile->getCollectibleOnTile() != nullptr)
	{
		//recuperation du collectible si il y a sur la case ou je bouge
		concernedTile->getCollectibleOnTile()->getCollectible();
		frayse++;
	}
	if (*concernedTile->getIsEnd() == true)
	{
		//NIVEAU SUIVANT
	}
}

//CONSTRUCTOR & DESTRUCTOR_________________________________________________________________________

PlayerEntity::PlayerEntity()
{
	_playerMovement = new PlayerMovement();
	frayse = 0;
}

PlayerEntity::PlayerEntity(int*x, int*y)
{
	_posX = *x;
	_posY = *y;
	_playerMovement = new PlayerMovement();
	frayse = 0;
}


PlayerEntity::~PlayerEntity()
{
	delete this;
}

//ACCESSER & GETTER_________________________________________________________________________

