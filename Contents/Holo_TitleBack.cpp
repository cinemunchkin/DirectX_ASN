#include "PreCompile.h"
#include "Holo_TitleBack.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>

AHolo_TitleBack::AHolo_TitleBack()
{
}

AHolo_TitleBack::~AHolo_TitleBack()
{
}

void AHolo_TitleBack::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(1280.0f, 720.0f, 100.0f));

	Renderer->SetSprite("menu_charselecBG_0.png");
}

void AHolo_TitleBack::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}