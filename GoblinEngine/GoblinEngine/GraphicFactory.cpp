#include "pch.h"
#include "GraphicFactory.h"

GoblinEngine::DirectX::GraphicFactory::GraphicFactory()
{
	CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)PIN(IDXGIFactory*, factory));
}
