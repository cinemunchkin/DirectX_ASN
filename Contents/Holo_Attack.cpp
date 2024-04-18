#include "PreCompile.h"
#include "Holo_Attack.h"
#include "Holo_InGameValue.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineMath.h>
#include "Holo_Pointer.h"



AHolo_Attack::AHolo_Attack()
{

	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Atk_Renderer");

	Atk_Renderer = CreateDefaultSubObject<USpriteRenderer>("Atk_Renderer");
	Atk_Renderer->SetupAttachment(Root);
	Atk_Renderer->SetPivot(EPivot::BOT);


	SetRoot(Root);

	InputOff();
	//InputOn();

}

AHolo_Attack::~AHolo_Attack()
{


}

void AHolo_Attack::BeginPlay()
{
	Super::BeginPlay();

}

void AHolo_Attack::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}


void AHolo_Attack::SpawnAttack(float _DeltaTime)
{
	InputOn();
	
CreateMultiShot(_DeltaTime);

	//if (/*Á¶°Ç*/)
	//{
	//	CreateRangedShot(_DeltaTime)
	//}

}

void AHolo_Attack::CreateMultiShot(float _DeltaTime)
{	 
	MultiShot = GetWorld()->SpawnActor<AHolo_Atk_MultiShot>("MultiShot");
	
	CreateAttackAnimation("FX_Atk_Ina");


}	 
	 
void AHolo_Attack::CreateRangedShot(float _DeltaTime)
{
	RangedShot = GetWorld()->SpawnActor<AHolo_Atk_Ranged>("RangedShot");
}

void AHolo_Attack::CreateAttackAnimation(std::string _Name)
{
	Atk_Renderer->CreateAnimation(_Name, _Name, 0.1f, true, 0, 3);

}