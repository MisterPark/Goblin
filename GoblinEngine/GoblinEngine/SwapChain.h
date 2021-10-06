#pragma once


namespace GoblinEngine
{
	namespace DirectX
	{
		ref class Texture2D;

		public ref class SwapChain
		{
		private:
			IDXGISwapChain* swapChain = nullptr;
		public:
			SwapChain(IntPtr unmanagedObject);
			~SwapChain();

			Texture2D^ GetTexture2D(UINT buffer);
		};

	}
}

