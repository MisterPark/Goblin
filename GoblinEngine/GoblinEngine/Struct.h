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

	}
}
