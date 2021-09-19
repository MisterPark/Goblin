#include "pch.h"
#include "SwapChain.h"

GoblinEngine::DirectX::SwapChain::SwapChain(IntPtr unmanagedObject)
{
    swapChain = (IDXGISwapChain*)unmanagedObject.ToPointer();
}

GoblinEngine::DirectX::SwapChain::~SwapChain()
{
    swapChain->Release();
}
