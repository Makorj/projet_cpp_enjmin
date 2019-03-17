#pragma once
#include "MovementComponent.h"
#include "Data.h"
#include "MapTile.h"

class GhostMovement : public MovementComponent
{
public:
	GhostMovement(); 
	~GhostMovement();

	Movement::Direction& Move(int* posX, int* posY) override;

	void setPreviousMovement(Movement::Direction* dir)
	{
		_previousMovement = dir;
	}

private:
	int orientation; // 0�49 : horaire - 50�99 : trigo

	Movement::Direction* _previousMovement;
	void getFirstMovementDirection();
	void getNextMovementDirection();
};

