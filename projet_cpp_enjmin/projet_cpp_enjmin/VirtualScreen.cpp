#include "VirtualScreen.h"
#include <string>
#include <cstring>


VirtualScreen::VirtualScreen()
	: _handleOutput((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE)) 
{
	COORD dwBufferSize = { VSCREEN_WIDTH,VSCREEN_HEIGHT };
	COORD dwBufferCoord = { 0, 0 };
	SMALL_RECT rcRegion = { 0, 0, VSCREEN_WIDTH - 1, VSCREEN_HEIGHT - 1 };

	ReadConsoleOutput(_handleOutput, (CHAR_INFO *)_clearedVirtualScreenBuffer, dwBufferSize,
		dwBufferCoord, &rcRegion);

	CONSOLE_CURSOR_INFO lpConsoleCursorInfo;
	GetConsoleCursorInfo(_handleOutput, &lpConsoleCursorInfo);
	lpConsoleCursorInfo.bVisible = false;
	SetConsoleCursorInfo(_handleOutput, &lpConsoleCursorInfo);
	
	clear();
}


VirtualScreen::~VirtualScreen()
{
}


void VirtualScreen::draw(const GraphicalEntity & sprite, const int & coordX, const int & coordY)
{
	draw(sprite._spriteValues, sprite._spriteInfos, sprite._col, sprite._line, coordX, coordY);
}

void VirtualScreen::draw(const std::string& sprite, const CharInfo* spriteInfos, const int& width, const int& height, const int& coordX, const int& coordY)
{
	int indice = 0;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			indice = j + (width * i);
			_virtualScreenBuffer[i + coordY][j + coordX].Char.AsciiChar = sprite[indice];
			_virtualScreenBuffer[i + coordY][j + coordX].Attributes = spriteInfos[indice];
		}
	}
}

void VirtualScreen::draw(const char* sprite, int width, int height, int coordX, int coordY)
{	
	int indice = 0;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			indice = j + (width * i);
			_virtualScreenBuffer[i + coordY][j + coordX].Char.AsciiChar = sprite[indice];
		}
	}
}


void VirtualScreen::clear()
{
	for (int i = 0; i < VSCREEN_HEIGHT; i++)
	{
		for (int j = 0; j < VSCREEN_WIDTH; j++)
		{
			_virtualScreenBuffer[i][j].Attributes = _clearedVirtualScreenBuffer[i][j].Attributes;
			_virtualScreenBuffer[i][j].Char =_clearedVirtualScreenBuffer[i][j].Char;
		}
	}
}

void VirtualScreen::flip()
{
	COORD dwBufferSize = { VSCREEN_WIDTH,VSCREEN_HEIGHT };
	COORD dwBufferCoord = { 0, 0 };
	SMALL_RECT rcRegion = { 0, 0, VSCREEN_WIDTH - 1, VSCREEN_HEIGHT - 1 };

	WriteConsoleOutput(_handleOutput, (CHAR_INFO * )_virtualScreenBuffer, dwBufferSize,
		dwBufferCoord, &rcRegion);
}
