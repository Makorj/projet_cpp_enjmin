#include <iostream>
#include <time.h>
#include <windows.h>
#include <stack>
#include "View.h"

using namespace std;

int main()
{

	View _view;

	while (true)
	{
		_view.Update();
		_view.Render();
		Sleep(33);
	}


	return 0;
}