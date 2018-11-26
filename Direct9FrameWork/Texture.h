#pragma once
class Texture
{
private:

	LPD3DXSPRITE sprite;
	LPDIRECT3DTEXTURE9 dxTexture;
	D3DCOLOR color;

	int frameX;
	int frameY;
	int maxFrameX;
	int maxFrameY;
	int width;
	int height;

public:
	HRESULT Init(wstring str, D3DCOLOR _color);
	HRESULT Init(wstring str, int _maxFrameX, int _maxFrameY, D3DCOLOR _color);
	void Render(float x, float y);
	void frameRender(float x, float y);
	void Destroy();

	void setFrameX(int _frameX) { frameX = _frameX; }
	void setFrameY(int _frameY) { frameY = _frameY; }

	void updateFrameX();
	void updateFrameY();
	Texture();
	~Texture();
};

