#pragma once
#include "VirtualScreen.h"
#include "GraphicalEntity.h"

class View
{
private:

	const static int MAX_GRAPHICAL_ENTITIES = 10;

	//GraphicalMap _graphicalMap;
	GraphicalEntity* _entities;
	char _nbEntities;

	VirtualScreen _screen;

public:
	View();
	
	~View();

	/*GraphicalMap& getGraphicalMap() const;*/

	void Update();
	void Render();


};


