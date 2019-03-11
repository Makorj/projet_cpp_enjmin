#pragma once
#include "Entity.h"
#include "GhostMovement.h"
#include "MapTile.h"
#include "Data.h"

class GhostEntity :
	public Entity
{
public:
	GhostEntity();
	GhostEntity(int* x, int* y);
	~GhostEntity();

	void UpdateEntity() override;

private:
	GhostMovement* _ghostMovement;
};

