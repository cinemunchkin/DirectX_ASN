#include "PreCompile.h"
#include "TitleGameMode.h"
#include "TitleLogo.h"
#include "Holo_TitleBack.h"
#include <EngineCore/Camera.h>
//#include 

ATitleGameMode::ATitleGameMode()
{
	InputOn();
}

ATitleGameMode::~ATitleGameMode()
{
}

void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<ATitleLogo>("TitleLogo");
	GetWorld()->SpawnActor<AHolo_TitleBack>("TitleBackGround");

	Cursor = GetWorld()->SpawnActor<AHolo_Pointer>("Cursor");
	AHolo_Pointer::CursorPos = GEngine->EngineWindow.GetScreenMousePos();
	Cursor->SetActorLocation(FVector{ AHolo_Pointer::CursorPos.X - 1280.0f, AHolo_Pointer::CursorPos.Y - 360.0f });
}

void ATitleGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AHolo_Pointer::CursorPos = GEngine->EngineWindow.GetScreenMousePos();
	AHolo_Pointer::MousePointerOn = false;
	Cursor->SetActorLocation(FVector{ AHolo_Pointer::CursorPos.X - 640.0f, (AHolo_Pointer::CursorPos.Y - 360.0f) * -1.0f });

	if (true == IsAnykeyDown())
	{
		GEngine->ChangeLevel("PlayLevel");
	}
}

void ATitleGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void ATitleGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

}