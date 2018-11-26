#pragma once
#include "Object.h"
#include "Bullet.h"
class Player : public Object
{
	BulletManager *b;
	int speed;

public:
	
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();

	Player();
	~Player();
};

