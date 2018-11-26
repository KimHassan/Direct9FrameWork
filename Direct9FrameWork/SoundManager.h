#pragma once
#include "singletonBase.h"

#include "inc\fmod.hpp"
#pragma comment(lib,"lib/fmodex_vc.lib")

using namespace FMOD;

struct SoundInfo
{
	Sound* sound;
	Channel* channel;

	SoundInfo()
	{
		sound = nullptr;
		channel = nullptr;
	}
};

class SoundManager :
	public singletonBase<SoundManager>
{
	System * system;

	map<string, SoundInfo> soundMap;

public:
	SoundManager();
	~SoundManager();

	HRESULT Init();

	void Update();
	void Destroy();
	void AddSound(string key, string fileName, bool bgm = false);

	bool isPause(string key);
	bool isPlay(string key);
	void Play(string key, float volume = 1.0f);
	void Stop(string key);
	void Pause(string key);
	void Resume(string key);

	UINT getLength(string key);
};

