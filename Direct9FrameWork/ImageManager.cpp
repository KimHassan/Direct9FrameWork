#include "stdafx.h"
#include "ImageManager.h"


HRESULT ImageManager::Init()
{
	return S_OK;
}

void ImageManager::Destroy()
{
	auto a = _mImageList;

}

ImageManager::ImageManager() {}
ImageManager::~ImageManager() {}

Texture * ImageManager::AddImage(string key, wstring fileName,D3DCOLOR color)
{

	Texture *t = FindImage(key);

	if (t) return t;

	t = new Texture;

	if (FAILED(t->Init(fileName,color)))
	{
		t->Destroy();
		
		return NULL;
	}
	_mImageList.insert({ key,t });
	return t;
}

Texture * ImageManager::AddFrameImage(string key, wstring fileName, int _maxFrameX, int _maxFrameY, D3DCOLOR color)
{
	Texture * t = FindImage(key);

	if (t) return t;

	t = new Texture;

	if (FAILED(t->Init(fileName,_maxFrameX,_maxFrameY,color)))
	{
		t->Destroy();

		return NULL;
	}
	_mImageList.insert({ key,t });

	return t;
}

Texture * ImageManager::FindImage(string key)
{
	mapImageIter it = _mImageList.find(key);

	if (it != _mImageList.end())
	{
		return it->second;
	}
	return NULL;
}

