#include "Data.h"
#include <fstream>
#include <iostream>
#include "VirtualScreen.h"

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

	MapTile* current = nullptr;

	int i = 0, j = 0;
	while (!mapFile.eof() && i+j<64)
	{
		char tile;
		mapFile.get(tile);

		switch (tile)
		{
		case 'w':
		//WALL
			current = new MapTile();
			current->setWall(2);
			break;
		case 'r':
		//ROAD
			current = new MapTile();
			current->setWall(0);
			break;
		case 'f':
		//FRAYSE
			current = new MapTile();
			current->setWall(0);
			current->addCollectible(new Collectible());
			break;
		case 'g':
		//GHOST
			current = new MapTile();
			current->setWall(0);

			break;
		case 'e':
		//EXIT
			current = new MapTile();
			current->setEnd();
			current->setWall(0);
			break;
		case 'p':
		//PLAYER
			current = new MapTile();
			current->setWall(0);

			break;
		default:
			break;
		}

		if(current!=nullptr)
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

// LOADERS

std::string const Data::spriteSheetFilePath = "spritesheets.txt";

std::string Data::LoadSpriteFromSpriteSheet(int id)
{
	std::fstream spritesheetFile(spriteSheetFilePath.c_str(), std::ios::in);
	std::string map = "";

	if (!spritesheetFile.is_open())
	{
		VirtualScreen::debug("Unable to open spritesheet " + spriteSheetFilePath);
		return std::string();
	}

	bool found = false;
	int size = 0;
	int actualId = 0;
	std::string line;
	std::string sprite;

	while (!spritesheetFile.eof() && !found)
	{
		spritesheetFile >> line ;
		actualId = std::stoi(line);

		if (actualId == id)
		{
			spritesheetFile >> line;
			size = std::stoi(line);

			spritesheetFile >> line;
			size *= std::stoi(line);
	
			spritesheetFile >> line ;
			sprite = line;

			found = true;
		}
		else
		{
			spritesheetFile >> line;
			spritesheetFile >> line;
			spritesheetFile >> line;
		}
	}

	if (found)
		return sprite;
	else
		return std::string();
}
