#pragma once


namespace GoblinEngine
{
	namespace DirectX
	{
		public ref class SwapChain
		{
		private:
			IDXGISwapChain* swapChain;
		public:
			SwapChain(IntPtr unmanagedObject);
			~SwapChain();
		};

	}
}

