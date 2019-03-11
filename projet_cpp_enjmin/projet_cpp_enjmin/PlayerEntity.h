#pragma once
#include "Entity.h"
#include "PlayerMovement.h"
#include "Data.h"

class PlayerEntity : public Entity
{
public:
	PlayerEntity();
	PlayerEntity(int*x, int*y);
	~PlayerEntity();

	void UpdateEntity() override;

	PlayerMovement & GetMovement()
	{
		return *_playerMovement;
	}

private:
	PlayerMovement * _playerMovement;
	int frayse;
};

