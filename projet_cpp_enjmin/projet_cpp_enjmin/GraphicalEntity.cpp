#include "GraphicalEntity.h"


GraphicalEntity::GraphicalEntity(const std::string & sprite, const short & col, const short & line, short xAnchor, short yAnchor)
	: _spriteValues(new char[sprite.size()]),
	_col(col),
	_line(line),
	_xAnchor(xAnchor),
	_yAnchor(yAnchor)
{
	memcpy(_spriteValues, sprite.c_str(), sprite.size());
}

GraphicalEntity::~GraphicalEntity()
{
	delete[] _spriteValues;
}

