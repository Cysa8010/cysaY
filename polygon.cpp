#include "main.h"
#include "renderer.h"
#include "texture.h"
#include "polygon.h"


void CPolygon::Initialize()
{
	VERTEX_3D vertex;

	LPDIRECT3DDEVICE9 pDevice = Renderer::GetDevice();
	if (!pDevice) return;

	// 頂点バッファの確保（頂点４つ分）
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) *4, D3DUSAGE_WRITEONLY, VERTEX_3D_FVF, D3DPOOL_DEFAULT, &pVertexBuffer, NULL);
	
	// 頂点の設定
	VERTEX_3D* pV; // 仮想アドレス
	pVertexBuffer->Lock(0, 0, (void**)&pV, 0);

	// 頂点座標
	pV[0].position = D3DXVECTOR3(-32.0f, +32.0f, +0.0f);
	pV[1].position = D3DXVECTOR3(+32.0f, +32.0f, +0.0f);
	pV[2].position = D3DXVECTOR3(-32.0f, -32.0f, +0.0f);
	pV[3].position = D3DXVECTOR3(+32.0f, -32.0f, +0.0f);

	// UV座標
	pV[0].texcoord = D3DXVECTOR2(0.f, 0.f);
	pV[1].texcoord = D3DXVECTOR2(1.f, 0.f);
	pV[2].texcoord = D3DXVECTOR2(0.f, 1.f);
	pV[3].texcoord = D3DXVECTOR2(1.f, 1.f);

	// 色
	for (int i = 0; i < 4; i++) {
		pV[i].diffuse = 0xffffffff;//赤色
	}

	// 法線
	pV[0].normal = D3DXVECTOR3(0.0, 0.0f, -1.0f); //手前
	pV[1].normal = D3DXVECTOR3(1.0, 0.0f, 0.0f);  //右
	pV[2].normal = D3DXVECTOR3(-1.0, 0.0f, 0.0f); //左
	pV[3].normal = D3DXVECTOR3(0.0, 0.0f, 1.0f);  //奥

	pVertexBuffer->Unlock();
	tex = new Texture();
	tex->Load("asset/cursol2.png");
}

void CPolygon::Finalise()
{
	if (tex)
	{
		tex->Release();
		delete tex;
	}
	// 頂点バッファの解放
	if (pVertexBuffer) {
		pVertexBuffer->Release();
		pVertexBuffer = NULL;
	}
}

void CPolygon::Update()
{

}

void CPolygon::Draw(const float x, const float y)
{
	LPDIRECT3DDEVICE9 pDevice = Renderer::GetDevice();
	
	Renderer::SetMatrix2D();
	{// ワールド座標の設定
		D3DXMATRIX mtxWorld;
		D3DXMatrixIdentity(&mtxWorld);// 単位行列の作成
		D3DXMatrixTranslation(&mtxWorld, x-(SCREEN_WIDTH/2.f), (y*-1.f)+(SCREEN_HEIGHT/2.f), 0.f);
		pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);
	}

	{
		pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
		pDevice->SetFVF(VERTEX_3D_FVF);
		pDevice->SetTexture(0,tex->GetTexture());
		pDevice->SetStreamSource(0, pVertexBuffer, 0, sizeof(VERTEX_3D));
		
		// プリミティブの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	}
}
