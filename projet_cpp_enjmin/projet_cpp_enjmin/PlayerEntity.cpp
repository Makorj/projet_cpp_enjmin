#include "PlayerEntity.h"

//ENTITY__________________________________________________________________________________________

void PlayerEntity::UpdateEntity()
{
	_playerMovement->Move();
	//stocker la direction dans une variable et intérroger la map pour savoir si je peux effectuer ce mouvement
	//faire le traitement en fonction
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

