#pragma once

namespace GoblinEngine
{
	namespace DirectX
	{
		public ref class GraphicFactory
		{
		private:
			IDXGIFactory* factory;
		public:
			GraphicFactory();
		};
	}
}

