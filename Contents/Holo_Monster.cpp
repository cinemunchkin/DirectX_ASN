#include "PreCompile.h"
#include "Holo_Monster.h"
#include "Player.h"
#include <EngineCore/Collision.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

AHolo_Monster::AHolo_Monster()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Render");

	Mon_Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Mon_Renderer->SetupAttachment(Root);
	// 이게 부모자식 만드는 구조?

	UCollision* Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetupAttachment(Root);
	Collision->SetScale(FVector(64.0f,80.0f, 100.0f));
	Collision->SetCollisionGroup(ECollisionOrder::Monster);
	Collision->SetCollisionType(ECollisionType::Rect);

	Mon_Renderer->SetPivot(EPivot::BOT);



	//Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//Renderer->SetPivot(EPivot::BOT);

	SetRoot(Root);
}

AHolo_Monster::~AHolo_Monster()
{
}

void AHolo_Monster::BeginPlay()
{
	Super::BeginPlay();

	CreateHolo_MonsterAnimation("Shrimp");
	CreateHolo_MonsterAnimation("Deadbeat");
	CreateHolo_MonsterAnimation("Takodachi");
	CreateHolo_MonsterAnimation("KFP");

	CreateHolo_MonsterAnimation("Shubangelion");


	Mon_Renderer->SetAutoSize(2.0f, true);
	Mon_Renderer->ChangeAnimation(Name);
	Mon_Renderer->SetOrder(ERenderOrder::MonsterUp);

	/*Renderer->SetAutoSize(2.0f, true);
	Renderer->ChangeAnimation(Name);
	Renderer->SetOrder(ERenderOrder::MonsterUp);*/
}


void AHolo_Monster::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


	Move(_DeltaTime, MoveType);





	CheckPosComparePlayer();
	MonsterDirCheck();




}

void AHolo_Monster::MonsterDirCheck()
{

	if (0 > Dir.X)
	{
		Mon_Renderer->SetDir(EEngineDir::Left);
	}
	else
	{
		Mon_Renderer->SetDir(EEngineDir::Right);
	}

}

void AHolo_Monster::SetMonsterStatus(float _Hp, float _Atk, float _Speed, float _Exp, EMonsterMoveType _MoveType)
{
	Hp = _Hp;
	Atk = _Atk;
	Speed = _Speed;
	CalSpeed = 200.0f * Speed;
	Exp = _Exp;
	MoveType = _MoveType;
}

FVector AHolo_Monster::CreateGroupToPlayerDir()
{
	//FVector GroupDir = APlayer::PlayerPos - GetActorLocation();
	FVector GroupDir = APlayer::PlayerPos - GetActorLocation();
	GroupDir = GroupDir.Normalize2DReturn();
	return GroupDir;
}

void AHolo_Monster::CreateHolo_MonsterAnimation(std::string _Name)
{
	Mon_Renderer->CreateAnimation(_Name, _Name, 0.1f, true, 0,4 );
	/*
	if(_name이 오리면 0~7까지 돌도록)
	*/
}

void AHolo_Monster::Move(float _DeltaTime, EMonsterMoveType _MoveType)
{
	FVector Holo_MonsterPos = GetActorLocation();

	switch (_MoveType)
	{
	case EMonsterMoveType::Follow:
		Dir = APlayer::PlayerPos - Holo_MonsterPos;
		Dir = Dir.Normalize2DReturn();
		break;
	case EMonsterMoveType::StraightToPlayer:
		Dir = ToPlayerDir;
		break;
	case EMonsterMoveType::StraightToUp:
		break;
	case EMonsterMoveType::StraightToDown:
		break;
	case EMonsterMoveType::StraightToRight:
		break;
	case EMonsterMoveType::StraightToLeft:
		break;
	case EMonsterMoveType::Stop:
		break;
	default:
		break;
	}

	AddActorLocation(Dir * _DeltaTime * CalSpeed);
}

void AHolo_Monster::CheckPosComparePlayer()
{
	if (APlayer::PlayerPos.Y <= GetActorLocation().Y)
	{
		Mon_Renderer->SetOrder(ERenderOrder::MonsterUp);
	}
	else
	{
		Mon_Renderer->SetOrder(ERenderOrder::MonsterDown);
	}
}