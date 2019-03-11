#include "Map.h"



Map::Map()
{
}

Map::Map(MapTile* newTile[])
{
	for (int i = 0; i < NUMBER_TILES; i++)
	{
		for(int j = 0 ; j < NUMBER_TILES; j++)
			_tilesInGame[i][j] = newTile[i][j];
	}
}

Map::~Map()
{
	delete[] _tilesInGame;
}

MapTile * Map::GetTileAtPosition(int * x, int * y)
{
	if (*x >= NUMBER_TILES || *y >= NUMBER_TILES)
		return nullptr;
	return &_tilesInGame[*x][*y];
}
