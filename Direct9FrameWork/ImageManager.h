#pragma once
#include "singletonBase.h"
#include "Texture.h"
class ImageManager :
	public singletonBase<ImageManager>
{
private:
	typedef map<string, Texture*>	mapImageList;
	typedef map<string, Texture*>::iterator mapImageIter;

private:
	mapImageList _mImageList;


public:
	HRESULT Init();
	void Destroy();

	Texture* AddImage(string key, wstring fileName, D3DCOLOR color);
	Texture* AddFrameImage(string key, wstring fileName,int _maxFrameX,int _maxFrameY, D3DCOLOR color);

	Texture* FindImage(string key);

	
	ImageManager();
	~ImageManager();
};

