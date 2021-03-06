// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define WIN_START_X 0
#define WIN_START_Y 0

#define SAFE_RELEASE(p) {if(p) {(p)->Release();} (p) = NULL;}
#define SAFE_DESTROY(p) {if(p) {(p)->Destroy();} (p) = NULL;}
#define SAFE_DELETE(p) {if(p) {delete (p); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p) {if(p){delete[] (p); (p) = NULL;}}

#define PI 3.141592654f
#define PI2 PI * 2

// 싱글톤

// Windows 헤더 파일:
#include <windows.h>

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#include <math.h>
#include <map>
#include <assert.h>
#include <time.h>
#include <mmsystem.h>
#include <string>
#include <functional>

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib,"d3dx9.lib")

#pragma comment(lib,"winmm.lib")


// C 런타임 헤더 파일입니다.
#include "Util.h"

using namespace std;

using namespace Util;
typedef function<void()> CALL_BACK;
#include "Device.h"
#include "KeyManager.h"
#include "TimeManager.h"
#include "SoundManager.h"
#include "SceneManager.h"
#include "ImageManager.h"

#define DEVICE Device::getSingleton()
#define KEYMANAGER KeyManager::getSingleton()
#define TIMER TimeManager::getSingleton()
#define SOUNDMANAGER SoundManager::getSingleton()
#define SCENEMANAGER SceneManager::getSingleton()
#define IMAGEMANAGER ImageManager::getSingleton()
//GameScene






//MainGame
#include "MainGame.h"

extern HWND hWnd;
extern D3DXVECTOR2 mousePos;


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
