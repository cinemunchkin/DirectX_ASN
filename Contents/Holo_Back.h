#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;
class AHolo_Back : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AHolo_Back();
	~AHolo_Back();

	// delete Function
	AHolo_Back(const AHolo_Back& _Other) = delete;
	AHolo_Back(AHolo_Back&& _Other) noexcept = delete;
	AHolo_Back& operator=(const AHolo_Back& _Other) = delete;
	AHolo_Back& operator=(AHolo_Back&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer;

	float4 Color;

private:
};

