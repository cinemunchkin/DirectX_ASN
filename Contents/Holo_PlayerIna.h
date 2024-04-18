#pragma once
#include "Holo_Weapon.h"

class AHolo_PlayerIna : public AHolo_Weapon
{
public:
	// constrcuter destructer
	AHolo_PlayerIna();
	~AHolo_PlayerIna();

	// delete Function
	AHolo_PlayerIna(const AHolo_PlayerIna& _Other) = delete;
	AHolo_PlayerIna(AHolo_PlayerIna&& _Other) noexcept = delete;
	AHolo_PlayerIna& operator=(const AHolo_PlayerIna& _Other) = delete;
	AHolo_PlayerIna& operator=(AHolo_PlayerIna&& _Other) noexcept = delete;

protected:

private:

};

