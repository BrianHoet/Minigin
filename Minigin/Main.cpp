#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextComponent.h"
#include "TextureComponent.h"
#include "Scene.h"
#include <iostream>
#include "GameObject.h"
#include "BaseComponent.h"
#include "FPSCounterComponent.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	auto GameObj = std::make_shared<dae::GameObject>();
	
	auto go = std::make_shared<TextureComponent>();
	go->SetTexture("background.tga");
	go->SetPosition(GameObj->GetTransform().GetPosition().x, GameObj->GetTransform().GetPosition().y);
	GameObj->AddComponent(go);

	go = std::make_shared<TextureComponent>();
	go->SetTexture("logo.tga");
	go->SetPosition(216, 180);
	GameObj->AddComponent(go);
	
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto to = std::make_shared<TextComponent>("Programming 4 Assignment", font);
	to->SetPosition(80, 20);
	GameObj->AddComponent(to);

	auto fpsCounter = std::make_shared<FPSCounterComponent>("FPS", font);
	fpsCounter->SetPosition(0, 0);
	GameObj->AddComponent(fpsCounter);
	
	scene.Add(GameObj);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}