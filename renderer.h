#ifndef RENDERER_H_
#define RENDERER_H_

#define VERTEX_3D_FVF (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1)
struct VERTEX_3D
{
	D3DXVECTOR3 position;
	D3DXVECTOR3 normal;
	D3DCOLOR    diffuse;
	D3DXVECTOR2 texcoord;
};

class Renderer
{
public:
	static void Initialize();
	static void Finalize();
	static void Begin();
	static void End();

	static void SetMatrix2D();
	

	static LPDIRECT3DDEVICE9 GetDevice();


};

#endif // !RENDERER_H_
