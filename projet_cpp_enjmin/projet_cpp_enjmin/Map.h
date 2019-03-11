#pragma once
#include "MapTile.h";
#include "Data.h"

class Map
{
public:
	Map();

	Map(MapTile* newTile[]);

	~Map();

	MapTile * GetTileAtPosition(int * x, int * y);

private:
	MapTile _tilesInGame[8][8];
	const int NUMBER_TILES = 8;
};

