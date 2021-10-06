#pragma once
using namespace System;

namespace GoblinEngine
{
	namespace DirectX
	{
		public ref struct LongUID
		{
		public:
			property DWORD LowPart;
			property LONG HighPart;
		};

		public ref struct BufferDescription
		{
		public:
			property unsigned int ByteWidth;
			property Usage Usage;
			property unsigned int BindFlags;
			property unsigned int CPUAccessFlags;
			property unsigned int MiscFlags;
			property unsigned int StructureByteStride;
		};

		public ref struct SubresourceData
		{
		public:
			property IntPtr pSysMem;
			property unsigned SysMemPitch;
			property unsigned SysMemSlicePitch;
		};

		public ref struct MappedSubresource
		{
		public:
			property IntPtr pData;
			property unsigned RowPitch;
			property unsigned DepthPitch;
		};

		public ref struct Rational
		{
		public:
			property UINT Numerator;
			property UINT Denominator;
		};

		public ref struct ModeDescription
		{
		public:
			property UINT Width;
			property UINT Height;
			property Rational^ RefreshRate;
			property GraphicFormat Format;
			property GraphicModeScanlineOrder ScanlineOrdering;
			property GraphicModeScaling Scaling;

			ModeDescription()
			{
				RefreshRate = gcnew Rational();
			}
		};

		public ref struct AdapterDescription
		{
		public:
			property String^ Description;
			property UINT VendorId;
			property UINT DeviceId;
			property UINT SubSysId;
			property UINT Revision;
			property SIZE_T DedicatedVideoMemory;
			property SIZE_T DedicatedSystemMemory;
			property SIZE_T SharedSystemMemory;
			property LongUID^ AdapterLuid;

			AdapterDescription()
			{
				AdapterLuid = gcnew LongUID();
			}
		};

		public ref struct GraphicSampleDescription
		{
		public:
			property UINT Count;
			property UINT Quality;
		};

		public ref struct SwapChainDescription
		{
		public:
			property ModeDescription^ BufferDescription;
			property GraphicSampleDescription^ SampleDescription;
			property GraphicUsage BufferUsage;
			property UINT BufferCount;
			property IntPtr OutputWindow;
			property bool Windowed;
			property SwapEffect SwapEffect;
			property UINT Flags;

			SwapChainDescription()
			{
				BufferDescription = gcnew ModeDescription();
				SampleDescription = gcnew GraphicSampleDescription();
			}
		};

		public ref struct Texture2DDescription
		{
		public:
			property UINT Width;
			property UINT Height;
			property UINT MipLevels;
			property UINT ArraySize;
			property GraphicFormat Format;
			property GraphicSampleDescription^ SampleDesc;
			property Usage Usage;
			property UINT BindFlags;
			property UINT CPUAccessFlags;
			property UINT MiscFlags;

			Texture2DDescription()
			{
				SampleDesc = gcnew GraphicSampleDescription();
			}
		};
		/// <summary>
		/// D3D11_DEPTH_STENCILOP_DESC
		/// </summary>
		public ref struct DepthStencilOPDescription
		{
		public:
			property StencilOp StencilFailOp;
			property StencilOp StencilDepthFailOp;
			property StencilOp StencilPassOp;
			property ComparisonType StencilFunc;
		};
		/// <summary>
		/// D3D11_DEPTH_STENCIL_DESC
		/// </summary>
		public ref struct DepthStencilDescription
		{
		public:
			property BOOL DepthEnable;
			property DepthWriteMask DepthWriteMask;
			property ComparisonType DepthFunc;
			property BOOL StencilEnable;
			property UINT8 StencilReadMask;
			property UINT8 StencilWriteMask;
			property DepthStencilOPDescription^ FrontFace;
			property DepthStencilOPDescription^ BackFace;

			DepthStencilDescription()
			{
				FrontFace = gcnew DepthStencilOPDescription();
				BackFace = gcnew DepthStencilOPDescription();
			}
		};


		public ref class DepthStencilState
		{
			DECLARE_WRAPPED_INSTANCE(DepthStencilState, ID3D11DepthStencilState)
		};


		public struct DSVTexture1D
		{
			UINT MipSlice;
		};

		public struct DSVTexture1DArray
		{
			UINT MipSlice;
			UINT FirstArraySlice;
			UINT ArraySize;
		};

		public struct DSVTexture2D
		{
			UINT MipSlice;
		};

		public struct DSVTexture2DArray
		{
			UINT MipSlice;
			UINT FirstArraySlice;
			UINT ArraySize;
		};

		public struct DSVTexture2DMS
		{
			UINT UnusedField_NothingToDefine;
		};

		public struct DSVTexture2DMSArray
		{
			UINT FirstArraySlice;
			UINT ArraySize;
		};
		/// <summary>
		/// D3D11_DEPTH_STENCIL_VIEW_DESC
		/// </summary>
		public struct DepthStencilViewDescription
		{
			GraphicFormat Format;
			DSVDimension ViewDimension;
			UINT Flags;
			union
			{
				DSVTexture1D Texture1D;
				DSVTexture1DArray Texture1DArray;
				DSVTexture2D Texture2D;
				DSVTexture2DArray Texture2DArray;
				DSVTexture2DMS Texture2DMS;
				DSVTexture2DMSArray Texture2DMSArray;
			};
		};
		
		public ref class DepthStencilView 
		{
			DECLARE_WRAPPED_INSTANCE(DepthStencilView,ID3D11DepthStencilView)
		};

		public struct RTVBuffer
		{
			union
			{
				UINT FirstElement;
				UINT ElementOffset;
			};
			union
			{
				UINT NumElements;
				UINT ElementWidth;
			};
		};

		public struct RTVTexture1D
		{
			UINT MipSlice;
		};

		public struct RTVTexture1DArray
		{
			UINT MipSlice;
			UINT FirstArraySlice;
			UINT ArraySize;
		};

		public struct RTVTexture2D
		{
			UINT MipSlice;
		};

		public struct RTVTexture2DMS
		{
			UINT UnusedField_NothingToDefine;
		};

		public struct RTVTexture2DArray
		{
			UINT MipSlice;
			UINT FirstArraySlice;
			UINT ArraySize;
		};

		public struct RTVTexture2DMSArray
		{
			UINT FirstArraySlice;
			UINT ArraySize;
		};

		public struct RTVTexture3D
		{
			UINT MipSlice;
			UINT FirstWSlice;
			UINT WSize;
		};

		public struct RenderTargetViewDescription
		{
			GraphicFormat Format;
			RTVDimension ViewDimension;
			union
			{
				RTVBuffer Buffer;
				RTVTexture1D Texture1D;
				RTVTexture1DArray Texture1DArray;
				RTVTexture2D Texture2D;
				RTVTexture2DArray Texture2DArray;
				RTVTexture2DMS Texture2DMS;
				RTVTexture2DMSArray Texture2DMSArray;
				RTVTexture3D Texture3D;
			};
		};


	}
}
