#include "PreCompile.h"
#include "Player.h"
#include "Holo_InGameValue.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineMath.h>
#include "Holo_Pointer.h"



float4 APlayer::PlayerPos;

APlayer::APlayer()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::BOT);

	PointerDir = CreateDefaultSubObject<USpriteRenderer>("Pointer_Renderer");
	PointerDir->SetupAttachment(Root);
	PointerDir->SetPivot(EPivot::MAX);

	SetRoot(Root);

	InputOn();
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{

	Super::BeginPlay();

	//플레이어 생성
	CreatePlayerAnimation("Ina");

	//플레이어 auto size
	Renderer->SetAutoSize(1.7f, true);
	Renderer->SetOrder(ERenderOrder::Player);

	PointerDir->SetOrder(ERenderOrder::Pointer);
	//PointerDir->SetPosition(FVector{ PlayerPos.X, PlayerPos.Y, PlayerPos.Z - 100.0f });

	StateInit();
}

void APlayer::Tick(float _DeltaTime)
{

	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);

	PlayerPos = GetActorLocation();


	CheckMouseAimMode();
	ChangeMoveAimAtkDir();
	ChangeMouseAimAtkDir();
	

	//공격스폰
	PlayerAttackSpawn(_DeltaTime);

}


void APlayer::CreatePlayerAnimation(std::string _Name)
{

	Renderer->CreateAnimation(_Name + "_Idle", _Name, 0.1f, true, 0, 3);
	Renderer->CreateAnimation(_Name + "_Run", _Name, 0.1f, true, 24, 29);
}

void APlayer::CheckMouseAimMode()
{// 마우스 포인터
	if (false == AHolo_Pointer::MousePointerOn)
	{
		PointerDir->SetSprite("spr_arrow_1.png");
		PointerDir->SetAutoSize(1.0f, true);
	}
	else
	{
		PointerDir->SetSprite("spr_arrow_2.png");
		PointerDir->SetAutoSize(1.0f, true);
	}
}


//이건 AtkDir이긴 하지만.. 플레이어의 방향에 따른 공격방향이고... 
void APlayer::ChangeMoveAimAtkDir()
{
	if (false == AHolo_Pointer::MousePointerOn)
	{
		switch (PlayerDir)
		{
		case EPlayerDir::Up:
			Angle = 90.0f;
			PointerDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EPlayerDir::UpRight:
			Angle = 45.0f;
			PointerDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EPlayerDir::Right:
			Angle = 0.0f;
			PointerDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EPlayerDir::DownRight:
			Angle = 315.0f;
			PointerDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EPlayerDir::Down:
			Angle = 270.0f;
			PointerDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EPlayerDir::DownLeft:
			Angle = 225.0f;
			PointerDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EPlayerDir::Left:
			Angle = 180.0f;
			PointerDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EPlayerDir::UpLeft:
			Angle = 135.0f;
			PointerDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		default:
			break;
		}
	}
}

void APlayer::ChangeMouseAimAtkDir()
{

	if (true == AHolo_Pointer::MousePointerOn)
	{
		Angle = atan2f((Holo_InGameValue::PlayLevelMousePos.Y - APlayer::PlayerPos.Y), (Holo_InGameValue::PlayLevelMousePos.X - APlayer::PlayerPos.X)) * 180.0f / UEngineMath::PI;
		PointerDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });

		if (-90.0f <= Angle && 90.0f > Angle)
		{
			Renderer->SetDir(EEngineDir::Right);
		}
		else
		{
			Renderer->SetDir(EEngineDir::Left);
		}
	}
}


FVector APlayer::GetPlayerCurPos()
{

	PlayerPos = this -> GetActorLocation();
	FVector PlayerCurPos = PlayerPos;
	return PlayerCurPos;

}



void APlayer::PlayerAttackSpawn(float _DeltaTime)
{

	if (2.0f <= AttackTime)
	{
		
		//PlayerPos = GetActorLocation();
		Attack = GetWorld()->SpawnActor<AHolo_Attack>("Attack");
		Attack->SetActorLocation({ GetPlayerCurPos() });
		//Attack->SetActorLocation({ PlayerPos.X + 500, PlayerPos.Y - 200 });
		int a = 0;

	}
	/*else if (2.0f < AttackTime)
	{
		Attack->Destroy();
		AttackTime = 0.0f;	
		return;
	}*/
	AttackTime += _DeltaTime;
	
		


}