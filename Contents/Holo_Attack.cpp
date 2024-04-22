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

	InputOn();
	//InputOn();

}

AHolo_Attack::~AHolo_Attack()
{


}

void AHolo_Attack::BeginPlay()
{
	Super::BeginPlay();

	//CreateAttackAnimation("MultiShot");
	
	Atk_Renderer->SetAutoSize(3.0f, true);
	Atk_Renderer->SetOrder(ERenderOrder::Attack);

	AtkStateInit();

}

void AHolo_Attack::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AtkState.Update(_DeltaTime);
}




void AHolo_Attack::SpawnAttack(float _DeltaTime)
{
	

	Atk_Renderer->ChangeAnimation("MultiShot");


}
/*
레벨

actor ???
spawn pointer <- xxx

일단 만들어야함
생성을 해야햐ㅏㅁ

this가 자기자신이라는 뜻인데
이게 null이면
걍 자기자신이 없다는소리임
안만든거임
안만들고 찾으면
엑서스위반뜸

공격을 할꺼다
공격을 actor?
콜리전으로 할꺼아님?

공격키를 누르면

player가 공격을 스폰
그 공격은 콜리전과 렌더러를 가지고 있어야함



*/