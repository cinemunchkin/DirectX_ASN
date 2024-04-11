#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Camera.h>
#include "ContentsEnum.h"

//void Function(URenderer* Renderer)
//{
//	Renderer->ChangeAnimation("Idle");
//}

void APlayer::StateInit()
{
	// ������Ʈ �����
	State.CreateState("Die");
	State.CreateState("Idle");
	State.CreateState("Run");

	// �Լ��� �����ϰ�
	State.SetUpdateFunction("Idle", std::bind(&APlayer::Idle, this, std::placeholders::_1));

	// �Ｎ �Լ�
	// = [ ����ĸ�� Renderer]
	// {
	//    �Լ� ����
	// }

	// ����ĸó�� ����ȿ� =�� ����
	// ���� ���ÿ��� ��밡���� ���纻�� �����.
	// �޸𸮸� �Ҵ��ؼ� Renderer�� ���� �̸����� �����Ѵ�.

	USpriteRenderer* MyRender = Renderer;


	

	State.SetStartFunction("Idle", [=] // USpriteRenderer* MyRender = MyRender
		{
			// �޸𸮸� �Ҵ��ؼ� MyRender�� ���� �̸����� �����Ѵ�.
			// ���ο� �Լ���.
			// ������ �޶�����.
			// MyRender0->
			MyRender->ChangeAnimation("Ina_Idle");
		}
	);

	State.SetUpdateFunction("Run", std::bind(&APlayer::Run, this, std::placeholders::_1));
	State.SetStartFunction("Run", std::bind(&APlayer::RunStart, this));
	// ü����
	Renderer->SetAutoSize(1.8f, true);
	State.ChangeState("Idle");

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
}

void APlayer::PlayerDirCheck(float _Deltatime)
{
}



void APlayer::PlayerDir()
{

	/*
	��
	���� �÷��̾� ������ 
	*/

	if (true == GetActorScale3D().iX() < 0)
	{
		Renderer->SetDir(EEngineDir::Left);

	}
	else
	{
		Renderer->SetDir(EEngineDir::Right);

	}
	return;

}
void APlayer::Die(float _Update)
{

}

void APlayer::Idle(float _Update)
{
	if (true == IsPress('A') || true == IsPress('D') || true == IsPress('W') || true == IsPress('S'))
	{
		State.ChangeState("Run");
		return;
	}
	PlayerDir();
	
}

void APlayer::RunStart()
{
	Renderer->ChangeAnimation("Ina_Run");
}

void APlayer::Run(float _DeltaTime)
{

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	float Speed = 500.0f;

	if (true == IsAnykeyFree())
	{

		State.ChangeState("Idle");
	}

	

	if (true == IsPress('A'))
	{
		//SetActorScale3D(FVector(-64.0f, 64.0f, 100.0f));
		SetActorScale3D({ -GetActorScale3D().iX(), GetActorScale3D().iY() });
		AddActorLocation(FVector::Left * _DeltaTime * Speed);
		Camera->AddActorLocation(FVector::Left * _DeltaTime * Speed);
		
	}
	
	if (true == IsPress('D'))
	{
		SetActorScale3D({ GetActorScale3D().iX(), GetActorScale3D().iY() });
		AddActorLocation(FVector::Right * _DeltaTime * Speed);
		Camera->AddActorLocation(FVector::Right * _DeltaTime * Speed);
	}


	if (true == IsPress('W'))
	{
		AddActorLocation(FVector::Up * _DeltaTime * Speed);
		Camera->AddActorLocation(FVector::Up * _DeltaTime * Speed);
	}


	if (true == IsPress('S'))
	{
		AddActorLocation(FVector::Down * _DeltaTime * Speed);
		Camera->AddActorLocation(FVector::Down * _DeltaTime * Speed);
	}
	

	if (true == IsPress(VK_NUMPAD1))
	{
		// AddActorRotation(float4{0.0f, 0.0f, 1.0f} * 360.0f * _DeltaTime);
		// Color.X += _DeltaTime;
	}

	if (true == IsPress(VK_NUMPAD2))
	{
		Color.X -= _DeltaTime;
	}

	if (true == IsPress(VK_NUMPAD4))
	{
		Color.Y += _DeltaTime;
	}

	if (true == IsPress(VK_NUMPAD5))
	{
		Color.Y -= _DeltaTime;
	}

	if (true == IsPress(VK_NUMPAD7))
	{
		Color.Z += _DeltaTime;
	}

	if (true == IsPress(VK_NUMPAD8))
	{
		Color.Z -= _DeltaTime;
	}

	





}