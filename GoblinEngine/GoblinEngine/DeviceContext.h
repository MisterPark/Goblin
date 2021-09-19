#pragma once

namespace GoblinEngine
{
	namespace DirectX
	{
		public ref class DeviceContext
		{
		private:
			ID3D11DeviceContext* deviceContext;
		public:
			DeviceContext(IntPtr unmanagedObject);
			~DeviceContext();
		};
	}
}


