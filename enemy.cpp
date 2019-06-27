#include "main.h"
#include "renderer.h"
#include "texture.h"
#include "polygon.h"
#include "Object.h"
#include "enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	m_Polygon = new CPolygon();
	m_Polygon->Initialize();

	m_Tex = new Texture();
	m_Tex->Load("asset/cursol2.png");

}

void Enemy::Finalize()
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

void Enemy::Update()
{
}

void Enemy::Draw()
{
	Renderer::GetDevice()->SetTexture(0, m_Tex->GetTexture());
	m_Polygon->Draw(m_Position.x, m_Position.y);
}
