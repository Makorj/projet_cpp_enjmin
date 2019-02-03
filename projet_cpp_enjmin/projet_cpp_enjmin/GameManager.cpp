#include "GameManager.h"

//initialisation du singleton 
GameManager *GameManager::singleton = nullptr;

GameManager::GameManager()
{
}

GameManager::GameManager(Data *newDatas)
{
	mapInfos = newDatas;
}


GameManager::~GameManager()
{
}

void GameManager::Update()
{
}
