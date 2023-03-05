#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include <algorithm>

namespace dae
{
	void GameObject::Update(float deltaTime)
	{
		for (std::shared_ptr<BaseComponent> pComponent : m_pComponents)
		{
			pComponent->Update(deltaTime);
		}
	}

	void GameObject::FixedUpdate(float deltaTime)
	{
		for (std::shared_ptr<BaseComponent> pComponent : m_pComponents)
		{
			pComponent->FixedUpdate(deltaTime);
		}
	}

	void GameObject::Render() const
	{
		for (std::shared_ptr<BaseComponent> pComponent : m_pComponents)
		{
			pComponent->Render();
		}
	}

	void GameObject::UpdateWorldPos()
	{
		if (m_dirtyFlag)
		{
			if (m_pParent == nullptr)
				m_WorldTransform = m_RelativeTransform;
			else
				m_WorldTransform = m_pParent->GetWorldPosition() + m_RelativeTransform;

			m_dirtyFlag = false;
			
		}
	}

	void GameObject::AddComponent(std::shared_ptr<BaseComponent> component)
	{
		m_pComponents.push_back(component);
	}

	void dae::GameObject::RemoveComponent(std::shared_ptr<BaseComponent> component)
	{
		m_pComponents.erase(std::remove(m_pComponents.begin(), m_pComponents.end(), component), m_pComponents.end());
	}

	void GameObject::SetParent(GameObject* parent)
	{
		if(m_pParent)
		{
			m_pParent->RemoveChild(this);
		}
		m_pParent = parent;

		UpdateWorldPos();

	}

	void GameObject::AddChild(GameObject* child)
	{
		m_pChildren.push_back(child);
		child->SetParent(this);
	}

	void GameObject::RemoveChild(GameObject* childGameObject)
	{
		m_pChildren.erase(std::remove(m_pChildren.begin(), m_pChildren.end(), childGameObject), m_pChildren.end());
	}

	const glm::vec3& GameObject::GetWorldPosition()
	{
		if (m_dirtyFlag)
			UpdateWorldPos();
		return m_WorldTransform;
	}

	

	glm::vec3 GameObject::GetRelativePosition() const
	{
		return m_RelativeTransform;
	}

	void GameObject::SetRelativePosition(glm::vec3 Pos)
	{
		m_RelativeTransform = Pos;

		m_dirtyFlag = true;
		for (auto child : m_pChildren)
		{
			child->FlagIsTrue();
		}
	}

	void GameObject::FlagIsTrue()
	{
		m_dirtyFlag = true;
	}

	GameObject::~GameObject()
	{
	}
}