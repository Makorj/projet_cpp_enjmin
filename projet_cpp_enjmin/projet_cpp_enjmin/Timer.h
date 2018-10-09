#pragma once
#include <windows.h>

class Timer
{
public:
	LARGE_INTEGER lastUpdateTime;
	LONGLONG freq;

	Timer();
	~Timer() = default;

	void start();
	void restart(LARGE_INTEGER& timeNow);

	float getElapsedSeconds();
	unsigned long getElapsedMs();
};


