#include "RotationComponent.h"

#include <iostream>

#include "GameObject.h"

dae::RotationComponent::RotationComponent(GameObject* owner, float offset, float rotationSpeed)
	:m_Offset(offset)
	,m_RotationSpeed(rotationSpeed)
	,m_Center(owner->GetWorldPosition())
{
	m_pOwner = owner;
}

void dae::RotationComponent::Update(float deltaTime)
{
	m_Angle += m_RotationSpeed * deltaTime;
	
	float posX = m_Center.x + m_Offset * cosf(m_Angle);
	float posY = m_Center.y + m_Offset * sinf(m_Angle);
	m_pOwner->SetRelativePosition(glm::vec3{ posX, posY, 0 });

}


