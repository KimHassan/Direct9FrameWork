#pragma once
#include "singletonBase.h"
#include "Scene.h"
class SceneManager :
	public singletonBase<SceneManager>
{
	Scene * currentScene;
	map<string, Scene*> sceneList;
public:
	SceneManager();
	~SceneManager();

	HRESULT Init();
	void Update();
	void Render();
	void Destroy();

	Scene* AddScene(string key, Scene * scene);
	void ChangeScene(string key);
};

