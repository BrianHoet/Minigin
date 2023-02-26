#include "BaseComponent.h"

namespace dae
{

	BaseComponent::BaseComponent()
		:m_needsUpdate{},
		m_Transform{}
	{
	}

	BaseComponent::~BaseComponent()
	{
	}

	void BaseComponent::Update()
	{

	}

	void BaseComponent::Render() const
	{

	}

	void BaseComponent::SetPosition(float x, float y)
	{
		m_Transform.SetPosition(x, y, 0.0f);
	}
}