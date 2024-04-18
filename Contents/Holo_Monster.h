#pragma once
#include <EngineCore/Actor.h>
#include "Holo_ContentsEnum.h"

class USpriteRenderer;
class AHolo_Monster : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AHolo_Monster();
	~AHolo_Monster();

	// delete Function
	AHolo_Monster(const AHolo_Monster& _Other) = delete;
	AHolo_Monster(AHolo_Monster&& _Other) noexcept = delete;
	AHolo_Monster& operator=(const AHolo_Monster& _Other) = delete;
	AHolo_Monster& operator=(AHolo_Monster&& _Other) noexcept = delete;

	void SetName(std::string _Name)
	{
		Name = _Name;
	}

	USpriteRenderer* GetRenderer()
	{
		return Renderer;
	}

	void SetMonsterStatus(float _Hp, float _Atk, float _Speed, float _Exp, EMonsterMoveType _MoveType);

	FVector CreateGroupToPlayerDir();

	void SetToPlayerDir(FVector _ToPlayerDir)
	{
		ToPlayerDir = _ToPlayerDir;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer;
	UCollision* Collision;

	FVector PlayerLocation;
	FVector Dir = FVector::Zero;
	FVector ToPlayerDir;

	std::string Name = "Shrimp";
	float Hp = 8.0f;
	float Atk = 2.0f;
	float Speed = 0.35f;
	float CalSpeed = 300.0f * Speed;
	float Exp = 6.0f;

	EMonsterMoveType MoveType = EMonsterMoveType::Follow;

	void CreateHolo_MonsterAnimation(std::string _Name);

	void Move(float _DeltaTime, EMonsterMoveType _MoveType);
	void CheckPosComparePlayer();
};

