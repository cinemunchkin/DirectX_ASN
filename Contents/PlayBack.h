#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class USpriteRenderer;
class APlayBack : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	APlayBack();
	~APlayBack();

	// delete Function
	APlayBack(const APlayBack& _Other) = delete;
	APlayBack(APlayBack&& _Other) noexcept = delete;
	APlayBack& operator=(const APlayBack& _Other) = delete;
	APlayBack& operator=(APlayBack&& _Other) noexcept = delete;
	int index;

	USpriteRenderer* Renderer;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

	float4 Color;
};

