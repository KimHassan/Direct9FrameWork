#include "stdafx.h"
#include "Bullet.h"


void Bullet::Init(float _x, float _y,float _goX, float _goY)
{
	img = IMAGEMANAGER->AddImage("bullet", L"Image\\bullet.png", D3DXCOLOR(1, 1, 1, 1));

	pos.x = _x;
	pos.y = _y;

	startX = _x;
	startY = _y;

	isFire = false;
	angle = getAngle(_x, _y, _goX, _goY);
	speed = 200;

}

void Bullet::Update()
{
	//pos.x += 3;
	//pos.y += 3;
	pos.x += cosf(angle) * speed * TIMER->TimeElapsed();
	pos.y += -sinf(angle) * speed * TIMER->TimeElapsed();


	
}

void Bullet::Render()
{
	img->Render(pos.x, pos.y);
}

void Bullet::Destroy()
{
	img = NULL;
	delete img;
}

Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

void BulletManager::Init(int _max)
{
	max = _max;
}

void BulletManager::Update()
{
	//for (auto a : bm)
	//{
	//	a.Update();
	//}
	//for (int i = 0; i < bm.size(); i++)
	//{
	//	if(bm[i].isFire == true)
	//		bm[i].Update();
	//	if(bm[i].getDis() > 200)
	//	{
	//		bm[i].Destroy();
	//		bm.erase(bm.begin() + i);
	//	}
	//}
	//for (int i = 0; i < bm.size();)
	//{
	//	bm[i].Update();
	//	if (bm[i].getDis() > 200)
	//	{
	//		bm[i].Destroy();
	//		bm.erase(bm.begin() + i);
	//	}
	//	else
	//		i++;
	//}
	for (ibm = bm.begin(); ibm != bm.end();)
	{
		ibm->Update();
		if (ibm->getDis() > 200)
		{
			ibm->Destroy();
			ibm = bm.erase(ibm);
		}
		else ++ibm;
	}
	//for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	//{
	//	_viBullet->x += _viBullet->speed;
	//	_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
	//		_viBullet->bulletImage->getFrameWidth(),
	//		_viBullet->bulletImage->getFrameHeight());

	//	if (_range < getDistance(_viBullet->x, _viBullet->y, _viBullet->fireX, _viBullet->fireY))
	//	{
	//		SAFE_RELEASE(_viBullet->bulletImage);
	//		SAFE_DELETE(_viBullet->bulletImage);
	//		_viBullet = _vBullet.erase(_viBullet);
	//	}
	//	else ++_viBullet;

	//}
	
	

	if (KEYMANAGER->isOnceKeyDown('T'))
	{
		int a = bm.size();
		int b = 0;
	}
}

void BulletManager::Render()
{
	//for (auto a : bm)
	//{
	//	a.Render();
	//}
	for (int i = 0; i < bm.size(); i++)
	{
		bm[i].Render();

	}
}

void BulletManager::Destroy()
{
	for (auto a : bm)
	{
		a.Destroy();
	}
}

void BulletManager::Shoot(float _x, float _y, float _goX, float _goY)
{
	Bullet b;
	b.Init(_x, _y, _goX,_goY);
	bm.push_back(b);
	
}
