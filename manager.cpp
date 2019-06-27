#include "main.h"
#include "manager.h"
// ˆË‘¶Œn
#include "renderer.h"// Direct3D9
#include "input.h"   // WindowsAPI

#include "texture.h"
#include "polygon.h"
#include "Object.h"
#include "player.h"

//CPolygon* g_polygon;
Player* g_Player;

void Manager::Initialize()
{
	Renderer::Initialize();
	Input::Initialize();
	
	g_Player = new Player();
	g_Player->Initialize();
}

void Manager::Finalize()
{
	g_Player->Finalize();
	delete g_Player;

	Input::Finalize();
	Renderer::Finalize();
}

void Manager::Update()
{
	Input::Update();
	g_Player->Update();
}

void Manager::Draw()
{
	Renderer::Begin();

	g_Player->Draw();

	Renderer::End();
}
