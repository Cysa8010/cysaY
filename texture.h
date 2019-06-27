#ifndef TEXTURE_H_
#define TEXTURE_H_

class Texture
{
private:
	LPDIRECT3DTEXTURE9 image;

	// コンテナとして使う時に使用
	int m_Index;   // 管理番号
	int m_UseCount;// 使用しているオブジェクトの個数

public:
	void Load(const char* fileName);
	void Release();
	LPDIRECT3DTEXTURE9 GetTexture() { return image; }
};

#endif // !TEXTURE_H_
