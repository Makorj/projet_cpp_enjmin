#pragma once

class Data;

class GameManager
{
	static GameManager *singleton;

	Data *mapInfos;

public:
	GameManager();
	GameManager(Data *newDatas);
	~GameManager();

	void Update();

	static GameManager *Instance()
	{
		if (!singleton)
			singleton = new GameManager();
		return singleton;
	}
};

