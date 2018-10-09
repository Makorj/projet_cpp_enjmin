#pragma once
#include "Entity.h"

class MapTile : public Entity
{
public:
	MapTile();
	~MapTile();

	void UpdateEntity() override;
};

