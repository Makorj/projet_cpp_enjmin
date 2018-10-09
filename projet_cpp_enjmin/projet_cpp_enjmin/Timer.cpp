#include "Timer.h"



Timer::Timer()
{
	QueryPerformanceCounter(&lastUpdateTime);
	LARGE_INTEGER li_freq;
	QueryPerformanceFrequency(&li_freq);
	freq = li_freq.QuadPart;
	freq /= 1000;
}

void Timer::start()
{
	QueryPerformanceCounter(&lastUpdateTime);
}

void Timer::restart(LARGE_INTEGER& timeNow)
{
	lastUpdateTime = timeNow;
}

float Timer::getElapsedSeconds()
{
	LARGE_INTEGER timeNow;
	QueryPerformanceCounter(&timeNow);
	LONGLONG elapsedLong = timeNow.QuadPart - lastUpdateTime.QuadPart;

	float elapsed = (float)((float)elapsedLong / (float)freq);
	elapsed /= 1000.0f;


	restart(timeNow);

	return elapsed;
}

unsigned long Timer::getElapsedMs()
{
	LARGE_INTEGER timeNow;
	QueryPerformanceCounter(&timeNow);
	LONGLONG elapsedLong = timeNow.QuadPart - lastUpdateTime.QuadPart;

	unsigned long elapsed = (unsigned long)((float)elapsedLong / (float)freq);

	restart(timeNow);

	return elapsed;
}
