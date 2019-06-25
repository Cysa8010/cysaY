#include "manager.h"
#include "renderer.h"

void Manager::Initialize()
{
	Renderer::Initialize();
}

void Manager::Finalize()
{
	Renderer::Finalize();
}

void Manager::Update()
{
}

void Manager::Draw()
{
	Renderer::Begin();

	Renderer::End();
}
