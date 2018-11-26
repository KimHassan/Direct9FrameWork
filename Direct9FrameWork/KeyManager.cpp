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
	//� Ű�� �����ٴ� ��ȣ�� �巷���� (�񵿱�)
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (!this->getKeyDown()[key]) // ���� �� Ű�� ���������� ���� ���¸�
		{
			this->setKeyDown(key, true); // �ش�Ű�� �����ٰ� ��ȣ�� ������ // �ߺ������� ���ؼ� ��������
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
