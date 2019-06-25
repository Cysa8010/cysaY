#include "main.h"
#include "manager.h"
// ˆË‘¶Œn
#include "renderer.h"// Direct3D9
#include "input.h"   // WindowsAPI

void Manager::Initialize()
{
	Renderer::Initialize();
	Input::Initialize();
	
}

void Manager::Finalize()
{
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

	Renderer::End();
}
