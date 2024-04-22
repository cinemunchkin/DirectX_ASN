
#include "PreCompile.h"
#include "PlayGameMode.h"
#include "Holo_InGameValue.h"
#include "Holo_Monster.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Camera.h>
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineBase/EngineRandom.h>

APlayGameMode::APlayGameMode()
{
}

APlayGameMode::~APlayGameMode()
{
}

void APlayGameMode::BeginPlay()
{
	Super::BeginPlay();

	float4 MapScale = UEngineTexture::FindRes("Holo_Stage_1_Back_Ground.png")->GetScale();

	CurIndex = { 0, 0 };
	float4 PlayerStartPos = IndexToCenterPos(CurIndex);

	// 카메라 세팅
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	float4 CameraPos = PlayerStartPos;
	CameraPos.Z = -500.0f;
	Camera->SetActorLocation(CameraPos);
	
	// 플레이어 생성
	Player = GetWorld()->SpawnActor<APlayer>("Player");
	//Player->SetName("Kronii");
	Player->SetName("Ina");

	Player->SetActorLocation(PlayerStartPos);

	// 커서 생성
	Cursor = GetWorld()->SpawnActor<AHolo_Pointer>("Cursor");
	AHolo_Pointer::MouseAimOn = false;
	AHolo_Pointer::CursorPos = GEngine->EngineWindow.GetScreenMousePos();
	Cursor->SetActorLocation(AHolo_Pointer::CursorPos);

	// 지면 생성
	for (int y = -1; y < 2; y++)
	{
		for (int x = -1; x < 2; x++)
		{
			std::shared_ptr<AHolo_PlayBack> BackGround = GetWorld()->SpawnActor<AHolo_PlayBack>("PlayBackGround");

			BackGround->SetActorScale3D(Holo_InGameValue::GroundTileSize);

			FIntPoint Point;
			Point.X = x;
			Point.Y = y;

			float4 Pos;
			Pos.X = Holo_InGameValue::GroundTileSize.X * x;
			Pos.Y = Holo_InGameValue::GroundTileSize.Y * y;

			Pos.X += Holo_InGameValue::GroundTileSize.hX();
			Pos.Y += Holo_InGameValue::GroundTileSize.hY();
			BackGround->SetActorLocation(Pos);

			BackGroundVector.push_back(BackGround);
		}
	}
}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AHolo_Pointer::CursorPos = GEngine->EngineWindow.GetScreenMousePos();
	Holo_InGameValue::PlayLevelMousePos = FVector{ APlayer::PlayerPos.X + AHolo_Pointer::CursorPos.X - 640, APlayer::PlayerPos.Y - AHolo_Pointer::CursorPos.Y + 360 };
	Cursor->SetActorLocation(Holo_InGameValue::PlayLevelMousePos);

	InfinityGroundCheck();

	//SpawnMonsterTimeSet(_DeltaTime, 0.0f, 20.0f, 5.0f, 
	//	"Shrimp", 1.0f, 8.0f, 2.0f, 0.35f, 6.0f, EMonsterMoveType::Follow, 
	//	false, 10);
	//SpawnMonsterTimeSet(_DeltaTime, 0.0f, 20.0f, 10.0f,
	//	"Shrimp", 1.0f, 8.0f, 2.0f, 0.35f, 6.0f, EMonsterMoveType::Follow,
	//	true, 10);
	//SpawnMonsterTimeSet(_DeltaTime, 20.0f, 40.0f, 5.0f, 
	//	"Deadbeat", 1.0f, 40.0f, 4.0f, 0.4f, 7.0f, EMonsterMoveType::Follow,
	//	false, 5);
	//SpawnMonsterTimeSet(_DeltaTime, 40.0f, 60.0f, 5.0f, 
	//	"Takodachi", 1.0f, 80.0f, 4.0f, 0.4f, 8.0f, EMonsterMoveType::Follow);
	//SpawnMonsterTimeSet(_DeltaTime, 60.0f, 80.0f, 5.0f, 
	//	"KFP", 1.0f, 20.0f, 2.0f, 1.0f, 3.0f, EMonsterMoveType::StraightToPlayer,
	//	true, 10);

	SpawnMonsterTimeSet(_DeltaTime, 3.0f, 20.0f, 5.0f,
		"Shubangelion", 1.5f, 20.0f, 2.0f, 0.5f, 3.0f, EMonsterMoveType::Follow,
		true, 10);

	/*
	void APlayGameMode::SpawnMonsterTimeSet(float _DeltaTime, float _SpawnBegin, float _SpawnEnd, float _Term, 
	std::string _Name, float _Size, float _Hp, float _Atk, float _Speed, float _Exp, EMonsterMoveType _MoveType, 
	bool _Group, int _Quantity)
{
	
	*/
	PlayTime += _DeltaTime;

	PlayDebugText();
}

void APlayGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void APlayGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}

float4 APlayGameMode::IndexToCenterPos(FIntPoint _Index)
{
	float4 Pos;
	Pos.X = Holo_InGameValue::GroundTileSize.X * _Index.X;
	Pos.Y = Holo_InGameValue::GroundTileSize.Y * _Index.Y;

	Pos.X += Holo_InGameValue::GroundTileSize.hX();
	Pos.Y += Holo_InGameValue::GroundTileSize.hY();

	return Pos;
}

FIntPoint APlayGameMode::PosToIndex(float4 _Pos)
{
	FIntPoint Index;

	float4 Location = _Pos;

	float4 Pos;
	Pos.X = Location.X / Holo_InGameValue::GroundTileSize.X;
	Pos.Y = Location.Y / Holo_InGameValue::GroundTileSize.Y;

	if (0 >= Pos.X)
	{
		Pos.X += -1;
	}
	if (0 >= Pos.Y)
	{
		Pos.Y += -1;
	}

	Index.X = Pos.X;
	Index.Y = Pos.Y;
	return Index;
}

void APlayGameMode::InfinityGroundCheck()
{
	FIntPoint Index = PosToIndex(APlayer::PlayerPos);

	if (Index.X != CurIndex.X || Index.Y != CurIndex.Y)
	{
		int GroundCount = 0;

		float4 MovePos;
		MovePos.X = Index.X * Holo_InGameValue::GroundTileSize.X;
		MovePos.Y = Index.Y * Holo_InGameValue::GroundTileSize.Y;

		for (int y = -1; y < 2; y++)
		{
			for (int x = -1; x < 2; x++)
			{
				std::shared_ptr<AHolo_PlayBack> BackGround = BackGroundVector[GroundCount];

				BackGround->SetActorScale3D(Holo_InGameValue::GroundTileSize);

				FIntPoint Point;
				Point.X = x;
				Point.Y = y;

				float4 Pos;
				Pos.X = Holo_InGameValue::GroundTileSize.X * x;
				Pos.Y = Holo_InGameValue::GroundTileSize.Y * y;

				Pos.X += Holo_InGameValue::GroundTileSize.hX();
				Pos.Y += Holo_InGameValue::GroundTileSize.hY();
				BackGround->SetActorLocation(Pos + MovePos);

				++GroundCount;
			}
		}

		CurIndex = Index;
	}
}

void APlayGameMode::RandomSpawnMonster(std::string _Name, float _Size, float _Hp, float _Atk, float _Speed, float _Exp, EMonsterMoveType _MoveType, 
	bool _Group, int _Quantity)
{
	if (0 >= _Quantity)
	{
		MsgBoxAssert("스폰하려는 몬스터의 수가 0 이하 입니다.");
		return;
	}

	FVector GroupToPlayerDir;
	
	for (int i = 0; i < _Quantity; i++)
	{
		std::shared_ptr<AHolo_Monster> Monster;

		Monster = GetWorld()->SpawnActor<AHolo_Monster>(_Name);
		Monster->GetRenderer()->SetAutoSize(_Size, true);
		Monster->GetRenderer()->ChangeAnimation(_Name);
		Monster->SetMonsterStatus(_Hp, _Atk, _Speed, _Exp, _MoveType);
		FVector GroupPos = RandomLocation(_Group);
		Monster->SetActorLocation(GroupPos);
		if (true == _Group)
		{
			if (false == GroupSpawn)
			{
				GroupToPlayerDir = Monster->CreateGroupToPlayerDir();
				Monster->SetToPlayerDir(GroupToPlayerDir);
				GroupSpawn = true;
			}
			else
			{
				Monster->SetToPlayerDir(GroupToPlayerDir);
			}
		}
		else
		{
			FVector Dir = APlayer::PlayerPos - Monster->GetActorLocation();
			Dir = Dir.Normalize2DReturn();
			Monster->SetToPlayerDir(Dir);
		}
	}
	GroupSpawn = false;
}

