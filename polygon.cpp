#include "main.h"
#include "renderer.h"
#include "polygon.h"

void CPolygon::Initialize()
{
	VERTEX_3D vertex;

	LPDIRECT3DDEVICE9 pDevice = Renderer::GetDevice();
	if (!pDevice) return;

	// ���_�o�b�t�@�̊m�ہi���_�S���j
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) *4, D3DUSAGE_WRITEONLY, VERTEX_3D_FVF, D3DPOOL_DEFAULT, &pVertexBuffer, NULL);
	
	// ���_�̐ݒ�
	VERTEX_3D* pV; // ���z�A�h���X
	pVertexBuffer->Lock(0, 0, (void**)&pV, 0);

	// ���_���W
	pV[0].position = D3DXVECTOR3(-502.0f, +100.0f, +0.0f);
	pV[1].position = D3DXVECTOR3(+502.0f, +100.0f, +0.0f);
	pV[2].position = D3DXVECTOR3(-502.0f, -100.0f, +0.0f);
	pV[3].position = D3DXVECTOR3(+502.0f, -100.0f, +0.0f);

	// UV���W
	pV[0].texcoord = D3DXVECTOR2(0.f, 0.f);
	pV[1].texcoord = D3DXVECTOR2(1.f, 0.f);
	pV[2].texcoord = D3DXVECTOR2(0.f, 1.f);
	pV[3].texcoord = D3DXVECTOR2(1.f, 1.f);

	// �F
	for (int i = 0; i < 4; i++) {
		pV[i].diffuse = 0xffff0000;//�ԐF
	}

	// �@��
	pV[0].normal = D3DXVECTOR3(0.0, 0.0f, -1.0f); //��O
	pV[1].normal = D3DXVECTOR3(1.0, 0.0f, 0.0f);  //�E
	pV[2].normal = D3DXVECTOR3(-1.0, 0.0f, 0.0f); //��
	pV[3].normal = D3DXVECTOR3(0.0, 0.0f, 1.0f);  //��

	pVertexBuffer->Unlock();
}

void CPolygon::Finalise()
{
	// ���_�o�b�t�@�̉��
	if (pVertexBuffer) {
		pVertexBuffer->Release();
		pVertexBuffer = NULL;
	}
}

void CPolygon::Update()
{

}

void CPolygon::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = Renderer::GetDevice();
	
	{// ���[���h���W�̐ݒ�
		//D3DXMATRIX mtxWorld;
		//D3DXMatrixIdentity(&mtxWorld);// �P�ʍs��̍쐬
		//mtxWorld = *mtx;

		//pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);
	}

	
	{
		
		Renderer::SetMatrix2D();
		pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
		pDevice->SetFVF(VERTEX_3D_FVF);
		pDevice->SetTexture(0,0);
		pDevice->SetStreamSource(0, pVertexBuffer, 0, sizeof(VERTEX_3D));
		
		// �v���~�e�B�u�̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	}
}
