#include "PreCompile.h"
#include "Player.h"
#include "Holo_InGameValue.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineMath.h>
#include "Holo_Pointer.h"


float4 APlayer::PlayerPos = float4::Zero;

APlayer::APlayer()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::BOT);

	AtkDir = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	AtkDir->SetupAttachment(Root);
	AtkDir->SetPivot(EPivot::MAX);

	SetRoot(Root);

	InputOn();
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	Super::BeginPlay();

	CreatePlayerAnimation("Ame");
	CreatePlayerAnimation("Aqua");
	CreatePlayerAnimation("Ayame");
	CreatePlayerAnimation("AZKiPortrait");
	CreatePlayerAnimation("Kronii");

	CreatePlayerAnimation("Ina");



	Renderer->SetAutoSize(1.7f, true);
	Renderer->SetOrder(ERenderOrder::Player);

	AtkDir->SetOrder(ERenderOrder::Player);
	AtkDir->SetPosition(FVector{ PlayerPos.X, PlayerPos.Y + 20.0f });

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


	PlayerAttack(_DeltaTime);
}

void APlayer::CreatePlayerAnimation(std::string _Name)
{

	Renderer->CreateAnimation(_Name + "_Idle", _Name, 0.1f, true, 0, 3);
	Renderer->CreateAnimation(_Name + "_Run", _Name, 0.1f, true, 24, 29);
}

void APlayer::CheckMouseAimMode()
{// 마우스 포인터
	if (false == AHolo_Pointer::MouseAimOn)
	{
		AtkDir->SetSprite("spr_arrow_1.png");
		AtkDir->SetAutoSize(1.0f, true);
	}
	else
	{
		AtkDir->SetSprite("spr_arrow_2.png");
		AtkDir->SetAutoSize(1.0f, true);
	}
}

void APlayer::ChangeMoveAimAtkDir()
{
	if (false == AHolo_Pointer::MouseAimOn)
	{
		switch (PlayerDir)
		{
		case EPlayerDir::Up:
			Angle = 90.0f;
			AtkDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EPlayerDir::UpRight:
			Angle = 45.0f;
			AtkDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EPlayerDir::Right:
			Angle = 0.0f;
			AtkDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EPlayerDir::DownRight:
			Angle = 315.0f;
			AtkDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EPlayerDir::Down:
			Angle = 270.0f;
			AtkDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EPlayerDir::DownLeft:
			Angle = 225.0f;
			AtkDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EPlayerDir::Left:
			Angle = 180.0f;
			AtkDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EPlayerDir::UpLeft:
			Angle = 135.0f;
			AtkDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		default:
			break;
		}
	}
}

void APlayer::ChangeMouseAimAtkDir()
{
	if (true == AHolo_Pointer::MouseAimOn)
	{
		Angle = atan2f((Holo_InGameValue::PlayLevelMousePos.Y - APlayer::PlayerPos.Y), (Holo_InGameValue::PlayLevelMousePos.X - APlayer::PlayerPos.X)) * 180.0f / UEngineMath::PI;
		AtkDir->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });

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





void APlayer::PlayerAttack(float _DeltaTime)
{
	int a = 0;

	if (true == IsPress(VK_NUMPAD0))
	{
	
		Atk_ptr->SpawnAttack(_DeltaTime);

		


		//SpawnAttack(_DeltaTime);
	}

}