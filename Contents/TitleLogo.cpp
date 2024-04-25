#include "PreCompile.h"
#include "TitleLogo.h"

ATitleLogo::ATitleLogo()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Renderer);
}

ATitleLogo::~ATitleLogo()
{
}


void ATitleLogo::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(580.0f, 240.0f, 100.0f));
	SetActorLocation(FVector(200.0f * 1.6, 240.0f*0.8,100.0f));
	Renderer->SetSprite("MainTitle_Eng.png");
	//Renderer->SetSprite("holocure.png");
}

void ATitleLogo::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
