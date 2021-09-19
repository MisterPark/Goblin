#include "pch.h"
#include "DeviceContext.h"

GoblinEngine::DirectX::DeviceContext::DeviceContext(IntPtr unmanagedObject)
{
    deviceContext = (ID3D11DeviceContext*)unmanagedObject.ToPointer();
}

GoblinEngine::DirectX::DeviceContext::~DeviceContext()
{
    deviceContext->Release();
}
