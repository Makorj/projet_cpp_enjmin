#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
	const SHORT SCREEN_WIDTH = 40;
	const SHORT SCREEN_HEIGHT = 20;

	HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
	COORD dwBufferCoord = { 0, 0 };
	SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	bool rouge = false;

	while (true)
	{

		ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
			dwBufferCoord, &rcRegion);

		for (int i = 0; i < SCREEN_HEIGHT; i++)
		{
			for (int j = 0; j < SCREEN_WIDTH; j++)
			{
				buffer[i][j].Char.AsciiChar = '0';

				if (rouge)
					buffer[i][j].Attributes = 0x0020 + 0x0080;
				else
					buffer[i][j].Attributes = 0x0040 + 0x0080;

			}
		}

		rouge != rouge;

		WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
			dwBufferCoord, &rcRegion);

		//Sleep(1);
	}


	int pomme;
	cin >> pomme;

	return 0;
}