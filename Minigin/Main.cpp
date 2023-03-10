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
#include "RotationComponent.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto GameObjBackGround = std::make_shared<dae::GameObject>();
	auto go = std::make_shared<dae::TextureComponent>(GameObjBackGround.get());
	go->SetTexture("background.tga");
	GameObjBackGround->SetRelativePosition(GameObjBackGround->GetWorldPosition());
	GameObjBackGround->AddComponent(go);

	auto GameObjLogo = std::make_shared<dae::GameObject>();
	auto go2 = std::make_shared<dae::TextureComponent>(GameObjLogo.get());
	go2->SetTexture("logo.tga");
	GameObjLogo->SetRelativePosition(glm::vec3{ 216, 180 ,0});
	GameObjLogo->AddComponent(go2);

	auto GameObjText = std::make_shared<dae::GameObject>();
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto to = std::make_shared<dae::TextComponent>("Programming 4 Assignment", font, GameObjText.get());
	GameObjText->SetRelativePosition(glm::vec3{ 80, 20, 0 });
	GameObjText->AddComponent(to);

	auto GameObjFps = std::make_shared<dae::GameObject>();
	auto fpsFont = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 24);
	auto fpsCounter = std::make_shared<dae::FPSCounterComponent>("FPS", fpsFont, GameObjFps.get());
	GameObjFps->SetRelativePosition(glm::vec3{ 0, 0 ,0 });
	GameObjFps->AddComponent(fpsCounter);

	auto GameObjBomberManTex = std::make_shared<dae::GameObject>();
	GameObjBomberManTex->SetRelativePosition(glm::vec3{300, 380 ,0 });
	auto TextureCpBomberman = std::make_shared<dae::TextureComponent>(GameObjBomberManTex.get());
	auto RotationCpBomberman = std::make_shared<dae::RotationComponent>(GameObjBomberManTex.get(), 20.f ,4.f);
	TextureCpBomberman->SetTexture("BomberMan_Running.png");
	GameObjBomberManTex->AddComponent(TextureCpBomberman);
	GameObjBomberManTex->AddComponent(RotationCpBomberman);

	auto GameObjBallon = std::make_shared<dae::GameObject>();
	auto TextureCpBallon = std::make_shared<dae::TextureComponent>(GameObjBallon.get());
	auto RotationCpBallon = std::make_shared<dae::RotationComponent>(GameObjBallon.get(), 20.f, -5.f);
	TextureCpBallon->SetTexture("BomberMan_Ballon.png");
	GameObjBallon->AddComponent(TextureCpBallon);
	GameObjBallon->AddComponent(RotationCpBallon);

	//AddingScene
	scene.Add(GameObjBackGround);
	scene.Add(GameObjLogo);
	scene.Add(GameObjText);
	scene.Add(GameObjFps);
	scene.Add(GameObjBomberManTex);
	scene.Add(GameObjBallon);

	//Children
	GameObjBackGround->AddChild(GameObjLogo.get());
	GameObjBackGround->AddChild(GameObjText.get());
	GameObjBackGround->AddChild(GameObjFps.get());
	GameObjBomberManTex->AddChild(GameObjBallon.get());
}

int main(int, char*[])
{
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}