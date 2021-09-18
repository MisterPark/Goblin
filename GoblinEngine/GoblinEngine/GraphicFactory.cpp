#include "pch.h"
#include "GraphicFactory.h"
#include "GraphicAdapter.h"


GoblinEngine::DirectX::GraphicFactory::GraphicFactory()
{
	pin_ptr<IDXGIFactory*> pFactory = &factory;
	CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)pFactory);
}

GoblinEngine::DirectX::GraphicFactory::~GraphicFactory()
{
	factory->Release();
	factory = NULL;
}

GraphicAdapter^ GoblinEngine::DirectX::GraphicFactory::EnumAdapters(unsigned adapter)
{
	IDXGIAdapter* pAdapter;
	factory->EnumAdapters(adapter, &pAdapter);
	IntPtr ptr = (IntPtr)pAdapter;
	return gcnew GraphicAdapter(ptr);
}
