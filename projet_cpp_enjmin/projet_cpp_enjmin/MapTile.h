#pragma once
#include "Entity.h"
#include "Collectible.h"
class MapTile : public Entity
{

	bool _isEnd;
	bool _isWall;

	Collectible* _collectible;

public:
	MapTile();
	~MapTile();

	void setRoad();
	void setEnd();
	void addCollectible(Collectible* collect);

	void UpdateEntity() override;
};

