#pragma once
#include "MovementComponent.h"
class GhostMovement : public MovementComponent
{
public:
	GhostMovement(); 
	~GhostMovement();

	Movement::Direction& Move() override;
};

