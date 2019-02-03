#pragma once
#include "Entity.h"
#include "Collectible.h"
class MapTile : public Entity
{

	bool _isEnd;
	bool _isWall;

	Collectible _collectible;

	

public:
	MapTile();
	~MapTile();


	void UpdateEntity() override;
};

