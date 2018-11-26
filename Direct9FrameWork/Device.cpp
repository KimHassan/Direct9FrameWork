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
	//vsync��
	param.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	//vSync(Vertical Synchronization)��������
	//�׷��� ī���� ������������ ȭ�� ������� ���� �����ϴ� ���
	//�������⸦ Ű�� 60���������� ����

	HRESULT hr;
	hr = d3d->CreateDevice
	(
		D3DADAPTER_DEFAULT //��ȭ�龵�ų� ����ȭ�龵�ų�
		, D3DDEVTYPE_HAL //�ϵ�
		, hWnd //�ڵ� (�߿�!!)�ڵ鿡�� �������ȴ�
		, D3DCREATE_HARDWARE_VERTEXPROCESSING //����ó�� �����Ұų�(�ϵ����Ѵ�)
		, &param //�߰����� ����
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
	device->EndScene(); // �ڸ� ����
	device->Present(NULL, NULL, NULL, NULL);//�ĸ���۸� �ÿ�
}