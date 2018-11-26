#pragma once
#include "singletonBase.h"
class TimeManager :
	public singletonBase<TimeManager>
{
private:
	LPD3DXFONT font;

	bool isTimerStopped;

	INT64 ticksPerSecond;
	INT64 currentTime;
	INT64 lastTime;
	INT64 lastFPSUpdate;
	INT64 fpsUpdateInterval;

	UINT frameCount;
	float runningTime;
	float timeElapsed;
	float framePerSecond;
public:
	TimeManager();
	~TimeManager();

	void Init();
	void Update();
	void Render();
	void Start();
	void Stop();

	bool IsTimerStopped() { return isTimerStopped; }
	float FramePerSecond() { return framePerSecond; }
	float RunningTime() { return runningTime; }
	float TimeElapsed()
	{
		return isTimerStopped ? 0.0 : timeElapsed;
	}
};

