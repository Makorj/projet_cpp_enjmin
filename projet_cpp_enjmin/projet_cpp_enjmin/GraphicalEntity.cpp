#include "GraphicalEntity.h"
#include "VirtualScreen.h"


GraphicalEntity::GraphicalEntity() :
	_spriteValues(nullptr)
{
}

GraphicalEntity::GraphicalEntity(const std::string & sprite, const short & col, const short & line, short xAnchor, short yAnchor)
	: _spriteValues(new char[sprite.size()]),
	_spriteInfos(CharInfo::BG_BLUE),
	_col(col),
	_line(line),
	_xAnchor(xAnchor),
	_yAnchor(yAnchor)
{
	for (int i = 0; i < sprite.size(); i++)
	{
		_spriteValues[i] = sprite[i];
	}
}

GraphicalEntity::GraphicalEntity(const std::string & sprite, CharInfo spriteInfo, const short & col, const short & line, short xAnchor, short yAnchor)
	: _spriteValues(new char[sprite.size()]),
	_spriteInfos(spriteInfo),
	_col(col),
	_line(line),
	_xAnchor(xAnchor),
	_yAnchor(yAnchor)
{
	for (int i = 0; i < sprite.size(); i++)
	{
		_spriteValues[i] = sprite[i];
	}
}

GraphicalEntity::GraphicalEntity(const GraphicalEntity & copy)
	: _spriteValues(new char[copy._col * copy._line]),
	_spriteInfos(copy._spriteInfos),
	_col(copy._col),
	_line(copy._line),
	_xAnchor(copy._xAnchor),
	_yAnchor(copy._yAnchor)
{
	for (int i = 0; i < copy._col * copy._line; i++)
	{
		_spriteValues[i] = copy._spriteValues[i];
	}
}

GraphicalEntity & GraphicalEntity::operator=(const GraphicalEntity & cpy)
{
	if (_spriteValues != nullptr)
	{
		delete[] _spriteValues;
	}

	_spriteValues = new char[cpy._col * cpy._line];
	for (int i = 0; i < cpy._col * cpy._line; i++)
	{
		_spriteValues[i] = cpy._spriteValues[i];
	}

	_spriteInfos=(cpy._spriteInfos);
	_col=(cpy._col);
	_line=(cpy._line);
	_xAnchor =(cpy._xAnchor);
	_yAnchor = (cpy._yAnchor);


	return *this;
}

GraphicalEntity::~GraphicalEntity()
{
	if(_spriteValues != nullptr)
		delete[] _spriteValues;
}

