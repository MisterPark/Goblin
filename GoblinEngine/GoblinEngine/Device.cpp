#include "pch.h"
#include "Device.h"
#include "DeviceContext.h"
#include "SwapChain.h"
#include "Texture2D.h"

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

Texture2D^ GoblinEngine::DirectX::Device::CreateTexture2D(Texture2DDescription desc)
{
    ID3D11Texture2D* texture;
    D3D11_TEXTURE2D_DESC textureDesc;
    textureDesc.Width = desc.Width;
    textureDesc.Height = desc.Height;
    textureDesc.MipLevels = desc.MipLevels;
    textureDesc.ArraySize = desc.ArraySize;
    textureDesc.Format = (DXGI_FORMAT)desc.Format;
    textureDesc.SampleDesc.Count = desc.SampleDesc->Count;
    textureDesc.SampleDesc.Quality = desc.SampleDesc->Quality;
    textureDesc.Usage = (D3D11_USAGE)desc.Usage;
    textureDesc.BindFlags = desc.BindFlags;
    textureDesc.CPUAccessFlags = desc.CPUAccessFlags;
    textureDesc.MiscFlags = desc.MiscFlags;

    if (FAILED(device->CreateTexture2D(&textureDesc, NULL, &texture)))
    {
        return nullptr;
    }

    return gcnew Texture2D((IntPtr)texture);
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

RenderTargetView^ GoblinEngine::DirectX::Device::CreateRenderTargetView(IResource^ resource, RenderTargetViewDescription desc)
{
  ID3D11Resource* _resource = resource->ToOrigin();
}

DepthStencilView^ GoblinEngine::DirectX::Device::CreateDepthStencilView(Texture2D^ resource, DepthStencilViewDescription desc)
{
    ID3D11DepthStencilView* view;
    D3D11_DEPTH_STENCIL_VIEW_DESC viewDesc;
    viewDesc.Format = (DXGI_FORMAT)desc.Format;
    viewDesc.ViewDimension = (D3D11_DSV_DIMENSION)desc.ViewDimension;
    viewDesc.Flags = desc.Flags;
    viewDesc.Texture1D.MipSlice = desc.Texture1D.MipSlice;
    viewDesc.Texture1DArray.MipSlice = desc.Texture1DArray.MipSlice;
    viewDesc.Texture1DArray.ArraySize = desc.Texture1DArray.ArraySize;
    viewDesc.Texture1DArray.FirstArraySlice = desc.Texture1DArray.FirstArraySlice;
    viewDesc.Texture2D.MipSlice = desc.Texture2D.MipSlice;
    viewDesc.Texture2DArray.MipSlice = desc.Texture2DArray.MipSlice;
    viewDesc.Texture2DArray.ArraySize = desc.Texture2DArray.ArraySize;
    viewDesc.Texture2DArray.FirstArraySlice = desc.Texture2DArray.FirstArraySlice;
    viewDesc.Texture2DMS.UnusedField_NothingToDefine = desc.Texture2DMS.UnusedField_NothingToDefine;
    viewDesc.Texture2DMSArray.ArraySize = desc.Texture2DMSArray.ArraySize;
    viewDesc.Texture2DMSArray.FirstArraySlice = desc.Texture2DMSArray.FirstArraySlice;

    auto hr = device->CreateDepthStencilView(resource->ToOrigin(), &viewDesc, &view);
    if (FAILED(hr))
    {
        return nullptr;
    }
    return gcnew DepthStencilView((IntPtr)view);
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

DepthStencilState^ GoblinEngine::DirectX::Device::CreateDepthStencilState(DepthStencilDescription desc)
{
    ID3D11DepthStencilState* state;
    D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
    depthStencilDesc.DepthEnable = desc.DepthEnable;
    depthStencilDesc.DepthWriteMask = (D3D11_DEPTH_WRITE_MASK)desc.DepthWriteMask;
    depthStencilDesc.DepthFunc = (D3D11_COMPARISON_FUNC)desc.DepthFunc;

    depthStencilDesc.StencilEnable = desc.StencilEnable;
    depthStencilDesc.StencilReadMask = desc.StencilReadMask;
    depthStencilDesc.StencilWriteMask = desc.StencilWriteMask;

    depthStencilDesc.FrontFace.StencilFailOp = (D3D11_STENCIL_OP)desc.FrontFace->StencilFailOp;
    depthStencilDesc.FrontFace.StencilDepthFailOp = (D3D11_STENCIL_OP)desc.FrontFace->StencilDepthFailOp;
    depthStencilDesc.FrontFace.StencilPassOp = (D3D11_STENCIL_OP)desc.FrontFace->StencilPassOp;
    depthStencilDesc.FrontFace.StencilFunc = (D3D11_COMPARISON_FUNC)desc.FrontFace->StencilFunc;

    depthStencilDesc.BackFace.StencilFailOp = (D3D11_STENCIL_OP)desc.BackFace->StencilFailOp;
    depthStencilDesc.BackFace.StencilDepthFailOp = (D3D11_STENCIL_OP)desc.BackFace->StencilDepthFailOp;
    depthStencilDesc.BackFace.StencilPassOp = (D3D11_STENCIL_OP)desc.BackFace->StencilPassOp;
    depthStencilDesc.BackFace.StencilFunc = (D3D11_COMPARISON_FUNC)desc.BackFace->StencilFunc;

    auto hr = device->CreateDepthStencilState(&depthStencilDesc, &state);
    if (FAILED(hr))
    {
        return nullptr;
    }
    return gcnew DepthStencilState((IntPtr)state);
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
