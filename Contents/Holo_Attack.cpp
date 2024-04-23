#include "PreCompile.h"
#include "Holo_Attack.h"
#include "Holo_InGameValue.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineMath.h>
#include "Holo_Pointer.h"
#include "Player.h"

EPlayerDir AHolo_Attack::PlayerDir = EPlayerDir::None;
//이거 용법이 뭘까

//EActorDir AMelee::PlayerDir = EActorDir::None;;

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

//	CreateAttackAnimation("MultiShot");

	Atk_Renderer->CreateAnimation("FX_Atk_Ina", "FX_Atk_Ina", 0.1f, true,0,10);
	Atk_Renderer->ChangeAnimation("FX_Atk_Ina");
	Atk_Renderer->SetAutoSize(3.0f, true);
	Atk_Renderer->SetOrder(ERenderOrder::Attack);

	AtkStateInit();

	
	// 공격 방향설정 -> 요거 마우스 쫓아가는 것만 남기기 (수정)
	if (false == AHolo_Pointer::MousePointerOn)
	{
		AttackDir();
	}
	/*else if (true == AHolo_Pointer::MousePointerOn)
	{
		AttackAimDir();
	}*/

	SetActorLocation(AttackDir());

	//SetActorLocation(GetActorLocation());
	

}

void AHolo_Attack::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	
	//std::shared_ptr<APlayer> Player;
	//SetActorLocation(PlayerPos);
	//AtkState.Update(_DeltaTime);
}

FVector AHolo_Attack::AttackDir()
{
	if (AHolo_Attack::PlayerDir == EPlayerDir::Right)
	{
		SetActorRotation(FVector{ 0.0f, 0.0f, 0.0f });
		AtkDir = { 1,0,0,0 };
	}

	else if (AHolo_Attack::PlayerDir == EPlayerDir::Up)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,90.0f });
		AtkDir = { 0,1,0,0 };
	}
	else if (AHolo_Attack::PlayerDir == EPlayerDir::Down)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,270.0f });
		AtkDir = { 0,-1,0,0 };
	}
	else if (AHolo_Attack::PlayerDir == EPlayerDir::Left)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,180.0f });
		AtkDir = { -1,0,0,0 };
	}
	else if (AHolo_Attack::PlayerDir == EPlayerDir::UpRight)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,45.0f });
		AtkDir = { 1,1,0,0 };
	}
	else if (AHolo_Attack::PlayerDir == EPlayerDir::UpLeft)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,135.0f });
		AtkDir = { -1,1,0,0 };
	}
	else if (AHolo_Attack::PlayerDir == EPlayerDir::DownRight)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,315.0f });
		AtkDir = { 1,-1,0,0 };
	}
	else if (AHolo_Attack::PlayerDir == EPlayerDir::DownLeft)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,225.0f });
		AtkDir = { -1,-1,0,0 };
	}

	AtkDir = AtkDir.Normalize3DReturn();
	return FVector::Zero;
}


void AHolo_Attack::AtkStateInit()
{

	AtkState.CreateState("MultiShot");
	AtkState.CreateState("RangedShot");

	AtkState.SetUpdateFunction("MultiShot");

	AtkState.SetUpdateFunction("MultiShot", std::bind(&AHolo_Attack::MultiShotInit, this, std::placeholders::_1));




	USpriteRenderer* MyAtkRender = Atk_Renderer;

	AtkState.SetStartFunction("MultiShot", [=]
		{
			MyAtkRender->ChangeAnimation(Name + "_MultiShot");
		}
	);

	AtkState.SetUpdateFunction("RangedShot", std::bind(&AHolo_Attack::RangedShotInit, this, std::placeholders::_1));

	AtkState.SetStartFunction("RangedShot", std::bind(&AHolo_Attack::RangedShotStart, this));

	//AtkState.ChangeState("MultiShot");


}


void AHolo_Attack::MultiShotInit(float _DeltaTime)
{

	if (true == IsPress(VK_NUMPAD0))
	{
		AtkState.ChangeState("MultiShot");
		return;
	}

}


void AHolo_Attack::RangedShotInit(float _DeltaTime)
{

}


void AHolo_Attack::RangedShotStart()
{
	Atk_Renderer->ChangeAnimation(Name + "_RangedShot");

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