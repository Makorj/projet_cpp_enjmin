#pragma once
#include "VirtualScreen.h"
#include "GraphicalEntity.h"
#include "Entity.h"
#include <map>

class View
{
private:

	const static int MAX_GRAPHICAL_ENTITIES = 10;

	//GraphicalMap _graphicalMap;

	GraphicalEntity* _entities;
	char _nbEntities;

	std::map<GraphicalEntity*, Entity*> _entityMap;

	VirtualScreen _screen;

public:
	View();
	
	~View();

	/*GraphicalMap& getGraphicalMap() const;*/

	void Update();
	void Render();


};


