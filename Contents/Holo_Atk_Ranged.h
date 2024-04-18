#pragma once
#include "Holo_Weapon.h"

class AHolo_Atk_Ranged : public AHolo_Weapon
{
public:
	// constrcuter destructer
	AHolo_Atk_Ranged();
	~AHolo_Atk_Ranged();

	// delete Function
	AHolo_Atk_Ranged(const AHolo_Atk_Ranged& _Other) = delete;
	AHolo_Atk_Ranged(AHolo_Atk_Ranged&& _Other) noexcept = delete;
	AHolo_Atk_Ranged& operator=(const AHolo_Atk_Ranged& _Other) = delete;
	AHolo_Atk_Ranged& operator=(AHolo_Atk_Ranged&& _Other) noexcept = delete;

protected:

private:

};

