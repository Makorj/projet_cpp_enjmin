#pragma once
#include <string>
#include "CharInfo.h"

class VirtualScreen;

class GraphicalEntity
{
private:
	
	friend VirtualScreen;

	char* _spriteValues;
	CharInfo* _spriteInfos;
	
	short _col;
	short _line;

	short _xAnchor;
	short _yAnchor;

public:
	GraphicalEntity() = default;
	GraphicalEntity(const std::string& sprite, const short& col, const short& line, short xAnchor=0, short yAnchor=0);
	GraphicalEntity(const std::string& sprite, CharInfo* spriteInfo, const short& col, const short& line, short xAnchor = 0, short yAnchor = 0);

	~GraphicalEntity();
};

