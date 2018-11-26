#include "stdafx.h"
#include "SceneManager.h"


SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

HRESULT SceneManager::Init()
{
	currentScene = NULL;
	return S_OK;
}
void SceneManager::Update()
{
	if (currentScene)
		currentScene->Update();
}

void SceneManager::Render()
{
	if (currentScene)
		currentScene->Render();
}

void SceneManager::Destroy()
{
	for (auto a : sceneList)
	{
		SAFE_DESTROY(a.second);
	}
	sceneList.clear();
}

Scene * SceneManager::AddScene(string key, Scene * scene)
{
	if (!scene)
		return NULL;

	sceneList.insert({ key,scene });
	return scene;
}

void SceneManager::ChangeScene(string key)
{
	auto changeScene = sceneList.find(key);

	if (changeScene == sceneList.end())
		return;
	if (changeScene->second == currentScene)
		return;
	changeScene->second->Init();
	if (currentScene)
		currentScene->Destroy();

	currentScene = changeScene->second;
}
