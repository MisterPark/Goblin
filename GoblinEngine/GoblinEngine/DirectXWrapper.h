#pragma once

namespace GoblinEngine
{
	namespace DirectX
	{
		template<class T>
		public ref class DirectXWrapper
		{
		private:
			T* origin;
		public:
			T* ToOrigin()
			{
				return origin;
			}

			IntPtr ToPointer()
			{
				return (IntPtr)origin;
			}
			DirectXWrapper()
			{

			}

			inline DirectXWrapper(IntPtr unmanagedObject)
			{
				origin = (T*)unmanagedObject.ToPointer();
			};

			virtual ~DirectXWrapper()
			{
				if (origin == nullptr) return;
				origin->Release();
				origin = nullptr;
			}
		};
	}
}
