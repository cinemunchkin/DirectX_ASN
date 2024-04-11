#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>

//std::vector<std::shared_ptr<APlayer>> BackList;

APlayer::APlayer()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	InputOn();
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	Super::BeginPlay();

		Renderer->CreateAnimation("Ina_Idle", "Player_Ina", 0.25f, true, 7, 10);
		//Renderer->CreateAnimation("Die", "Die");
		Renderer->CreateAnimation("Ina_Run", "Player_Ina" ,0.1f, true, 0, 6);

		StateInit();
		Renderer->SetOrder(ERenderOrder::Player);


}


void APlayer::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);
	
	
}




