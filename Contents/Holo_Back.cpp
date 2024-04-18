#include "PreCompile.h"
#include "Holo_Back.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include "Holo_ContentsEnum.h"

AHolo_Back::AHolo_Back()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Renderer);
}

AHolo_Back::~AHolo_Back()
{
}

void AHolo_Back::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(ERenderOrder::Holo_Back);
}

void AHolo_Back::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
