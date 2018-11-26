#include "stdafx.h"
#include "Player.h"


void Player::Init()
{
	
	img = IMAGEMANAGER->AddImage("player",L"Image\\player.png", D3DXCOLOR(1, 1, 1, 0.5));
	pos = D3DXVECTOR3(100, 100, 0);
	rc = RectMake(pos.x, pos.y, 100, 100);
	speed = 200;
	b = new BulletManager;
	b->Init(3);
}

void Player::Update()
{
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		pos.x -= speed * TIMER->TimeElapsed();
		img->updateFrameX();
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		pos.x += speed * TIMER->TimeElapsed();
		img->updateFrameX();
	}
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		pos.y -= speed * TIMER->TimeElapsed();
		//img->updateFrameX();
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		pos.y += speed * TIMER->TimeElapsed();
		//img->updateFrameX();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		b->Shoot(pos.x, pos.y, mousePos.x,mousePos.y);
	}
	b->Update();

}

void Player::Render()
{
	img->Render(pos.x, pos.y);
	b->Render();

}

void Player::Destroy()
{
}

Player::Player()
{
}


Player::~Player()
{
}

