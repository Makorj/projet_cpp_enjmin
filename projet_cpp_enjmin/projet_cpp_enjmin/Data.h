#pragma once
#include "Entity.h";
#include "Map.h";

class Data
{
public:
	Data();
	~Data();

private:
	//std::reference_wrapper<Entity> _entitiesInGame;
	Map* _gameMap;

};

