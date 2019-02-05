#pragma once

class Data;
       
class GameManager
{
	static GameManager *_instance;

	Data *mapInfos;

public:
	GameManager();
	GameManager(Data *newDatas);
	~GameManager();

	void Update();

	static GameManager & getInstance();
};

