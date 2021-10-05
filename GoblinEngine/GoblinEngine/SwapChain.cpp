#include "pch.h"
#include "SwapChain.h"
#include "Texture2D.h"

GoblinEngine::DirectX::SwapChain::SwapChain(IntPtr unmanagedObject)
{
    swapChain = (IDXGISwapChain*)unmanagedObject.ToPointer();
}

GoblinEngine::DirectX::SwapChain::~SwapChain()
{
    if (swapChain == nullptr) return;
    swapChain->Release();
    swapChain = nullptr;
}

Texture2D^ GoblinEngine::DirectX::SwapChain::GetTexture2D(UINT buffer)
{
    ID3D11Texture2D* pTexture = nullptr;
    HRESULT hr = swapChain->GetBuffer(buffer, __uuidof(ID3D11Texture2D), (void**)&pTexture);
    if (FAILED(hr))
    {
        return nullptr;
    }

    return  gcnew Texture2D((IntPtr)pTexture);
}
