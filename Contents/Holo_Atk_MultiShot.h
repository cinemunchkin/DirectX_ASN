#pragma once
#include "Holo_Weapon.h"

class AHolo_Atk_MultiShot : public AHolo_Weapon
{
public:
	// constrcuter destructer
	AHolo_Atk_MultiShot();
	~AHolo_Atk_MultiShot();

	// delete Function
	AHolo_Atk_MultiShot(const AHolo_Atk_MultiShot& _Other) = delete;
	AHolo_Atk_MultiShot(AHolo_Atk_MultiShot&& _Other) noexcept = delete;
	AHolo_Atk_MultiShot& operator=(const AHolo_Atk_MultiShot& _Other) = delete;
	AHolo_Atk_MultiShot& operator=(AHolo_Atk_MultiShot&& _Other) noexcept = delete;


	

protected:

private:

};

