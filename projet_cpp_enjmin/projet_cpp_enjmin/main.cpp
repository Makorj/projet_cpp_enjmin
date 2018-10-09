#include <iostream>
#include <time.h>
#include <windows.h>
#include <stack>
#include <conio.h>
#include "Timer.h"
#include "View.h"
#include "InputManager.h"

using namespace std;

int main()
{
	Timer t;
	View _view;
	InputManager inputManager;

	t.start();
	while (inputManager.getKbInfos().ESCAPE != true)
	{
		inputManager.resetInfos();
		inputManager.updateKbEvents();

		_view.Update();
		_view.Render();

		//Sleep(33-t.getElapsedMs()); ça fait planter
	}

	return 0;
}