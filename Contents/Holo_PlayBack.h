#pragma once
#include "Holo_Back.h"

class AHolo_PlayBack : public AHolo_Back
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AHolo_PlayBack();
	~AHolo_PlayBack();

	// delete Function
	AHolo_PlayBack(const AHolo_PlayBack& _Other) = delete;
	AHolo_PlayBack(AHolo_PlayBack&& _Other) noexcept = delete;
	AHolo_PlayBack& operator=(const AHolo_PlayBack& _Other) = delete;
	AHolo_PlayBack& operator=(AHolo_PlayBack&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

