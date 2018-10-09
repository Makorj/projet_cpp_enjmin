#pragma once
#include "Direction.h";

class MovementComponent
{
public:
	MovementComponent();
	~MovementComponent();

	virtual Movement::Direction& Move() = 0;

protected:
	//DATA ACCESS

};

