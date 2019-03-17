#pragma once
#include <string>
#include "CharInfo.h"


class VirtualScreen;

class GraphicalEntity
{
private:
	
	friend VirtualScreen;

	char _spriteValues[25];
	CharInfo _spriteInfos;
	
	short _col;
	short _line;

	short _xAnchor;
	short _yAnchor;

public:
	GraphicalEntity();
	GraphicalEntity(const std::string& sprite, const short& col, const short& line, short xAnchor=0, short yAnchor=0);
	GraphicalEntity(const std::string& sprite, CharInfo spriteInfo, const short& col, const short& line, short xAnchor = 0, short yAnchor = 0);

	GraphicalEntity(const GraphicalEntity&);
	GraphicalEntity& operator=(const GraphicalEntity&);
	~GraphicalEntity();
};

