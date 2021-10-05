#pragma once


namespace GoblinEngine
{
	namespace DirectX
	{
		enum class ResourceDimension : unsigned;

		public interface class IResource
		{
			virtual ResourceDimension GetType() = 0;
			virtual void SetEvictionPriority(UINT evictionPriority) = 0;
			virtual UINT GetEvictionPriority() = 0;
		};
	}
}


