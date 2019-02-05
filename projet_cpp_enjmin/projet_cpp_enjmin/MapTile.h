#pragma once
#include "Entity.h"
#include "Collectible.h"
class MapTile : public Entity
{

	bool _isEnd;
	int _wallHp; // 0 : pas de mur c'est une route, 1 : mur endommagé, 2 : mur de base

	Collectible* _collectible;
	Entity* _entityOnTile;

public:
	MapTile();
	~MapTile();

	void setWall(int val);
	void DamageWall();
	void setEnd();
	void addCollectible(Collectible* collect);
	void addEntity(Entity* newEntity);

	void resetCollectible();
	void resetEntity();

	void UpdateEntity() override;
};

