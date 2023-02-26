#pragma once
#include "GameObject.h"
#include "Transform.h"

using namespace dae;


	class BaseComponent
	{
	public:
		BaseComponent();
		virtual ~BaseComponent();
		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) = delete;


		virtual void Update();
		virtual void Render() const;
		void SetPosition(float x, float y);


	private:

	protected:
		bool m_needsUpdate;
		Transform m_Transform;
	};
