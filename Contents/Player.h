#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>
#include <EngineBase/EngineSerializer.h>
#include "Holo_ContentsEnum.h"
#include "Holo_Attack.h"



class USpriteRenderer;
class APlayer : public AActor
{
	GENERATED_BODY(AActor)

public:

	static float4 PlayerPos;

	// constrcuter destructer
	APlayer();
	~APlayer();

	// delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

	UStateManager State;

	void SetName(std::string _Name)
	{
		Name = _Name;
	}

	EPlayerDir GetPlayerDir()
	{
		return PlayerDir;
	}

	float GetAngle()
	{
		return Angle;
	}

	FVector GetPlayerCurPos();

	void PlayerSprite(std::string_view _Name, UINT _Index)
	{

	std::shared_ptr<UEngineSprite> Sprite = UEngineSprite::FindRes(_Name);

	if (nullptr == Sprite)
	{
		MsgBoxAssert("존재하지 않는 스프라이트를 세팅해주려고 했습니다.");
		return;
	}

	FVector SpriteInfo = Sprite->GetSpriteInfo(0).CuttingSize;

	}

	void PlayerStrobe(float _DeltaTime);



	//FVector GetPlayerPos()
	//{
	//	return PlayerPos;
	//}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer;
	UCollision* Collision;

	USpriteRenderer* PointerDir;
	std::shared_ptr<UCamera> Camera;
	std::shared_ptr<AHolo_Attack> Attack;

	
	float AttackTime = 0;

	float4 Color;
	float Angle;

	std::string Name = "Ina";
	EPlayerDir PlayerDir = EPlayerDir::Right;
	int Hp = 100;
	float Atk = 1;
	float Speed = 200.0f;
	float LineSpeed = Speed * 0.75f;


	void CreatePlayerAnimation(std::string _Name);

	void CheckMouseAimMode();
	void ChangeMoveAimAtkDir();
	void ChangeMouseAimAtkDir();



	//Attack
	void PlayerAttackSpawn(float _Deltatime);


	//State
	void StateInit();

	void Die(float _DeltaTime);

	void Idle(float _DeltaTime);

	void RunStart();
	void Run(float _DeltaTime);

	void KeyMove(float _DeltaTime, float4 _Dir, float _Speed);
	void KeyLineMove(float _DeltaTime, float4 _Dir1, float4 _Dir2);


	//msg
	void DebugMsgFunction(float _DeltaTime);
};