float4 APlayGameMode::RandomLocation(bool _Group)
{
	float4 MonsterPos;
	// 뭉쳐서 나오지 않을 때
	if (false == _Group)
	{
		MonsterPos = APlayer::PlayerPos;

		while (MonsterPos.X > (APlayer::PlayerPos.X - 300.0f) && MonsterPos.X < (APlayer::PlayerPos.X + 300.0f))
		{
			MonsterPos.X += UEngineRandom::MainRandom.RandomFloat(-5.0f, 5.0f) * 100.0f;
		}
		while (MonsterPos.Y > (APlayer::PlayerPos.Y - 250.0f) && MonsterPos.Y < (APlayer::PlayerPos.Y + 250.0f))
		{
			MonsterPos.Y += UEngineRandom::MainRandom.RandomFloat(-5.0f, 5.0f) * 100.0f;
		}
	}
	else
	{
		//뭉쳐서 나올 때 
		if (false == GroupSpawn)
		{
			GroupMonsterPos = APlayer::PlayerPos; 

			while (GroupMonsterPos.X > (APlayer::PlayerPos.X - 300.0f) && GroupMonsterPos.X < (APlayer::PlayerPos.X + 300.0f))
			{
				GroupMonsterPos.X += UEngineRandom::MainRandom.RandomFloat(-5.0f, 5.0f) * 100.0f;
			}
			while (GroupMonsterPos.Y > (APlayer::PlayerPos.Y - 250.0f) && GroupMonsterPos.Y < (APlayer::PlayerPos.Y + 250.0f))
			{
				GroupMonsterPos.Y += UEngineRandom::MainRandom.RandomFloat(-5.0f, 5.0f) * 100.0f;
			}
		}

		MonsterPos = GroupMonsterPos;

		MonsterPos.X += UEngineRandom::MainRandom.RandomFloat(-5.0f, 5.0f) * 10.0f;
		MonsterPos.Y += UEngineRandom::MainRandom.RandomFloat(-5.0f, 5.0f) * 10.0f;
	}
	
	return MonsterPos;
}

void APlayGameMode::SpawnMonsterTimeSet(float _DeltaTime, float _SpawnBegin, float _SpawnEnd, float _Term, 
	std::string _Name, float _Size, float _Hp, float _Atk, float _Speed, float _Exp, EMonsterMoveType _MoveType, 
	bool _Group, int _Quantity)
{
	if (PlayTime >= _SpawnBegin && PlayTime < _SpawnEnd)
	{
		if (SpawnTerm <= 0)
		{
			RandomSpawnMonster(_Name, _Size, _Hp, _Atk, _Speed, _Exp, _MoveType, _Group, _Quantity);
			SpawnTerm = _Term;
		}
		else
		{
			SpawnTerm -= _DeltaTime;
		}
	}
}

void APlayGameMode::PlayDebugText()
{
	AGameMode* ThisLevel = dynamic_cast<AGameMode*>(this);

	FIntPoint Index = PosToIndex(APlayer::PlayerPos);
	CurIndex = Index;
	
	//플레이어 위치
	UEngineDebugMsgWindow::PushMsg(std::format("PlayerPos : X : {}, Y : {}", APlayer::PlayerPos.X, APlayer::PlayerPos.Y));
	//플레이어가 있는 BackGround
	UEngineDebugMsgWindow::PushMsg(std::format("BackGroundIndex : {}, {}", Index.X, Index.Y));
	
	std::string PlayerDir = "";
	switch (Player->GetPlayerDir())
	{
	case EPlayerDir::Up:
		PlayerDir = "Up";
		break;
	case EPlayerDir::UpRight:
		PlayerDir = "UpRight";
		break;
	case EPlayerDir::UpLeft:
		PlayerDir = "UpLeft";
		break;
	case EPlayerDir::Right:
		PlayerDir = "Right";
		break;
	case EPlayerDir::Left:
		PlayerDir = "Left";
		break;
	case EPlayerDir::Down:
		PlayerDir = "Down";
		break;
	case EPlayerDir::DownRight:
		PlayerDir = "DownRight";
		break;
	case EPlayerDir::DownLeft:
		PlayerDir = "DownLeft";
		break;
	default:
		break;
	}
	//마지막으로 움직인 방향
	UEngineDebugMsgWindow::PushMsg(std::format("PlayerDir : {}", PlayerDir));
	//마우스모드 각도
	UEngineDebugMsgWindow::PushMsg(std::format("Angle : {}", Player->GetAngle()));
}