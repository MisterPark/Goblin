#pragma once


namespace GoblinEngine
{
	namespace DirectX
	{
		enum class ResourceDimension : unsigned;

		public ref class IResource  abstract 
		{
			DECLARE_WRAPPED_INSTANCE(IResource, ID3D11Resource)
		public:
			virtual ResourceDimension GetType() = 0;
			virtual void SetEvictionPriority(UINT evictionPriority) = 0;
			virtual UINT GetEvictionPriority() = 0;
		};
	}
}


