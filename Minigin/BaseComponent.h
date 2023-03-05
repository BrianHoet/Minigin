#pragma once
#include "Transform.h"
#include <memory>

namespace dae
{
	class GameObject;

	class BaseComponent
	{
	public:
		BaseComponent();
		virtual ~BaseComponent();
		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) = delete;


		virtual void Update(float);
		virtual void FixedUpdate(float);
		virtual void Render() const;


	private:

	protected:
		bool m_needsUpdate;
		GameObject* m_pOwner{ nullptr };
	};
}