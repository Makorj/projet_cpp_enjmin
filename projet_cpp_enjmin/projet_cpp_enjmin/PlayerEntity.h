#pragma once
#include "Entity.h"
#include "PlayerMovement.h"

class PlayerEntity : public Entity
{
public:
	PlayerEntity();
	~PlayerEntity();

	void UpdateEntity() override;

private:
	PlayerMovement * _playerMovement;
};

