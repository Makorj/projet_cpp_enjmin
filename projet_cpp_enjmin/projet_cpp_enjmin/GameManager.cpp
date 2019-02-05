#include "GameManager.h"

//initialisation du singleton 
GameManager *GameManager::_instance = nullptr;

GameManager::GameManager()
{
}

GameManager::GameManager(Data *newDatas)
{
	mapInfos = newDatas;
}


GameManager::~GameManager()
{
	if (_instance != nullptr && _instance != this)
		delete this;
}

GameManager & GameManager::getInstance()
{
	if (!_instance)
		_instance = new GameManager();
	return *_instance;
}



void GameManager::Update()
{
}
