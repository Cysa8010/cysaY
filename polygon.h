#ifndef POLYGON_H_
#define POLYGON_H_

class CPolygon
{
private:
	LPDIRECT3DVERTEXBUFFER9 pVertexBuffer = NULL;
	LPDIRECT3DINDEXBUFFER9 pIndexBuffer = NULL;
public:
	void Initialize();
	void Finalise();
	void Update();
	void Draw();
};

#endif // !POLYGON_H_
