#include "pch.h"
#include "Texture2D.h"

GoblinEngine::DirectX::Texture2D::Texture2D(IntPtr unmanagedObject)
    :DirectXWrapper(unmanagedObject)
{
}

GoblinEngine::DirectX::Texture2D::~Texture2D()
{
}

ResourceDimension GoblinEngine::DirectX::Texture2D::GetType()
{
    D3D11_RESOURCE_DIMENSION dimension;
    texture2D->GetType(&dimension);

    return (ResourceDimension)dimension;
}

void GoblinEngine::DirectX::Texture2D::SetEvictionPriority(UINT evictionPriority)
{
    texture2D->SetEvictionPriority(evictionPriority);
}

UINT GoblinEngine::DirectX::Texture2D::GetEvictionPriority()
{
    return texture2D->GetEvictionPriority();
}
