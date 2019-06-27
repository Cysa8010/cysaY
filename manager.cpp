#include "main.h"
#include "manager.h"
// ˆË‘¶Œn
#include "renderer.h"// Direct3D9
#include "input.h"   // WindowsAPI

#include "texture.h"
#include "polygon.h"

CPolygon* g_polygon;

void Manager::Initialize()
{
	Renderer::Initialize();
	Input::Initialize();
	g_polygon = new CPolygon();
	g_polygon->Initialize();
	
}

void Manager::Finalize()
{
	g_polygon->Finalise();
	delete g_polygon;
	Input::Finalize();
	Renderer::Finalize();
}

void Manager::Update()
{
	Input::Update();
}

void Manager::Draw()
{
	Renderer::Begin();

	g_polygon->Draw();

	Renderer::End();
}
