#include "renderer.h"
#include "main.h"
#include <d3d9.h>

#define SAFE_RELEASE(x)   { if(x) {(x)->Release(); (x) = NULL;} }

static LPDIRECT3D9 g_pD3D = NULL;
static LPDIRECT3DDEVICE9 g_pDevice = NULL;

void Renderer::Initialize()
{
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (g_pD3D == NULL) {
		return;
	}

	D3DPRESENT_PARAMETERS d3dpp = {};

	//�p�����[�^�\���̂̐ݒ�
	d3dpp.BackBufferWidth = SCREEN_WIDTH; //�o�b�t�@�̓E�B���h�E�̓��̃T�C�Y�i���j
	d3dpp.BackBufferHeight = SCREEN_HEIGHT; //�o�b�t�@�̓E�B���h�E�̓��̃T�C�Y�i�c�j

	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN; //�o�b�t�@�̃t�H�[�}�b�g(�F��)

	d3dpp.BackBufferCount = 1;//�o�b�N�o�b�t�@�̐��i��{�I�ɕ\�P���P�ŏ\���j

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD; //���̃Q�[���������Ă���f�o�C�X�ōő��ŃX���b�v����i���̑��肻�̂��Ƃ̃o�b�t�@�̏�Ԃ͕ۏ؂��Ȃ��j

	d3dpp.Windowed = TRUE;//  !!!�t���X�N���[���ɂ���Ƃ��͂�����false

	d3dpp.EnableAutoDepthStencil = TRUE;//depthstencil��L���ɂ��邩�ǂ���  �|���S���̗��\����H

	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;//�[�x�o�b�t�@��16bit    �O�N���̌���ɂ���Z�@�Ł@_D24S8�ɂ��邱�ƂɂȂ�24bit�̃X�y���V���o�b�t�@8bit

	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;//�S��ʎ��������t���b�V�����[�g���w��o����
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;  //D3DPRESENT_INTERVAL_DEFAULT  D3DPRESENT_INTERVAL_ONE

	HRESULT hr = g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, GetHWnd(), D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &g_pDevice);

	if (FAILED(hr))
	{
		return;
	}

	// �e�N�X�`���T���v���[�̐ݒ�
	g_pDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_MIRROR);

	// �e�N�X�`���t�B���^�����O�̐ݒ�
	g_pDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	g_pDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	g_pDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

	//�A���t�@�u�����h�̗L����
	g_pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA); //���ꂩ��̂�f�X�g�u�����h
	g_pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);     //���܂ł̂�\�[�X�u�����h

	// �|���S���̃��̗L����
	g_pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);//�|���S���̃�
	g_pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);//��ʂ̃�
	g_pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);//�������킹

	return;
}

void Renderer::Finalize()
{
	SAFE_RELEASE(g_pDevice);
	SAFE_RELEASE(g_pD3D);
}

void Renderer::Begin()
{
	//�N���A�֐�   1�`2.�M��Ȃ� 3.�N���A������̂��Z�b�g���� 4.�N���A���鎞�̃J���[�F 5.�[���̏������l 6.�X�y���V���̏������l                
	g_pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(125, 125, 125, 255), 1.0f, 0);//D3DCOLOR_RGBA(100, 80, 200, 255)

	//�`��J�n
	g_pDevice->BeginScene();
}

void Renderer::End()
{
	//�`��I��
	g_pDevice->EndScene();
	g_pDevice->Present(NULL, NULL, NULL, NULL);
}
