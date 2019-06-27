#include "main.h"
#include "manager.h"
// ˆË‘¶Œn
#include "renderer.h"// Direct3D9
#include "input.h"   // WindowsAPI

#include "texture.h"
#include "polygon.h"
#include "Object.h"
#include "player.h"
#include "enemy.h"
#include <list>

//CPolygon* g_polygon;
std::list<Object*> g_GameObjects;
//Player* g_Player;
//Enemy* g_Enemy;

void Manager::Initialize()
{
	Renderer::Initialize();
	Input::Initialize();
	
	Player* player = new Player();
	player->Initialize();
	g_GameObjects.push_back(player);
	Enemy* enemy = new Enemy();
	enemy->Initialize();
	g_GameObjects.push_back(enemy);
}

void Manager::Finalize()
{
	for (Object* object : g_GameObjects)
	{
		object->Finalize();
		delete object;
	}
	g_GameObjects.clear();

	Input::Finalize();
	Renderer::Finalize();
}

void Manager::Update()
{
	Input::Update();
	for (Object* object : g_GameObjects)
	{
		object->Update();
	}
}

void Manager::Draw()
{
	Renderer::Begin();

	for (Object* object : g_GameObjects)
	{
		object->Draw();
	}

	Renderer::End();
}
