#include "stdafx.h"
#include "TestScene.h"


TestScene::TestScene()
{
}


TestScene::~TestScene()
{
}

void TestScene::Init()
{
	
	p = new Player;
	p->Init();
	//SOUNDMANAGER->AddSound("hateYou", "Sound\\music1.mp3",true);
	//SOUNDMANAGER->Play("hateYou");
	
}
void TestScene::Update()
{
	p->Update();

}

void TestScene::Render()
{
	
	p->Render();
}

void TestScene::Destroy()
{

}