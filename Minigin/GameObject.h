#pragma once

#include "Transform.h"
#include <memory>
#include <vector>
#include <iostream>
#include "Transform.h"
#include "BaseComponent.h"



using namespace dae;


	class BaseComponent;

	class GameObject final
	{
	public:
		virtual void Update();
		virtual void Render() const;

		void SetPosition(float x, float y);
		Transform GetTransform() const;

		void AddComponent(std::shared_ptr<BaseComponent> component);
		std::shared_ptr<BaseComponent> GetComponent(std::shared_ptr<BaseComponent> component);
		void RemoveComponent(std::shared_ptr<BaseComponent> component);


		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_Transform{};
		std::vector<std::shared_ptr<BaseComponent>> m_Components;
	};
