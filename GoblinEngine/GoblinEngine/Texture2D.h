#pragma once
#include "IResource.h"

namespace GoblinEngine
{
	namespace DirectX
	{
		public ref class Texture2D : IResource, DirectXWrapper<ID3D11Texture2D>
		{
		private:
			ID3D11Texture2D* texture2D;
		public:
			Texture2D(IntPtr unmanagedObject);
			~Texture2D();

			// IResource��(��) ���� ��ӵ�
			virtual ResourceDimension GetType();
			virtual void SetEvictionPriority(UINT evictionPriority);
			virtual UINT GetEvictionPriority();

		};

	}
}

