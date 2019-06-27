#ifndef TEXTURE_H_
#define TEXTURE_H_

class Texture
{
private:
	LPDIRECT3DTEXTURE9 image;
public:
	void Load(const char* fileName);
	void Release();
	LPDIRECT3DTEXTURE9 GetTexture() { return image; }
};

#endif // !TEXTURE_H_
