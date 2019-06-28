#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"
#include "polygon.h"
#include "Object.h"
#include "scene.h"
#include "explosion.h"

Explosion::Explosion()
{
}

Explosion::~Explosion()
{
}

void Explosion::Initialize()
{
	m_Polygon = new CPolygon();
	m_Polygon->Initialize();

	m_Tex = new Texture();
	m_Tex->Load("asset/exp.tga");

}

void Explosion::Finalize()
{
	if (m_Tex)
	{
		m_Tex->Release();
		delete m_Tex;
	}
	if (m_Polygon)
	{
		m_Polygon->Finalise();
		delete m_Polygon;
	}
}

void Explosion::Update()
{
}

void Explosion::Draw()
{
	Renderer::GetDevice()->SetTexture(0, m_Tex->GetTexture());
	m_Polygon->Draw(m_Position.x, m_Position.y);
}

