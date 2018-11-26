#include "stdafx.h"
#include "KeyManager.h"


KeyManager::KeyManager()
{
}


KeyManager::~KeyManager()
{
}

HRESULT KeyManager::Init()
{
	for (int i = 0; i < KEYMAX; i++)
	{
		this->getKeyUp().set(i, false);
		this->getKeyDown().set(i, false);
	}
	return S_OK;
}

void KeyManager::Destroy()
{
}

bool KeyManager::isOnceKeyDown(int key)
{
	//어떤 키를 눌렀다는 신호가 드렁오면 (비동기)
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (!this->getKeyDown()[key]) // 만약 그 키가 눌러져있지 않은 상태면
		{
			this->setKeyDown(key, true); // 해당키를 눌렀다고 신호를 보내라 // 중복방지를 위해서 해제해줌
			return true;
		}
	}
	else this->setKeyDown(key, false);
	return false;
}

bool KeyManager::isOnceKeyUp(int key)
{
	if (GetAsyncKeyState(key) & 0x8000) this->setKeyUp(key, true);
	else
	{
		if (this->getKeyUp()[key])
		{
			this->setKeyUp(key, false);
			return true;
		}
	}
	return false;
}

bool KeyManager::isStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
		return true;

	return false;
}

bool KeyManager::isToggleKey(int key)
{
	if (GetAsyncKeyState(key) & 0x0001)
		return true;

	return false;
}
