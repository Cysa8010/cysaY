#include "main.h"
#include "manager.h"
// ˆË‘¶Œn
#include "renderer.h"// Direct3D9
#include "input.h"   // WindowsAPI
#include "scene.h"

Scene* g_Scene;

void Manager::Initialize()
{
	Renderer::Initialize();
	Input::Initialize();
	
	g_Scene = new Scene();
	g_Scene->Initialize();
}

void Manager::Finalize()
{
	g_Scene->Finalize();
	delete g_Scene;

	Input::Finalize();
	Renderer::Finalize();
}

void Manager::Update()
{
	Input::Update();
	g_Scene->Update();
}

void Manager::Draw()
{
	Renderer::Begin();

	g_Scene->Draw();

	Renderer::End();
}

Scene * Manager::GetScene()
{
	return g_Scene;
}
