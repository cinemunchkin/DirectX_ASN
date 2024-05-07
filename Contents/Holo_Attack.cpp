#include "PreCompile.h"
#include "Holo_Attack.h"
#include "Holo_InGameValue.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineMath.h>
#include "Holo_Pointer.h"
#include "Player.h"
#include "EngineCore/Image.h"

//EPlayerDir AHolo_Attack::PlayerDir = EPlayerDir::None;
//이거 용법이 뭘까

//EActorDir AMelee::PlayerDir = EActorDir::None;;

AHolo_Attack::AHolo_Attack()
{

	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Atk_Renderer");

	Atk_Renderer = CreateDefaultSubObject<USpriteRenderer>("Atk_Renderer");
	Atk_Renderer->SetupAttachment(Root);
	Atk_Renderer->SetPivot(EPivot::LEFTBOTTOM);

	Atk_Collision = CreateDefaultSubObject<UCollision>("Collision");
	Atk_Collision->SetupAttachment(Root);
	Atk_Collision->SetScale(FVector(256.0f, 32.0f, 100.0f));
	Atk_Collision->SetPosition(FVector(10.0f, 50.0f));

	Atk_Collision->SetCollisionGroup(ECollisionOrder::Attack);
	Atk_Collision->SetCollisionType(ECollisionType::Rect);

	

	SetRoot(Root);

	InputOn();
	//InputOn();
}

AHolo_Attack::~AHolo_Attack()
{
	Destroy();
}

void AHolo_Attack::BeginPlay()
{
	Super::BeginPlay();

//	CreateAttackAnimation("MultiShot");
	//오늘 공격애니메이션 부순다
	Atk_Renderer->CreateAnimation("FX_Atk_Ina", "FX_Atk_Ina", 0.07f, true,1,5);
	Atk_Renderer->SetAutoSize(2.0f, true);
	Atk_Renderer->SetOrder(ERenderOrder::Attack);

	Atk_Renderer->ChangeAnimation("FX_Atk_Ina");
	//AtkStateInit();
	

	/*if (false == AHolo_Pointer::MousePointerOn)
	{
		AttackDir();
	}*/
	/*else if (true == AHolo_Pointer::MousePointerOn)
	{
		AttackAimDir();
	}*/

	}

void AHolo_Attack::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	//SetActorRotation(AttackDir());
	SetActorRotation(AttackDir());
		

	//if (DestroyTime >= 0.1f)

	AtkAnimationCheck();
	AtkCollisionCheck();

}




void AHolo_Attack::AtkAnimationCheck()
{
		if (true == Atk_Renderer->IsCurAnimationEnd())
	{
		this->Destroy();
		Atk_State::Atk_Animation_End;
		return;
	}
	else
	{
		return;
	}
}


//오늘 이거 무조건 해결한다 
// 애니메이션 방향 무조건 해결한다


void AHolo_Attack::AtkCollisionCheck()
{

	Atk_Collision->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision>_Collision)
		{
			_Collision->GetActor()->Destroy();
			int a = 0;
		}
	);
	Atk_Collision->CollisionStay(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision>_Collision)
		{
			_Collision->GetActor()->Destroy();
			int a = 0;
		}
	);
	Atk_Collision->CollisionExit(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision>_Collision)
		{
			_Collision->GetActor()->Destroy();
			int a = 0;
		}
	);

	//else 
	//{
	//	DestroyTime += _DeltaTime;
	//}
	// 


	// 
	////FVector scale = GetActorScale3D();
	//SetActorScale3D(FVector{ -scale.X, scale.Y,scale.Z, 0.0f });


	//std::shared_ptr<APlayer> Player;
	//SetActorLocation(PlayerPos);
	//AtkState.Update(_DeltaTime);

}




