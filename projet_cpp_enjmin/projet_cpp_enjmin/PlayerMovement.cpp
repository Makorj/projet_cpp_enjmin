#include "PlayerMovement.h"
#include "InputManager.h"



PlayerMovement::PlayerMovement()
{
	_playerInput = &InputManager::getInstance();
}


PlayerMovement::~PlayerMovement()
{
}

Movement::Direction& PlayerMovement::Move()
{
	Movement::Direction dir;
	dir.xDisplacement = 0;
	dir.yDisplacement = 0;
	_playerInput->resetInfos();
	_playerInput->updateKbEvents();
	if (_playerInput->getKbInfos().KEY_UP)
		dir.yDisplacement = 1;
	else if (_playerInput->getKbInfos().KEY_DOWN)
		dir.yDisplacement = -1;
	else if (_playerInput->getKbInfos().KEY_RIGHT)
		dir.xDisplacement = 1;
	else if (_playerInput->getKbInfos().KEY_LEFT)
		dir.xDisplacement = -1;
	return dir;
}

bool PlayerMovement::GetEscButton()
{
	_playerInput->resetInfos();
	_playerInput->updateKbEvents();
	return _playerInput->getKbInfos().ESCAPE;
}

