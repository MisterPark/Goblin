#include "pch.h"
#include "Texture2D.h"


ResourceDimension GoblinEngine::DirectX::Texture2D::GetType()
{
    D3D11_RESOURCE_DIMENSION dimension;
    origin->GetType(&dimension);

    return (ResourceDimension)dimension;
}

void GoblinEngine::DirectX::Texture2D::SetEvictionPriority(UINT evictionPriority)
{
  origin->SetEvictionPriority(evictionPriority);
}

UINT GoblinEngine::DirectX::Texture2D::GetEvictionPriority()
{
    return origin->GetEvictionPriority();
}