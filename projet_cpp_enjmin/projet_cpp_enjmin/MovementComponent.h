#pragma once
#include "Direction.h";

class MovementComponent
{
public:
	MovementComponent();
	~MovementComponent();

	virtual Movement::Direction& Move(int* posX, int* posY) = 0;

protected:
	//DATA ACCESS

};

