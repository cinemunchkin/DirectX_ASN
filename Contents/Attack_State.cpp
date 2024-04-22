#include "PreCompile.h"
#include "Holo_Attack.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Camera.h>
#include "Holo_Pointer.h"

void AHolo_Attack::AtkStateInit()
{

	AtkState.CreateState("MultiShot");
	AtkState.CreateState("RangedShot");

	AtkState.SetUpdateFunction("MultiShot");

	AtkState.SetUpdateFunction("MultiShot", std::bind(&AHolo_Attack::MultiShotInit, this, std::placeholders::_1));




	USpriteRenderer* MyAtkRender = Atk_Renderer;

	AtkState.SetStartFunction("MultiShot", [=]
		{
			MyAtkRender->ChangeAnimation(Name + "_MultiShot");
		}
	);

	AtkState.SetUpdateFunction("RangedShot", std::bind(&AHolo_Attack::RangedShotInit, this, std::placeholders::_1));

	AtkState.SetStartFunction("RangedShot", std::bind(&AHolo_Attack::RangedShotStart, this));
	
	//AtkState.ChangeState("MultiShot");


}


void AHolo_Attack::MultiShotInit(float _DeltaTime)
{

	if (true == IsPress(VK_NUMPAD0))
	{
		AtkState.ChangeState("MultiShot");
		return;
	}

}


void AHolo_Attack::RangedShotInit(float _DeltaTime)
{

}


void AHolo_Attack::RangedShotStart()
{
	Atk_Renderer->ChangeAnimation(Name + "_RangedShot");

}