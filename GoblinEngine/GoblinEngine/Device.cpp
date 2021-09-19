#include "pch.h"
#include "Device.h"
#include "DeviceContext.h"
#include "SwapChain.h"


GoblinEngine::DirectX::Device::Device(IntPtr unmanagedObject)
{
    device = (ID3D11Device*)unmanagedObject.ToPointer();
}

GoblinEngine::DirectX::Device::Device(DriverType driverType, FeatureLevel featureLevel, SwapChainDescription^ swapChainDescription, out SwapChain^% swapChain, out DeviceContext^% deviceContext)
{
    IDXGISwapChain* pSwapChain;
    ID3D11DeviceContext* pDeviceContext;
    ID3D11Device* pDevice;
    D3D_FEATURE_LEVEL level = (D3D_FEATURE_LEVEL)featureLevel;
    DXGI_SWAP_CHAIN_DESC desc;
    ZeroMemory(&desc, sizeof(desc));

    desc.BufferCount = 1;
    desc.BufferDesc.Width = swapChainDescription->BufferDescription->Width;
    desc.BufferDesc.Height = swapChainDescription->BufferDescription->Height;
    desc.BufferDesc.Format = (DXGI_FORMAT)swapChainDescription->BufferDescription->Format;
    desc.BufferDesc.RefreshRate.Denominator = swapChainDescription->BufferDescription->RefreshRate->Denominator;
    desc.BufferDesc.RefreshRate.Numerator = swapChainDescription->BufferDescription->RefreshRate->Numerator;
    desc.BufferDesc.ScanlineOrdering = (DXGI_MODE_SCANLINE_ORDER)swapChainDescription->BufferDescription->ScanlineOrdering;
    desc.BufferDesc.Scaling = (DXGI_MODE_SCALING)swapChainDescription->BufferDescription->Scaling;
    
    desc.BufferUsage = (DXGI_USAGE)swapChainDescription->BufferUsage;
    desc.OutputWindow = (HWND)swapChainDescription->OutputWindow.ToPointer();
    desc.SampleDesc.Count = swapChainDescription->SampleDescription->Count;
    desc.SampleDesc.Quality = swapChainDescription->SampleDescription->Quality;

    desc.Windowed = swapChainDescription->Windowed;

    desc.SwapEffect = (DXGI_SWAP_EFFECT)swapChainDescription->SwapEffect;
    desc.Flags = swapChainDescription->Flags;


    HRESULT hr = D3D11CreateDeviceAndSwapChain(0, (D3D_DRIVER_TYPE)driverType, 0, 0, &level, 1, D3D11_SDK_VERSION, &desc, &pSwapChain, &pDevice, 0, &pDeviceContext);
    if (FAILED(hr))
    {
        String^ code = Int32(hr).ToString();
        String^ msg = gcnew String("[Error] Code : ") + code;
        throw gcnew System::Exception(msg);
    }

    swapChain = gcnew SwapChain((IntPtr)pSwapChain);
    deviceContext = gcnew DeviceContext((IntPtr)pDeviceContext);
    device = pDevice;
}

GoblinEngine::DirectX::Device::~Device()
{
    device->Release();
}

void GoblinEngine::DirectX::Device::CreateBuffer(BufferDescription desc)
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateTexture1D()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateTexture2D()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateTexture3D()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateShaderResourceView()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateUnorderedAccessView()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateRenderTargetView()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateDepthStencilView()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateInputLayout()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateVertexShader()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateGeometryShader()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateGeometryShaderWithStreamOutput()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreatePixelShader()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateHullShader()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateDomainShader()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateComputeShader()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateClassLinkage()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateBlendState()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateDepthStencilState()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateRasterizerState()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateSamplerState()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateQuery()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreatePredicate()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateCounter()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CreateDeferredContext()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::OpenSharedResource()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CheckFormatSupport()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CheckMultisampleQualityLevels()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CheckCounterInfo()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CheckCounter()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::CheckFeatureSupport()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::GetPrivateData()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::SetPrivateData()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::SetPrivateDataInterface()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::GetFeatureLevel()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::GetCreationFlags()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::GetDeviceRemovedReason()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::GetImmediateContext()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::SetExceptionMode()
{
    throw gcnew System::NotImplementedException();
}

void GoblinEngine::DirectX::Device::GetExceptionMode()
{
    throw gcnew System::NotImplementedException();
}
