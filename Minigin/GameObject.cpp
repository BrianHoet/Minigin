#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include <algorithm>

void GameObject::Update()
{
	for (std::shared_ptr<BaseComponent> pComponent : m_Components)
	{
		pComponent->Update();
	}
}

void GameObject::Render() const
{
	for (std::shared_ptr<BaseComponent> pComponent : m_Components)
	{
		pComponent->Render();
	}
}

void GameObject::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}

dae::Transform GameObject::GetTransform() const
{
	return m_Transform;
}

void GameObject::AddComponent(std::shared_ptr<BaseComponent> component)
{
	m_Components.push_back(component);
}

std::shared_ptr<BaseComponent> GameObject::GetComponent(std::shared_ptr<BaseComponent> component)
{
	return 0;
}

void GameObject::RemoveComponent(std::shared_ptr<BaseComponent> component)
{
	m_Components.erase(std::remove(m_Components.begin(), m_Components.end(), component), m_Components.end());
}

GameObject::~GameObject()
{
}
