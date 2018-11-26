#pragma once
#include "Texture.h"
class Object
{
protected:
	Texture * img;
	D3DXVECTOR3 pos;
	RECT rc;
	
public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();

	Object();
	~Object();
};

