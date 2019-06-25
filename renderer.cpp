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

	//パラメータ構造体の設定
	d3dpp.BackBufferWidth = SCREEN_WIDTH; //バッファはウィンドウの内のサイズ（横）
	d3dpp.BackBufferHeight = SCREEN_HEIGHT; //バッファはウィンドウの内のサイズ（縦）

	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN; //バッファのフォーマット(色数)

	d3dpp.BackBufferCount = 1;//バックバッファの数（基本的に表１裏１で十分）

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD; //このゲームが動いているデバイスで最速でスワップする（その代わりそのあとのバッファの状態は保証しない）

	d3dpp.Windowed = TRUE;//  !!!フルスクリーンにするときはここはfalse

	d3dpp.EnableAutoDepthStencil = TRUE;//depthstencilを有効にするかどうか  ポリゴンの裏表判定？

	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;//深度バッファを16bit    三年生の後期にある技法で　_D24S8にすることになる24bitのスペンシルバッファ8bit

	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;//全画面時だけリフレッシュレートを指定出来る
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;  //D3DPRESENT_INTERVAL_DEFAULT  D3DPRESENT_INTERVAL_ONE

	HRESULT hr = g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, GetHWnd(), D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &g_pDevice);

	if (FAILED(hr))
	{
		return;
	}

	// テクスチャサンプラーの設定
	g_pDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_MIRROR);

	// テクスチャフィルタリングの設定
	g_pDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	g_pDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	g_pDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

	//アルファブレンドの有効化
	g_pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA); //これからのやつデストブレンド
	g_pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);     //今までのやつソースブレンド

	// ポリゴンのαの有効化
	g_pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);//ポリゴンのα
	g_pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);//画面のα
	g_pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);//かけ合わせ

	return;
}

void Renderer::Finalize()
{
	SAFE_RELEASE(g_pDevice);
	SAFE_RELEASE(g_pD3D);
}

void Renderer::Begin()
{
	//クリア関数   1～2.弄らない 3.クリアするものをセットする 4.クリアする時のカラー色 5.深さの初期化値 6.スペンシルの初期化値                
	g_pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(125, 125, 125, 255), 1.0f, 0);//D3DCOLOR_RGBA(100, 80, 200, 255)

	//描画開始
	g_pDevice->BeginScene();
}

void Renderer::End()
{
	//描画終了
	g_pDevice->EndScene();
	g_pDevice->Present(NULL, NULL, NULL, NULL);
}
