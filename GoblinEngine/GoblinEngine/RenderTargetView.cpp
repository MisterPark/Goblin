#include "pch.h"
#include "RenderTargetView.h"

GoblinEngine::DirectX::RenderTargetView::RenderTargetView(IntPtr unmanagedObject)
{
  origin = (ID3D11RenderTargetView*)unmanagedObject.ToPointer();
}

GoblinEngine::DirectX::RenderTargetView::~RenderTargetView()
{
  if (origin == nullptr) return;
  origin->Release();
  origin = nullptr;
}
