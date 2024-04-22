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

//	CreateAttackAnimation("MultiShot");

	Atk_Renderer->CreateAnimation("FX_Atk_Ina", "FX_Atk_Ina", 0.1, true,0,5);
	Atk_Renderer->ChangeAnimation("FX_Atk_Ina");
	Atk_Renderer->SetAutoSize(3.0f, true);
	Atk_Renderer->SetOrder(ERenderOrder::Attack);

	AtkStateInit();

	SetActorLocation(GetActorLocation());


}

void AHolo_Attack::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	//AtkState.Update(_DeltaTime);
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
����

actor ???
spawn pointer <- xxx

�ϴ� ��������
������ �ؾ��᤿��

this�� �ڱ��ڽ��̶�� ���ε�
�̰� null�̸�
�� �ڱ��ڽ��� ���ٴ¼Ҹ���
�ȸ������
�ȸ���� ã����
���������ݶ�

������ �Ҳ���
������ actor?
�ݸ������� �Ҳ��ƴ�?

����Ű�� ������

player�� ������ ����
�� ������ �ݸ����� �������� ������ �־����



*/