#include "MapTile.h"


void MapTile::UpdateEntity()
{

}

std::string MapTile::getStringType() const
{
	return _wallHp>0?"wallTaMere":"pasWall";
}

//CONSTRUCTOR & DESTRUCTOR_________________________________________________________________________

MapTile::MapTile()
	: _isEnd(false),
	_wallHp(0),
	_collectible(nullptr),
	_entityOnTile(nullptr)
{
}


MapTile::~MapTile()
{
}

//GETTER & SETTER_______________________________________________________________________________

void MapTile::setWall(int val)
{
	_wallHp = val;
}

void MapTile::DamageWall()
{
	if (_wallHp <= 0)
		return;
	_wallHp -= 1;
}

void MapTile::setEnd()
{
	_isEnd = true;
}

void MapTile::addCollectible(Collectible * collect)
{
	_collectible = collect;
}

void MapTile::addEntity(Entity* newEntity)
{
	_entityOnTile = newEntity;
}

void MapTile::resetCollectible()
{
	_collectible = nullptr;
}

void MapTile::resetEntity()
{
	_entityOnTile = nullptr;
}

