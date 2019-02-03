#pragma once
#include "Map.h";

class Entity;

class Data
{
public:
	Data();
	~Data();

private:
	//std::reference_wrapper<Entity> _entitiesInGame;
	Entity * _montableau[64];
	Map* _gameMap;

	void LoadMap(std::string);

};

