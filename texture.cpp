#include "main.h"
#include "renderer.h"
#include "texture.h"

void Texture::Load(const char * fileName)
{
	if (FAILED(D3DXCreateTextureFromFile(Renderer::GetDevice() , fileName, &image))) 
	{
		return;
	}
}

void Texture::Release()
{
	if (image)
	{
		image->Release();
		image = NULL;
	}
}
