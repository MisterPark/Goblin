#pragma once

namespace GoblinEngine
{
	namespace DirectX
	{
		public ref class Device
		{
		private:
			ID3D11Device* device;
		public:
			Device();
			~Device();

			void CreateBuffer(GoblinEngine::DirectX::BufferDescription desc);
			void CreateTexture1D();
			void CreateTexture2D();
			void CreateTexture3D();
			void CreateShaderResourceView();
			void CreateUnorderedAccessView();
			void CreateRenderTargetView();
			void CreateDepthStencilView();
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
			void CreateDepthStencilState();
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

