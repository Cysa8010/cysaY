#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"
#include "polygon.h"
#include "Object.h"
#include "bullet.h"
#include "scene.h"
// 仮->後で削除
#include "enemy.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	m_Polygon = new CPolygon();
	m_Polygon->Initialize();

	m_Tex = new Texture();
	m_Tex->Load("asset/cursol2.png");
}

void Bullet::Finalize()
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

void Bullet::Update()
{
	m_Position.x += 1.0f;
	if (m_Position.x > (float)SCREEN_WIDTH-100.f)
	{
		Manager::GetScene()->DestroyGameObject(this);
	}

	// 衝突判定(仮)->コライダーとジャッジメントクラスを作って処理を委譲
	std::vector<Enemy*> enemys;
	enemys = Manager::GetScene()->GetGameObjects<Enemy>(2);
	for (Enemy* enemy : enemys)
	{
		D3DXVECTOR3 enemyPos = enemy->GetPosition();
		float renge = (32.f + 32.f)*(32.f + 32.f);
		float x = (enemyPos.x - this->m_Position.x)*(enemyPos.x - this->m_Position.x);
		float y = (enemyPos.y - this->m_Position.y)*(enemyPos.y - this->m_Position.y);
		float twoPointlength = x + y;
		if (twoPointlength < renge)
		{
			Manager::GetScene()->DestroyGameObject(enemy);
			Manager::GetScene()->DestroyGameObject(this);
			return;
		}
	}
}

void Bullet::Draw()
{
	Renderer::GetDevice()->SetTexture(0, m_Tex->GetTexture());
	m_Polygon->Draw(m_Position.x, m_Position.y);
}
