#pragma once

namespace GoblinEngine
{
  namespace DirectX
  {
    public ref class RenderTargetView
    {
    private:
      ID3D11RenderTargetView* origin = nullptr;
    public:
      RenderTargetView(IntPtr unmanagedObject);
      ~RenderTargetView();
    };

  }
}

