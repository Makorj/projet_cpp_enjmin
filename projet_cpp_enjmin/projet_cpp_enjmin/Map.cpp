#include "Map.h"



Map::Map()
{
}

Map::Map(MapTile *newTile[])
{
	for (int i = 0; i < NUMBER_TILES; i++)
	{
		_tilesInGame[i] = newTile[i];
	}
}


Map::~Map()
{
	delete[] _tilesInGame;
}
