#pragma once
#include "singletonBase.h"
class Device : public singletonBase<Device>
{
private:

	LPDIRECT3DDEVICE9 device;
	LPDIRECT3D9 d3d;
	LPDIRECT3DTEXTURE9 bgTexture;

public:
	Device();
	~Device();

	LPDIRECT3DDEVICE9 GetDevice() { return device; }
	LPDIRECT3DTEXTURE9 getTexture() { return bgTexture; }
	LPDIRECT3DTEXTURE9* getPtTexture() { return &bgTexture; }
	void Init();

	void Begin();
	void End();
};

