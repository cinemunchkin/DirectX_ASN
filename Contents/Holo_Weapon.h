#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;
class AHolo_Weapon : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AHolo_Weapon();
	~AHolo_Weapon();

	// delete Function
	AHolo_Weapon(const AHolo_Weapon& _Other) = delete;
	AHolo_Weapon(AHolo_Weapon&& _Other) noexcept = delete;
	AHolo_Weapon& operator=(const AHolo_Weapon& _Other) = delete;
	AHolo_Weapon& operator=(AHolo_Weapon&& _Other) noexcept = delete;

protected:
	USpriteRenderer* Renderer;

private:

};

