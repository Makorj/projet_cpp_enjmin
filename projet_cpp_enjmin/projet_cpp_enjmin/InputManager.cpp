#include "InputManager.h"
#include <Windows.h>
#include <vector>
#include <iostream>

InputManager* InputManager::_instance = nullptr;

InputManager::InputManager()
{
	if (_instance == nullptr)
	{
		_instance = this;
	}
	else if (_instance != this)
	{
		delete this;
	}
}


InputManager::~InputManager()
{
	if (_instance != nullptr && _instance != this)
		delete this;
}

InputManager & InputManager::getInstance()
{
	if (_instance == nullptr)
		_instance = new InputManager();
	return *_instance;
}
void InputManager::updateKbEvents()
{
	_infos.ESCAPE = GetAsyncKeyState(VK_ESCAPE);

	_infos.KEY_RIGHT = GetAsyncKeyState(VK_RIGHT);
	_infos.KEY_LEFT = GetAsyncKeyState(VK_LEFT);
	_infos.KEY_UP = GetAsyncKeyState(VK_UP);
	_infos.KEY_DOWN = GetAsyncKeyState(VK_DOWN);

}

const KB_INFO & InputManager::getKbInfos()
{
	return _infos;
}

void InputManager::resetInfos()
{
	_infos = std::move(KB_INFO());
}
