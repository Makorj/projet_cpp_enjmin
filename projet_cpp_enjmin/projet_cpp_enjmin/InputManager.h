#pragma once

struct KB_INFO
{
	bool KEY_UP = false;
	bool KEY_DOWN = false;
	bool KEY_LEFT = false;
	bool KEY_RIGHT = false;

	bool ESCAPE = false;
};

class InputManager
{
private:
	static InputManager* _instance;

	KB_INFO _infos;

public:
	InputManager();
	~InputManager();

	static InputManager& getInstance();
	void updateKbEvents();
	const KB_INFO& getKbInfos();
	void resetInfos();
};

