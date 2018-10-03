#include "Collectible.h"


void Collectible::UpdateEntity()
{
	//les collectibles n'ont pas besoin d'être update
}



//CONSTRUCTOR & DESTRUCTOR_________________________________________________________________________

Collectible::Collectible(int x, int y):Entity(x,y)
{
}

Collectible::~Collectible()
{
}


//ACCESSER & GETTER_______________________________________________________________________________

bool Collectible::getCollectible()
{
	//RECUPERATION DU COLLECTIBLE LORSQUE LE JOUEUR MARCHE SUR LA TUILE 
	return false;
}
