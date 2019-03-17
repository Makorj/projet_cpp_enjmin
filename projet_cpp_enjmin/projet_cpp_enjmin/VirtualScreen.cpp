#include "VirtualScreen.h"
#include <string>
#include <cstring>
#include <time.h>

#ifndef _DEBUG
#define VirtualScreen::debug(x) Log::debug(x)
#endif


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


void VirtualScreen::draw(const GraphicalEntity* sprite, const int & coordX, const int & coordY)
{
	//draw(sprite->_spriteValues, sprite->_spriteInfos, sprite->_col, sprite->_line, coordX, coordY);

	int indice = 0;
	for (int i = 0; i < sprite->_col; ++i)
	{
		for (int j = 0; j < sprite->_line; ++j)
		{
			indice = j + (sprite->_line * i);
			_virtualScreenBuffer[i + coordY][j + coordX].Char.AsciiChar = sprite->_spriteValues[indice];
			_virtualScreenBuffer[i + coordY][j + coordX].Attributes = sprite->_spriteInfos;
		}
	}
}

void VirtualScreen::draw(const std::string& sprite, const CharInfo& spriteInfos, const int& width, const int& height, const int& coordX, const int& coordY)
{
	int indice = 0;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			_virtualScreenBuffer[i + coordY][j + coordX].Char.AsciiChar = sprite[indice];
			_virtualScreenBuffer[i + coordY][j + coordX].Attributes = spriteInfos;
			indice++;
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
	int t = time(nullptr);

	for (int i = 0; i < VSCREEN_HEIGHT; i++)
	{
		for (int j = 0; j < VSCREEN_WIDTH; j++)
		{
			_virtualScreenBuffer[i][j].Attributes = t % 2 == 0 ? 0x0040 : 0x0040 + 0x0080;//_clearedVirtualScreenBuffer[i][j].Attributes;
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

std::string VirtualScreen::debug_stream = "";

void VirtualScreen::debug(std::string debug_string)
{
	std::string separtion_str = " | ";

	if (debug_stream.size() + debug_string.size() + separtion_str.size() >= VSCREEN_WIDTH)
		debug_stream = debug_stream.substr(debug_string.size()+3) + separtion_str + debug_string;
	else
		debug_stream += separtion_str + debug_string;
}
