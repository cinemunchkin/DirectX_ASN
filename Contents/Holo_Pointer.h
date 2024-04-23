#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

class USpriteRenderer;
class AHolo_Pointer : public AActor
{
	GENERATED_BODY(AActor)
public:
	static float4 CursorPos;
	static bool MousePointerOn;

	// constrcuter destructer
	AHolo_Pointer();
	~AHolo_Pointer();

	// delete Function
	AHolo_Pointer(const AHolo_Pointer& _Other) = delete;
	AHolo_Pointer(AHolo_Pointer&& _Other) noexcept = delete;
	AHolo_Pointer& operator=(const AHolo_Pointer& _Other) = delete;
	AHolo_Pointer& operator=(AHolo_Pointer&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Pointer_Renderer;

	void CursorOff();
	void ChangeAimMode();
	void CheckAimMode();

private:
};

