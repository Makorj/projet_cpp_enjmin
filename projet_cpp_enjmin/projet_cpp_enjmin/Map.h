#pragma once
#include "MapTile.h";

class Map
{
public:
	Map();

	Map(MapTile newTile[8][8]);

	~Map();

	MapTile * GetTileAtPosition(int * x, int * y);

	const int NUMBER_TILES = 8;
private:
	MapTile _tilesInGame[8][8];
};

