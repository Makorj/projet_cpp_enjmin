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

	bool* getIsEnd()
	{
		return &_isEnd;
	}

	bool isWall()
	{
		return (_wallHp > 0);
	}

	int* getWallHp()
	{
		return &_wallHp;
	}

	Collectible* getCollectibleOnTile()
	{
		return _collectible;
	}

	Entity* getEntityOnTile()
	{
		return _entityOnTile;
	}

	void resetCollectible();
	void resetEntity();

	void UpdateEntity() override;

	std::string getStringType() const;
};

