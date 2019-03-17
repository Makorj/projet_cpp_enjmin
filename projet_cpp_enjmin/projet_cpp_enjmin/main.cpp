#include <iostream>
#include <time.h>
#include <windows.h>
#include <stack>
#include <conio.h>
#include "Timer.h"
#include "View.h"
#include "Data.h"
#include "InputManager.h"
#include "PlayerEntity.h"

using namespace std;

int main()
{
	Timer t;
	View _view;
	//InputManager inputManager;

	PlayerEntity * playerTest= new PlayerEntity();

	Data* data = new Data();

	data->LoadMap("carte.txt", _view.getGraphicalEntities());

	_view.setData(data);

	t.start();
	while( ! playerTest->GetMovement().GetEscButton())
	{ 
		//playerTest->GetMovement().Move();

		_view.Update();
		_view.Render();

		//Sleep(33-t.getElapsedMs()); ça fait planter
	}

	return 0;
}