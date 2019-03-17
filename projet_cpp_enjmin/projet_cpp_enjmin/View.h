#pragma once
#include "VirtualScreen.h"
#include "GraphicalEntity.h"
#include "Entity.h"
#include <map>

class Data;

class View
{
private:

	const static int MAX_GRAPHICAL_ENTITIES = 10;

	GraphicalEntity* _entities;
	char _nbEntities;

	std::map<GraphicalEntity*, Entity*> _entityMap;

	VirtualScreen _screen;
	Data* _data;

	void DrawMap();

public:
	View();
	
	~View();

	GraphicalEntity* getGraphicalEntities();

	void Update();
	void Render();

	void setData(Data* data);


};


