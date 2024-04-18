#include "PreCompile.h"
#include "Holo_PlayBack.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>

AHolo_PlayBack::AHolo_PlayBack()
{
}

AHolo_PlayBack::~AHolo_PlayBack()
{
}

void AHolo_PlayBack::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("Holo_Stage_1_Back_Ground.png");

}

void AHolo_PlayBack::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
