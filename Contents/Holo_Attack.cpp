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

	CreateAttackAnimation("MultiShot");
	
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