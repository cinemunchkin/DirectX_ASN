#pragma once
#include <EngineCore/EngineCore.h>

// Ό³Έν :
class UHoloCore : public UserCore
{
public:
	// constrcuter destructer
	UHoloCore();
	~UHoloCore();

	// delete Function
	UHoloCore(const UHoloCore& _Other) = delete;
	UHoloCore(UHoloCore&& _Other) noexcept = delete;
	UHoloCore& operator=(const UHoloCore& _Other) = delete;
	UHoloCore& operator=(UHoloCore&& _Other) noexcept = delete;

protected:
	void Initialize() override;

private:

};

