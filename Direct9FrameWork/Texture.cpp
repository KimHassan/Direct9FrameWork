#include "stdafx.h"
#include "Texture.h"


Texture::Texture()
{
}


Texture::~Texture()
{
}

HRESULT Texture::Init(wstring str,D3DCOLOR _color)
{
	D3DXIMAGE_INFO pImgInf;

	if (FAILED(D3DXCreateTextureFromFileEx(
		DEVICE->GetDevice(),
		str.c_str(),
		D3DX_DEFAULT,//가로크기
		D3DX_DEFAULT,//세로크기
		1,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		0x0000001,
		0x0000001,
		0x00FFFFFF,
		&pImgInf,
		NULL,
		&dxTexture
	)))
	{
		MessageBox(NULL, str.c_str(), L"Error", 0);
		return E_FAIL;
	}
	if (FAILED(D3DXCreateSprite(DEVICE->GetDevice(), &sprite)))
	{
		return E_FAIL;
	}

	frameX = 0;
	frameY = 0;
	maxFrameX = 0;
	maxFrameY = 0;
	color = _color;

	return S_OK;
}

HRESULT Texture::Init(wstring str,int _maxFrameX,int _maxFrameY, D3DCOLOR _color)
{
	D3DXIMAGE_INFO pImgInf;



	if (FAILED(D3DXCreateTextureFromFileEx(
		DEVICE->GetDevice(),
		str.c_str(),
		D3DX_DEFAULT_NONPOW2,//가로크기
		D3DX_DEFAULT_NONPOW2,//세로크기
		1,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		0x0000001,
		0x0000001,
		0x00FFFFFF,
		&pImgInf,
		NULL,
		&dxTexture
	)))
	{
		MessageBox(NULL, str.c_str(), L"Error", 0);
		return E_FAIL;
	}
	if (FAILED(D3DXCreateSprite(DEVICE->GetDevice(), &sprite)))
	{
		return E_FAIL;
	}
	frameX = 0;
	frameY = 0;
	maxFrameX = _maxFrameX;
	maxFrameY = _maxFrameY;
	color = _color;

	D3DSURFACE_DESC desc;
	dxTexture->GetLevelDesc(0, &desc);

	width = desc.Width / _maxFrameX + 1;
	height = desc.Height / _maxFrameY + 1;

	return S_OK;
}

void Texture::Render(float x, float y)
{
	if (DEVICE->GetDevice() == NULL)
		return;

	//D3DXMATRIX ,mat, matS, matR, matT;
	//D3DXMatrixScalmatWorlding

	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 pos(x, y, 0);
	sprite->Draw(dxTexture, NULL, NULL, &pos, color);

	sprite->End();

}

void Texture::frameRender(float x, float y)
{
	if (DEVICE->GetDevice() == NULL)
		return;

	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rt = { frameX * width, frameY * height, (frameX + 1) * width, (frameY + 1) * height };

	D3DXVECTOR3 pos(x, y, 0);
	sprite->Draw(dxTexture, &rt, NULL, &pos, color);

	sprite->End();

}

void Texture::Destroy()
{
	SAFE_RELEASE(sprite);
	SAFE_RELEASE(dxTexture);

	SAFE_DELETE(sprite);
	SAFE_DELETE(dxTexture);
}

void Texture::updateFrameX()
{
	frameX++;
	if (frameX >= maxFrameX)
	{
		frameX = 0;
	}
}

void Texture::updateFrameY()
{
	frameY++;
	if (frameY > maxFrameY)
	{
		frameY = 0;
	}
}
