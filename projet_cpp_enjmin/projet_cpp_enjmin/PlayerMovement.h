#pragma once
#include "MovementComponent.h"
#include "Direction.h";
#include "InputManager.h"

class PlayerMovement : public MovementComponent
{
public:
	PlayerMovement();
	~PlayerMovement();

	Movement::Direction& Move() override;

private:
	InputManager *_playerInput;
};

