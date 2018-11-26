#pragma once
#include "singletonBase.h"
#include <bitset>

#define KEYMAX 256

class KeyManager :
	public singletonBase<KeyManager>
{
private:
	bitset<KEYMAX> keyUp;
	bitset<KEYMAX> keyDown;
public:
	KeyManager();
	~KeyManager();

	HRESULT Init();
	void Destroy();

	bool isOnceKeyDown(int key);
	bool isOnceKeyUp(int key);
	bool isStayKeyDown(int key);
	bool isToggleKey(int key);

	bitset<KEYMAX> getKeyUp() { return keyUp; }
	bitset<KEYMAX> getKeyDown() { return keyDown; }

	void setKeyDown(int key, bool state) { keyDown.set(key, state); } // 키를 강제로 내리게 한다
	void setKeyUp(int key, bool state) { keyUp.set(key, state); }
};