// 마우스Dir = 플레이어 Dir = AttackDir 로 만들어야함
FVector AHolo_Attack::AttackDir()
{
	//PlayerDir를 받아와야하는데
	//아니면 Pointer로 받아와야겠다

	CurPointerDir();



	switch (PointerDir)
	{
	case EPointerDir::Up:
		Atk_Renderer->SetRotationDeg(FVector{ 0.0f, 0.0f, -90.0f });
		AtkDir = { 0,1,0,0 };
		break;
	case EPointerDir::UpRight:
		Atk_Renderer->SetRotationDeg(FVector{ 0.0f, 0.0f, -45.0f });
		AtkDir = { 1,1,0,0 };
		break;
	case EPointerDir::Right:
		Atk_Renderer->SetRotationDeg(FVector{ 0.0f, 0.0f, 0.0f });
		AtkDir = { 1,0,0,0 };
		break;
	case EPointerDir::DownRight:
		Atk_Renderer->SetRotationDeg(FVector{ 0.0f, 0.0f, 45.0f });
		AtkDir = { 1,-1,0,0 };
		break;
	case EPointerDir::Down:
		Atk_Renderer->SetRotationDeg(FVector{ 0.0f, 0.0f, 90.0f });
		AtkDir = { 0,-1,0,0 };
		break;
	case EPointerDir::DownLeft:
		Atk_Renderer->SetRotationDeg(FVector{ 0.0f, 0.0f, 135.0f });
		AtkDir = { -1,-1,0,0 };
		break;
	case EPointerDir::Left:
		Atk_Renderer->SetRotationDeg(FVector{ 0.0f, 0.0f, 180.0f });
		AtkDir = { -1,0,0,0 };
		break;
	case EPointerDir::UpLeft:
		Atk_Renderer->SetRotationDeg(FVector{ 0.0f, 0.0f, 215.0f });
		AtkDir = { -1,1,0,0 };
		break;
	default:
		break;
	}

	FVector AtkCurRot = Atk_Renderer->GetLocalRotation();
	AtkCurRot = AtkCurRot.Normalize3DReturn();

	int a = 0;

	//AtkDir = AtkDir.Normalize3DReturn();
	return AtkCurRot;
	//FVector Scale = GetActorScale3D();
	////SetActorScale3D(FVector{ -scale.X, scale.Y,scale.Z, 0.0f });
	//if (AHolo_Attack::PlayerDir == EPlayerDir::Right)
	//{
	//	//SetActirS
	//	SetActorRotation(FVector{ 0.0f, 0.0f, 0.0f });
	//	AtkDir = { 1,0,0,0 };
	//}

	//else if (AHolo_Attack::PlayerDir == EPlayerDir::Up)
	//{
	//	SetActorRotation(FVector{ 0.0f,0.0f,90.0f });
	//	AtkDir = { 0,1,0,0 };
	//}
	//else if (AHolo_Attack::PlayerDir == EPlayerDir::Down)
	//{
	//	SetActorRotation(FVector{ 0.0f,0.0f,270.0f });
	//	AtkDir = { 0,-1,0,0 };
	//}
	//else if (AHolo_Attack::PlayerDir == EPlayerDir::Left)
	//{
	//	SetActorScale3D(FVector{ -Scale.X, Scale.Y,Scale.Z, 0.0f });
	////	SetActorRotation(FVector{ 0.0f,0.0f,180.0f });
	//	AtkDir = { -1,0,0,0 };
	//}
	//else if (AHolo_Attack::PlayerDir == EPlayerDir::UpRight)
	//{
	//	SetActorRotation(FVector{ 0.0f,0.0f,45.0f });
	//	AtkDir = { 1,1,0,0 };
	//}
	//else if (AHolo_Attack::PlayerDir == EPlayerDir::UpLeft)
	//{
	//	SetActorRotation(FVector{ 0.0f,0.0f,135.0f });
	//	AtkDir = { -1,1,0,0 };
	//}
	//else if (AHolo_Attack::PlayerDir == EPlayerDir::DownRight)
	//{
	//	SetActorRotation(FVector{ 0.0f,0.0f,315.0f });
	//	AtkDir = { 1,-1,0,0 };
	//}
	//else if (AHolo_Attack::PlayerDir == EPlayerDir::DownLeft)
	//{
	//	SetActorRotation(FVector{ 0.0f,0.0f,225.0f });
	//	AtkDir = { -1,-1,0,0 };
	//}


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