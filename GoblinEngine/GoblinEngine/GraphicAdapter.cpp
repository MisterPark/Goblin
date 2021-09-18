#include "pch.h"
#include "GraphicAdapter.h"

GoblinEngine::DirectX::GraphicAdapter::GraphicAdapter(IntPtr unmanagedObject)
{
    adapter = (IDXGIAdapter*)unmanagedObject.ToPointer();
}

GoblinEngine::DirectX::GraphicAdapter::~GraphicAdapter()
{
    adapter->Release();
    adapter = nullptr;
}
