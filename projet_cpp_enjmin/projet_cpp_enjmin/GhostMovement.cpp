#include "GhostMovement.h"




GhostMovement::GhostMovement()
{
	orientation = rand() % 100;
	getFirstMovementDirection();
}


GhostMovement::~GhostMovement()
{
}

Movement::Direction& GhostMovement::Move(int* posX, int* posY)
{
	Movement::Direction dir;
	MapTile* concernedTile;
	int indexDir = 0;

	while (indexDir < 4)
	{
		dir = *_previousMovement;
		int xPos = *posX + dir.xDisplacement;
		int yPos = *posY + dir.yDisplacement;
		concernedTile = Data::getInstance().GetGameMap()->GetTileAtPosition(&xPos, &yPos);
		if ((concernedTile==nullptr)||(concernedTile->getWallHp() > 0))
		{
			//si on essaie de bouger dans un mur
			getNextMovementDirection();
			indexDir++;
			if (indexDir > 3)
			{
				//si on a tout testé mais qu'il n'y a pas de chemin possible
				dir.xDisplacement = 0;
				dir.yDisplacement = 0;
			}
		}
		else
		{
			indexDir = 4;
		}
	}
	return dir;
}

void GhostMovement::getFirstMovementDirection()
{
	Movement::Direction dir;
	dir.xDisplacement = 0;
	dir.yDisplacement = 0;
	int dirRand = rand() % 4;
	switch (dirRand)
	{
		case 0:
			dir.yDisplacement = 1;
			break;
		case 1:
			dir.xDisplacement = 1;
			break;
		case 2:
			dir.yDisplacement = -1;
			break;
		case 3:
			dir.xDisplacement = -1;
			break;
	}
	*_previousMovement = dir;
}

void GhostMovement::getNextMovementDirection()
{
	if (orientation < 50)
	{
		//horaire
		if (_previousMovement->yDisplacement == 1)
		{
			//up
			_previousMovement->xDisplacement = 1;
			_previousMovement->yDisplacement = 0;
		}
		else if (_previousMovement->xDisplacement == 1)
		{
			//right
			_previousMovement->xDisplacement = 0;
			_previousMovement->yDisplacement = -1;
		}
		else if (_previousMovement->yDisplacement == -1)
		{
			//down
			_previousMovement->xDisplacement = -1;
			_previousMovement->yDisplacement = 0;
		}
		else if (_previousMovement->xDisplacement == -1)
		{
			//left
			_previousMovement->xDisplacement = 0;
			_previousMovement->yDisplacement = 1;
		}
	}
	else
	{
		//trigo
		if (_previousMovement->yDisplacement == 1)
		{
			//up
			_previousMovement->xDisplacement = -1;
			_previousMovement->yDisplacement = 0;
		}
		else if (_previousMovement->xDisplacement == -1)
		{
			//right
			_previousMovement->xDisplacement = 0;
			_previousMovement->yDisplacement = -1;
		}
		else if (_previousMovement->yDisplacement == -1)
		{
			//down
			_previousMovement->xDisplacement = 1;
			_previousMovement->yDisplacement = 0;
		}
		else if (_previousMovement->xDisplacement == 1)
		{
			//left
			_previousMovement->xDisplacement = 0;
			_previousMovement->yDisplacement = 1;
		}
	}
}
