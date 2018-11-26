#include "stdafx.h"
#include "TimeManager.h"
using namespace std;

TimeManager::TimeManager()
{
}


TimeManager::~TimeManager()
{
}

void TimeManager::Init()
{
	isTimerStopped = true;
	currentTime = 0;
	lastTime = 0;
	lastFPSUpdate = 0;
	frameCount = 0;
	runningTime = 0;
	timeElapsed = 0;
	framePerSecond = 0;
	font = NULL;
	QueryPerformanceFrequency(
		(LARGE_INTEGER*)&ticksPerSecond);
	fpsUpdateInterval = ticksPerSecond >> 1;

	if (!isTimerStopped)
		assert(false);

	QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);
	isTimerStopped = false;

	
}

void TimeManager::Update()
{
	if (isTimerStopped)
		return;

	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	timeElapsed = (float)(currentTime - lastTime)
		/ (float)ticksPerSecond;
	runningTime += timeElapsed;

	frameCount++;
	if (currentTime - lastFPSUpdate >= fpsUpdateInterval)
	{
		float tempCurrentTime =
			(float)currentTime / (float)ticksPerSecond;
		float tempLastTime =
			(float)lastFPSUpdate / (float)ticksPerSecond;
		framePerSecond = (float)frameCount /
			(tempCurrentTime - tempLastTime);

		lastFPSUpdate = (INT64)currentTime;
		frameCount = 0;
	}

	lastTime = currentTime;
}

void TimeManager::Render()
{
	if (font == NULL)
	{
		D3DXFONT_DESC desc = { 0 };
		desc.Width = 20;
		desc.Height = 20;
		desc.CharSet = HANGUL_CHARSET;
		wstring str = L"µ¸À½Ã¼";

		wcscpy_s(desc.FaceName, str.c_str());

		D3DXCreateFontIndirect(DEVICE->GetDevice(), &desc, &font);
	}

	wstring str = L"";
	str = to_wstring((int)framePerSecond);

	RECT rect = { 0,5,100,25 };
	font->DrawText(NULL, str.c_str(), -1, &rect, DT_LEFT, 0xffffff00);

}

void TimeManager::Start()
{
	if (!isTimerStopped)
		assert(false);

	QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);
	isTimerStopped = false;
}

void TimeManager::Stop()
{
	if (isTimerStopped)
		assert(false);

	INT64 stopTime = 0;
	QueryPerformanceCounter((LARGE_INTEGER*) &stopTime);
	runningTime += (float)(stopTime - lastTime) / (float)ticksPerSecond;
	isTimerStopped = true;

}
