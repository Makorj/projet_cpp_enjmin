#pragma once
#include "MapTile.h";

class Map
{
public:
	Map();

	Map(MapTile *newTile[]);

	~Map();

private:
	MapTile* _tilesInGame[14400];
	const int NUMBER_TILES = 14400;
};

