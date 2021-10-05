#pragma once

namespace GoblinEngine
{
	namespace DirectX
	{
		ref class DepthStencilState;

		public ref class DeviceContext
		{
		private:
			ID3D11DeviceContext* deviceContext;
		public:
			DeviceContext(IntPtr unmanagedObject);
			~DeviceContext();

			void OMSetDepthStencilState(DepthStencilState state, UINT stencilRef);
		};
	}
}


