#include "stdafx.h"
#include "SoundManager.h"

#define MAXSOUND 15

SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
}

HRESULT SoundManager::Init()
{
	System_Create(&system);
	system->init(MAXSOUND, FMOD_INIT_NORMAL, 0);
	return S_OK;
}
void SoundManager::Update()
{
	system->update();
}

void SoundManager::AddSound(string key, string fileName, bool bgm)
{
	if (soundMap.count(key) > 0)
		return;

	SoundInfo info;


	if (bgm)
	{
		if (FAILED(system->createStream(fileName.c_str(), FMOD_LOOP_NORMAL,
			NULL, &info.sound)))
		{
			return;
		}
	}
	else
	{
		system->createSound(fileName.c_str(), FMOD_DEFAULT,
			NULL, &info.sound);
	}
	soundMap.insert({ key,info });
}

bool SoundManager::isPause(string key)
{
	auto a = soundMap.find(key);
	if (a != soundMap.end())
	{
		bool _isPause;
		a->second.channel->getPaused(&_isPause);

		return _isPause;
	}
	return false;
}

bool SoundManager::isPlay(string key)
{
	auto a = soundMap.find(key);
	if (a != soundMap.end())
	{
		bool _isPlay;
		a->second.channel->isPlaying(&_isPlay);
		return _isPlay;
	}
	return false;
}

void SoundManager::Play(string key, float volume)
{
	auto a = soundMap.find(key);
	if (a != soundMap.end())
	{
		system->playSound(FMOD_CHANNEL_FREE, a->second.sound,
			false, &a->second.channel);
	}
}

void SoundManager::Stop(string key)
{
	auto a = soundMap.find(key);
	if (a != soundMap.end())
	{
		a->second.channel->stop();
	}
}

void SoundManager::Pause(string key)
{
	auto a = soundMap.find(key);
	if (a != soundMap.end())
	{
		a->second.channel->setPaused(true);
	}
}

void SoundManager::Resume(string key)
{
	auto a = soundMap.find(key);
	if (a != soundMap.end())
	{
		a->second.channel->setPaused(false);
	}
}

void SoundManager::Destroy()
{
	for (auto a : soundMap)
	{
		a.second.sound->release();
	}
	system->release();
	system->close();
}