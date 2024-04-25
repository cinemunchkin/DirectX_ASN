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
	//SetActorLocation(FVector(200.0f * 1.5, 240.0f,100.0f));
	//여긴 타이틀의 배경!

	Renderer->SetSprite("TitleBack_FX_1.png");
	//Renderer->CreateAnimation("TitleBack_FX", "TitleBack_FX", 1.0f, true, 0, 2);
	//Renderer->ChangeAnimation("TitleBack_FX");


	
	//Renderer->CreateAnimation("")

	
}

void AHolo_TitleBack::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}