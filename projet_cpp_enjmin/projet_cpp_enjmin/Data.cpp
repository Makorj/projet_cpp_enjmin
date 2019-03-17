#include "Data.h"
#include <fstream>
#include <iostream>
#include "VirtualScreen.h"
#include "PlayerEntity.h"
#include "Map.h"
#include "GhostEntity.h"

Data::Data()
	: nbEntity(0)
{
}


Data::~Data()
{
}

void Data::LoadMap(std::string mapFilePath, GraphicalEntity* gEntities) {

	std::ifstream mapFile(mapFilePath.c_str(), std::ios::in);
	std::string lines = "";
	std::string map = "";

	if (!mapFile.is_open())
	{
		VirtualScreen::debug("Unable to open mapfile " + mapFilePath);
		std::cerr << "Unable to open mapfile " + mapFilePath << std::endl;
		return;
	}

	while (!mapFile.eof())
	{
		mapFile >> lines;
		map += lines;
	}

	/*MapTile*** mapTileTmp = new MapTile**[8];

	for (int i = 0; i < 8; i++)
	{
		mapTileTmp[i] = new MapTile*[8];
	}*/

	MapTile* current = nullptr;

	MapTile test[8][8];

	int i = 0, j = 0, k = 0;
	// 7*7 -> (8 cases - 1) * (8 cases - 1) car le tableau commence a zero et la case max en est en i=j=7
	while (i*j<(7*7)+1 && k < map.size())
	{
		char tile;

		tile = map[k];
		k++;

		if (tile == ',' || tile == '\n')
			continue;

		switch (tile)
		{
		case 'w':
		//WALL
			current = new MapTile();
			current->SetRenderer(&(gEntities[1]));
			current->setWall(2);

			VirtualScreen::debug("Wall");
			break;
		case 'r':
		//ROAD
			current = new MapTile();
			current->SetRenderer(&(gEntities[0]));
			current->setWall(0);
			break;
		case 'f':
		//FRAYSE
			current = new MapTile();
			current->SetRenderer(&(gEntities[5]));
			current->setWall(0);
			current->addCollectible(new Collectible());
			break;
		case 'g':
		//GHOST
			current = new MapTile();
			current->setWall(0);
			current->SetRenderer(&(gEntities[3]));
			
			current->addEntity(new GhostEntity(&i, &j));

			break;
		case 'e':
		//EXIT
			current = new MapTile();
			current->SetRenderer(&(gEntities[4]));
			current->setEnd();
			current->setWall(0);
			break;
		case 'p':
		//PLAYER
			current = new MapTile();
			current->SetRenderer(&(gEntities[4]));
			current->setWall(0);

			current->addEntity(new PlayerEntity(&i, &j));

			break;
		default:
			break;
		}

		if (current != nullptr)
			//(mapTileTmp[i])[j] = current;
			test[i][j] = *current;
		
		current = nullptr;


		if (j >= 7)
		{
			j = 0;
			i++;
		}
		else 
		{
			j++;
		}
	}

	_gameMap = new Map(test);

	VirtualScreen::debug("CARTE LOADED");
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

Data* Data::_instance = nullptr;

Data& Data::getInstance()
{
	if (_instance == nullptr)
		_instance = new Data();
	return *_instance;
}

Map* Data::GetGameMap()
{
	return _gameMap;
}

