#pragma once
#include "Entity.h"
#include "PlayerMovement.h"

class PlayerEntity : public Entity
{
public:
	PlayerEntity();
	~PlayerEntity();

	//Movement::Direction& Move() override;
	void UpdateEntity() override;

private:
	PlayerMovement * _playerMovement;
};

