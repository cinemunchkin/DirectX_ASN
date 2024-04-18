#pragma once

#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>
#include "Holo_ContentsEnum.h"


#include "Holo_Atk_MultiShot.h"
#include "Holo_Atk_Ranged.h"



class USpriteRenderer;
class AHolo_Attack : public AActor
{

	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AHolo_Attack();
	~AHolo_Attack();

	// delete Function
	AHolo_Attack(const AHolo_Attack& _Other) = delete;
	AHolo_Attack(AHolo_Attack&& _Other) noexcept = delete;
	AHolo_Attack& operator=(const AHolo_Attack& _Other) = delete;
	AHolo_Attack& operator=(AHolo_Attack&& _Other) noexcept = delete;




	//���� ����
	void SpawnAttack(float _DeltaTime);
	void CreateAttackAnimation(std::string _Name);


	void CreateMultiShot(float _DeltaTime);
	void CreateRangedShot(float _DeltaTime);



	std::shared_ptr<AHolo_Atk_MultiShot> MultiShot;
	std::shared_ptr<AHolo_Atk_Ranged> RangedShot;

protected:

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;



private:

	USpriteRenderer* Atk_Renderer;
	std::shared_ptr<UCamera> Camera;
};