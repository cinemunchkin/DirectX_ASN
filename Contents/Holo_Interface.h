#pragma once
#include <EngineCore/Widget.h>

class AHolo_Interface : public UWidget
{
public:
	// constrcuter destructer
	AHolo_Interface();
	~AHolo_Interface();

	// delete Function
	AHolo_Interface(const AHolo_Interface& _Other) = delete;
	AHolo_Interface(AHolo_Interface&& _Other) noexcept = delete;
	AHolo_Interface& operator=(const AHolo_Interface& _Other) = delete;
	AHolo_Interface& operator=(AHolo_Interface&& _Other) noexcept = delete;

protected:

	void BeginPlay();


private:

};