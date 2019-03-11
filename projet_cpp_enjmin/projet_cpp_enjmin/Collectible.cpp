#include "Collectible.h"
#include "Data.h"


void Collectible::UpdateEntity()
{
	//les collectibles n'ont pas besoin d'�tre update
}



//CONSTRUCTOR & DESTRUCTOR_________________________________________________________________________

Collectible::Collectible(int &x, int &y):Entity(x,y)
{
}

Collectible::~Collectible()
{
}


//ACCESSER & GETTER_______________________________________________________________________________

bool Collectible::getCollectible()
{
	//RECUPERATION DU COLLECTIBLE LORSQUE LE JOUEUR MARCHE SUR LA TUILE 
	Data::getInstance().GetGameMap()->GetTileAtPosition(&_posX, &_posY)->resetCollectible();
	return true;
}
