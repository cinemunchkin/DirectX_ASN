#include "PreCompile.h"
#include "Holo_Monster.h"
#include "Player.h"

AHolo_Monster::AHolo_Monster()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetPivot(EPivot::BOT);

	SetRoot(Renderer);
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

	Renderer->SetAutoSize(1.0f, true);
	Renderer->ChangeAnimation(Name);
	Renderer->SetOrder(ERenderOrder::MonsterUp);
}


void AHolo_Monster::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Move(_DeltaTime, MoveType);

	if (0 > Dir.X)
	{
		Renderer->SetDir(EEngineDir::Left);
	}
	else
	{
		Renderer->SetDir(EEngineDir::Right);
	}

	CheckPosComparePlayer();
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
	FVector GroupDir = APlayer::PlayerPos - GetActorLocation();
	GroupDir = GroupDir.Normalize2DReturn();
	return GroupDir;
}

void AHolo_Monster::CreateHolo_MonsterAnimation(std::string _Name)
{
	Renderer->CreateAnimation(_Name, _Name, 0.1f, true, 0, 2);
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
		Renderer->SetOrder(ERenderOrder::MonsterUp);
	}
	else
	{
		Renderer->SetOrder(ERenderOrder::MonsterDown);
	}
}