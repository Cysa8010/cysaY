#include "main.h"
#include "renderer.h"
#include "texture.h"
#include "polygon.h"
#include "Object.h"
#include "player.h"
#include "input.h"   // WindowsAPI

Player::Player()
{

}

Player::~Player()
{

}

void Player::Initialize()
{
	m_Polygon = new CPolygon();
	m_Polygon->Initialize();

	tex = new Texture();
	tex->Load("asset/cursol2.png");
}

void Player::Finalize()
{
	if (tex)
	{
		tex->Release();
		delete tex;
	}
	if (m_Polygon)
	{
		m_Polygon->Finalise();
		delete m_Polygon;
	}
}

void Player::Update()
{
	if (Input::GetKeyPress('W'))m_Position.y += -10.f;
	if (Input::GetKeyPress('S'))m_Position.y += +10.f;
}

void Player::Draw()
{
	Renderer::GetDevice()->SetTexture(0, tex->GetTexture());
	m_Polygon->Draw(m_Position.x, m_Position.y);
}
