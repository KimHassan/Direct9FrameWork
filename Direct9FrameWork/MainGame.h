#pragma once
#include "Scene.h"
#include "TestScene.h"
class MainGame
{
private:

	vector<Scene*> scene;
public:
	MainGame();
	~MainGame();

	void Init();
	void Update();
	void Render();
};

