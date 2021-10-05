#pragma once

namespace GoblinEngine
{
	namespace DirectX
	{
		ref class DeviceContext;
		ref class SwapChain;
		ref struct Texture2DDescription;
		ref class Texture2D;
		ref class DepthStencilState;
		ref class DepthStencilView;

		public ref class Device
		{
		private:
			ID3D11Device* device;
		public:
			Device(IntPtr unmanagedObject);
			Device(DriverType driverType, FeatureLevel featureLevel,SwapChainDescription^ swapChainDescription, out SwapChain^% swapChain, out DeviceContext^% deviceContext);
			~Device();

			void CreateBuffer(GoblinEngine::DirectX::BufferDescription desc);
			void CreateTexture1D();
			Texture2D^ CreateTexture2D(Texture2DDescription desc);
			void CreateTexture3D();
			void CreateShaderResourceView();
			void CreateUnorderedAccessView();
			void CreateRenderTargetView();
			DepthStencilView^ CreateDepthStencilView(Texture2D^ resource, DepthStencilViewDescription desc);
			void CreateInputLayout();
			void CreateVertexShader();
			void CreateGeometryShader();
			void CreateGeometryShaderWithStreamOutput();
			void CreatePixelShader();
			void CreateHullShader();
			void CreateDomainShader();
			void CreateComputeShader();
			void CreateClassLinkage();
			void CreateBlendState();
			DepthStencilState^ CreateDepthStencilState(DepthStencilDescription desc);
			void CreateRasterizerState();
			void CreateSamplerState();
			void CreateQuery();
			void CreatePredicate();
			void CreateCounter();
			void CreateDeferredContext();
			void OpenSharedResource();
			void CheckFormatSupport();
			void CheckMultisampleQualityLevels();
			void CheckCounterInfo();
			void CheckCounter();
			void CheckFeatureSupport();
			void GetPrivateData();
			void SetPrivateData();
			void SetPrivateDataInterface();
			void GetFeatureLevel();
			void GetCreationFlags();
			void GetDeviceRemovedReason();
			void GetImmediateContext();
			void SetExceptionMode();
			void GetExceptionMode();
		};

	}
}

