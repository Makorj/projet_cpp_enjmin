#pragma once
#include <Windows.h>
#include <string>
#include "GraphicalEntity.h"

class VirtualScreen
{
private:

	static const int VSCREEN_HEIGHT = 90;
	static const int VSCREEN_WIDTH = 90;

	
	HANDLE _handleOutput;

	CHAR_INFO _virtualScreenBuffer[VSCREEN_HEIGHT][VSCREEN_WIDTH];

	CHAR_INFO _clearedVirtualScreenBuffer[VSCREEN_HEIGHT][VSCREEN_WIDTH];

public:
	VirtualScreen();
	~VirtualScreen();

	void draw(const GraphicalEntity& sprite, const int& coordX, const int& coordY);

	void draw(const std::string& sprite, const CharInfo& spriteInfo, const int& width, const int& height, const int& coordX, const int& coordY);
	void draw(const char* sprite, int width, int height, int coordX, int coordY);

	void clear();
	void flip();

#ifdef _DEBUG	
	static std::string debug_stream;
	static void debug(std::string debug_string);
#endif
};

