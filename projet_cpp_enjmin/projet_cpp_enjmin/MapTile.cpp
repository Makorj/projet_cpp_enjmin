#include "MapTile.h"


void MapTile::UpdateEntity()
{

}

//CONSTRUCTOR & DESTRUCTOR_________________________________________________________________________

MapTile::MapTile()
	: _isEnd(false),
	_isWall(true),
	_collectible(nullptr)
{
}


MapTile::~MapTile()
{
}

void MapTile::setRoad()
{
	_isWall = true;
}

void MapTile::setEnd()
{
	_isEnd = true;
}

void MapTile::addCollectible(Collectible * collect)
{
	_collectible = collect;
}

