#pragma once
#include "MapTile.h";

class Map
{
public:
	Map();

	Map(MapTile* newTile[]);

	~Map();

private:
	MapTile _tilesInGame[8][8];
	const int NUMBER_TILES = 8;
};

