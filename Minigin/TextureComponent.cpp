#include "TextureComponent.h"
#include "Renderer.h"
#include "GameObject.h"
#include "ResourceManager.h"

TextureComponent::TextureComponent()
{
}

void TextureComponent::Update()
{
}

void TextureComponent::Render() const
{
	//const auto& pos = m_OwnerOfComponent.GetTransform().GetPosition();
	dae::Renderer::GetInstance().RenderTexture(*m_Texture, m_Transform.GetPosition().x, m_Transform.GetPosition().y);
	
}

void TextureComponent::SetTexture(const std::string& filename)
{
	m_Texture = ResourceManager::GetInstance().LoadTexture(filename);
}