#pragma once
#include "Entity.h"

class Collectible : public Entity
{
	public:
		Collectible()=default;
		Collectible(int x, int y);
		~Collectible();

		bool getCollectible();
};

