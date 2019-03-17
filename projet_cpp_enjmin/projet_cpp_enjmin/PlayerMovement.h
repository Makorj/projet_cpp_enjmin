#pragma once
#include "MovementComponent.h"
#include "Direction.h";
#include "InputManager.h"

class PlayerMovement : public MovementComponent
{
public:
	PlayerMovement();
	~PlayerMovement();

	Movement::Direction& Move(int* posX, int* posY) override;

	bool GetEscButton();

	InputManager & GetInputManager()
	{
		return *_playerInput;
	}

private:
	InputManager *_playerInput;
};

