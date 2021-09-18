#pragma once
using namespace System;

namespace GoblinEngine
{
	namespace DirectX
	{
		public ref struct BufferDescription
		{
			unsigned int ByteWidth;
			Usage Usage;
			unsigned int BindFlags;
			unsigned int CPUAccessFlags;
			unsigned int MiscFlags;
			unsigned int StructureByteStride;
		};

		public ref struct SubresourceData
		{
			IntPtr pSysMem;
			unsigned SysMemPitch;
			unsigned SysMemSlicePitch;
		};

		public ref struct MappedSubresource
		{
			IntPtr pData;
			unsigned RowPitch;
			unsigned DepthPitch;
		};


	}
}
