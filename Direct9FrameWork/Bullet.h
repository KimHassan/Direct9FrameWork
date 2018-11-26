#pragma once
#include "Object.h"
class Bullet : Object
{

	float startX;
	float startY;
	int angle;
	int speed;
	
public:
	bool isFire;
	void Init(float _x, float _y, float _goX, float _goY);
	void Update();
	void Render();
	void Destroy();
	float getX() { return pos.x; }
	float getY() { return pos.y; }
	float getDis() { return getDistance(startX, startY, pos.x, pos.y); }
	Bullet();
	~Bullet();
};

class BulletManager
{
	vector<Bullet> bm;
	vector<Bullet>::iterator ibm;

	int max;
public:
	void Init(int _max);
	void Update();
	void Render();
	void Destroy();
	vector<Bullet> getBm() { return bm; }
	void Shoot(float _x, float _y, float _goX, float _goY);
};