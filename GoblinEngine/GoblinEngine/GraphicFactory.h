#pragma once

namespace GoblinEngine
{
	namespace DirectX
	{
		ref class GraphicAdapter;

		public ref class GraphicFactory
		{
		private:
			IDXGIFactory* factory;
		public:
			GraphicFactory();
			~GraphicFactory();

			GraphicAdapter^ EnumAdapters(unsigned adapter);

		};
	}
}

