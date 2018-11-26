#include "stdafx.h"
#include "MainGame.h"


MainGame::MainGame()
{
	
	
}


MainGame::~MainGame()
{
}

void MainGame::Init()
{
	scene.push_back(new TestScene);
	for (auto a : scene)
		a->Init();
}
void MainGame::Update()
{
	for (auto a : scene)
		a->Update();
	//CAMERA->Update();
}

void MainGame::Render()
{
	for (auto a : scene)
		a->Render();
}