#pragma once
#include "IResource.h"

namespace GoblinEngine
{
	namespace DirectX
	{
		public ref class Texture2D : IResource
		{
			DECLARE_WRAPPED_INSTANCE(Texture2D, ID3D11Texture2D)

			// IResource��(��) ���� ��ӵ�
			virtual ResourceDimension GetType() override;
			virtual void SetEvictionPriority(UINT evictionPriority) override;
			virtual UINT GetEvictionPriority() override;


		};

	}
}

