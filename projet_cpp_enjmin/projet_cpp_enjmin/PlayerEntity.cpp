#include "PlayerEntity.h"

//ENTITY__________________________________________________________________________________________

void PlayerEntity::UpdateEntity()
{
	Movement::Direction dir = _playerMovement->Move();
	//interroger la map pour savoir si je peux effectuer ce mouvement
	MapTile* concernedTile = Data::getInstance().GetGameMap()->GetTileAtPosition(&dir.xDisplacement, &dir.yDisplacement);
	//faire le traitement en fonction
	if (concernedTile == nullptr)
		//on essaie de bouger hors range du niveau
		return;
	
}

//CONSTRUCTOR & DESTRUCTOR_________________________________________________________________________

PlayerEntity::PlayerEntity()
{
	_playerMovement = new PlayerMovement();
}


PlayerEntity::~PlayerEntity()
{
	delete this;
}

//ACCESSER & GETTER_________________________________________________________________________

