#include "Data.h"
#include <fstream>
#include <iostream>


Data::Data()
{
}


Data::~Data()
{
}

void Data::LoadMap(std::string mapFilePath){

	std::fstream mapFile(mapFilePath.c_str(), std::ios::in);
	std::string map = "";

	if (!mapFile.is_open())
	{
		std::cerr << "Unable to open mapfile " + mapFilePath << std::endl;
		return;
	}

	MapTile*** mapTileTmp = new MapTile**[8];

	for (int i = 0; i < 8; i++)
	{
		mapTileTmp[i] = new MapTile*[8];
	}

	MapTile* current;

	int i = 0, j = 0;
	while (!mapFile.eof() && i+j<64)
	{
		char tile;
		mapFile.get(tile);

		switch (tile)
		{
		case 'w':
			current = new MapTile();
			break;
		case 'r':
			current = new MapTile();
			current->setRoad();
			break;
		case 'f':
			current = new MapTile();
			current->setRoad();
			current->addCollectible(new Collectible());
			break;
		case 'g':
			current = new MapTile();
			current->setRoad();

			break;
		case 'e':
			current = new MapTile();
			current->setEnd();
			break;
		case 'p':
			current = new MapTile();
			current->setRoad();

			break;
		default:
			break;
		}

		(mapTileTmp[i])[j] = current;
		current = nullptr;


		if (j >= 8)
		{
			j = 0;
			i++;
		}
		else 
		{
			j++;
		}
	}

}