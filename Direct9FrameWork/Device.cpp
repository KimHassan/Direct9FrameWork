#include "stdafx.h"
#include "Device.h"


Device::Device()
{
	

}


Device::~Device()
{
}

void Device::Init()
{


	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	//assert(d3d != NULL);

	D3DPRESENT_PARAMETERS param = { 0 };
	param.Windowed = TRUE;
	param.SwapEffect = D3DSWAPEFFECT_DISCARD;
	param.AutoDepthStencilFormat = D3DFMT_D16;
	param.EnableAutoDepthStencil = TRUE;
	param.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;
	//vsync끔
	param.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	//vSync(Vertical Synchronization)수직동기
	//그래픽 카드의 영상프래임을 화면 재생률에 맞춰 전송하는 기능
	//수직동기를 키면 60프래임으로 고정

	HRESULT hr;
	hr = d3d->CreateDevice
	(
		D3DADAPTER_DEFAULT //주화면쓸거냐 보조화면쓸거냐
		, D3DDEVTYPE_HAL //하드
		, hWnd //핸들 (중요!!)핸들에서 렌더링된다
		, D3DCREATE_HARDWARE_VERTEXPROCESSING //정점처리 누가할거냐(하드웨어가한다)
		, &param //추가정보 설정
		, &device
	);
}


void Device::Begin()
{
	device->Clear(0
		, NULL
		, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER
		, 0x00FFFFF
		, 1.0f
		, 0);
	device->BeginScene();
}
void Device::End()
{
	device->EndScene(); // 자면 종료
	device->Present(NULL, NULL, NULL, NULL);//후면버퍼를 시연
}