#ifndef TEXTURE_H_
#define TEXTURE_H_

class Texture
{
private:
	LPDIRECT3DTEXTURE9 image;

	// �R���e�i�Ƃ��Ďg�����Ɏg�p
	int m_Index;   // �Ǘ��ԍ�
	int m_UseCount;// �g�p���Ă���I�u�W�F�N�g�̌�

public:
	void Load(const char* fileName);
	void Release();
	LPDIRECT3DTEXTURE9 GetTexture() { return image; }
};

#endif // !TEXTURE_H_
