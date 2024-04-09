#pragma once
#include <EngineCore/EngineCore.h>

// Ό³Έν :
class UCineCore : public UserCore
{
public:
	// constrcuter destructer
	UCineCore();
	~UCineCore();

	// delete Function
	UCineCore(const UCineCore& _Other) = delete;
	UCineCore(UCineCore&& _Other) noexcept = delete;
	UCineCore& operator=(const UCineCore& _Other) = delete;
	UCineCore& operator=(UCineCore&& _Other) noexcept = delete;

protected:
	void Initialize() override;

private:

};

