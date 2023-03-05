#pragma once

#include "Transform.h"
#include <memory>
#include <vector>
#include <iostream>
#include "BaseComponent.h"

namespace dae
{

	class BaseComponent;

	class GameObject final
	{
	public:
		void Update(float deltaTime);
		void FixedUpdate(float deltaTime);
		void Render() const;

		void AddComponent(std::shared_ptr<BaseComponent> component);
		void RemoveComponent(std::shared_ptr<BaseComponent> component);

		template <typename T>
		T* GetComponent()
		{
			for (auto component : m_pComponents)
			{
				if (typeid(*component) == typeid(T))
				{
					return static_cast<T*>(component);
				}
			}
			return nullptr;
		}
		
		void UpdateWorldPos();
		const glm::vec3& GetWorldPosition();

		void SetParent(GameObject* parent);
		void AddChild(GameObject* child);
		void RemoveChild(GameObject* childGameObject);

		glm::vec3 GetRelativePosition() const;
		void SetRelativePosition(glm::vec3 Pos);

		void FlagIsTrue();

		GameObject() = default;
		~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		bool m_dirtyFlag{ false };

		glm::vec3 m_WorldTransform{};
		glm::vec3 m_RelativeTransform{};

		GameObject* m_pParent{nullptr};
		std::vector<GameObject*> m_pChildren{};


		Transform m_Transform{};
		std::vector<std::shared_ptr<BaseComponent>> m_pComponents;

	};
}