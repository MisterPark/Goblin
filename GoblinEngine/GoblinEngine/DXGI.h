#pragma once

namespace GoblinEngine
{
	namespace DirectX
	{
		ref struct AdapterDescription;
		ref struct ModeDescription;
		enum class GraphicFormat : unsigned;
		enum class GraphicModes : unsigned;

		public ref class GraphicOutput
		{
		private:
			IDXGIOutput* output;
		public:
			GraphicOutput(System::IntPtr unmanagedObject);
			~GraphicOutput();

			System::Collections::Generic::List<ModeDescription^>^ GetDisplayModeList(GraphicFormat format, GraphicModes mode);

		};

		public ref class GraphicAdapter
		{
		private:
			IDXGIAdapter* adapter;
		public:
			GraphicAdapter(System::IntPtr unmanagedObject);
			~GraphicAdapter();

			AdapterDescription^ GetDescription();
			GraphicOutput^ EnumOutputs(unsigned output);
		};

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

