#pragma once
#include "Holo_Back.h"

class AHolo_TitleBack : public AHolo_Back
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AHolo_TitleBack();
	~AHolo_TitleBack();

	// delete Function
	AHolo_TitleBack(const AHolo_TitleBack& _Other) = delete;
	AHolo_TitleBack(AHolo_TitleBack&& _Other) noexcept = delete;
	AHolo_TitleBack& operator=(const AHolo_TitleBack& _Other) = delete;
	AHolo_TitleBack& operator=(AHolo_TitleBack&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

