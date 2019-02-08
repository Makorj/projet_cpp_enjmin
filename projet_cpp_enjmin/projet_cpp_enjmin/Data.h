#pragma once
#include "Map.h";

class Entity;

class Data
{
public:
	Data();
	~Data();

	static const std::string spriteSheetFilePath;

	static std::string LoadSpriteFromSpriteSheet(int id);
private:
	//std::reference_wrapper<Entity> _entitiesInGame;
	Entity * _montableau[64];
	Map* _gameMap;

	void LoadMap(std::string);
};

