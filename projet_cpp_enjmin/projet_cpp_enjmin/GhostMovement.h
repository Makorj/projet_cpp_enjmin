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
	int orientation; // 0à49 : horaire - 50à99 : trigo

	Movement::Direction* _previousMovement;
	void getFirstMovementDirection();
	void getNextMovementDirection();
};

