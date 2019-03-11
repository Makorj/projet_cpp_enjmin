#pragma once
#include "MovementComponent.h"
#include "Data.h"
#include "MapTile.h"

class GhostMovement : public MovementComponent
{
public:
	GhostMovement(); 
	~GhostMovement();

	Movement::Direction& Move() override;

	void setPreviousMovement(Movement::Direction* dir)
	{
		_previousMovement = dir;
	}

private:
	Movement::Direction* _previousMovement;
};

