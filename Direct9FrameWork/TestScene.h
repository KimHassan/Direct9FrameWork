#pragma once
#include "Scene.h"
#include "Player.h"
class TestScene :
	public Scene
{
	Player *p;
	float x;
public:
	TestScene();
	~TestScene();
	void Init();
	void Update();
	void Render();
	void Destroy();
};

