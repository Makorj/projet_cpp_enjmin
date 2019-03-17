#pragma once
#include "Map.h"

class Entity;

class Data
{
public:
	Data();
	~Data();

	static const std::string spriteSheetFilePath;

	static std::string LoadSpriteFromSpriteSheet(int id);
	void LoadMap(std::string mapFilePath, GraphicalEntity * gEntities);

	static Data& getInstance();

	Map* GetGameMap();

private:
	
	Entity * _entities[64];
	int nbEntity;
	Map* _gameMap;

	static Data* _instance;

};

