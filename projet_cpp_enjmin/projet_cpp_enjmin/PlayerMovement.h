#pragma once
#include "MovementComponent.h"
#include "Direction.h";

class PlayerMovement : public MovementComponent
{
public:
	PlayerMovement();
	~PlayerMovement();

	Movement::Direction& Move() override;

private:
	//InputManager _playerInput
};

