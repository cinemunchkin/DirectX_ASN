#pragma once
#include <EngineCore/EngineCore.h>

class UHolo_Core : public UserCore
{
public:
	// constrcuter destructer
	UHolo_Core();
	~UHolo_Core();

	// delete Function
	UHolo_Core(const UHolo_Core& _Other) = delete;
	UHolo_Core(UHolo_Core&& _Other) noexcept = delete;
	UHolo_Core& operator=(const UHolo_Core& _Other) = delete;
	UHolo_Core& operator=(UHolo_Core&& _Other) noexcept = delete;

protected:
	void Initialize() override;

private:

};

