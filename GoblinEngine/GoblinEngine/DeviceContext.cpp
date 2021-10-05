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

void GoblinEngine::DirectX::DeviceContext::OMSetDepthStencilState(DepthStencilState state, UINT stencilRef)
{
    deviceContext->OMSetDepthStencilState(state.ToOrigin(), stencilRef);
}
