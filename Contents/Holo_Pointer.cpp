#include "PreCompile.h"
#include "Holo_Pointer.h"

float4 AHolo_Pointer::CursorPos = FVector::Zero;
bool AHolo_Pointer::MousePointerOn = false;

AHolo_Pointer::AHolo_Pointer()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Pointer_Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");

	SetRoot(Root);
	Pointer_Renderer->SetupAttachment(Root);
	InputOn();
}

AHolo_Pointer::~AHolo_Pointer()
{
}

void AHolo_Pointer::BeginPlay()
{
	Super::BeginPlay();

	CursorOff();
	Pointer_Renderer->SetSprite("spr_GameCursor_0.png");
	Pointer_Renderer->SetAutoSize(1.0f, true);
	Pointer_Renderer->SetOrder(ERenderOrder::Pointer);

	CursorPos = GEngine->EngineWindow.GetScreenMousePos();
}

void AHolo_Pointer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	ChangeAimMode();
	CheckAimMode();
}

void AHolo_Pointer::CursorOff()
{
	ShowCursor(FALSE);
}

void AHolo_Pointer::ChangeAimMode()
{
	if (true == IsDown(VK_LBUTTON))
	{
		if (true != MousePointerOn)
		{
			MousePointerOn = true;
		}
		else
		{
			MousePointerOn = false;
		}
	}
}

void AHolo_Pointer::CheckAimMode()
{
	if (true != MousePointerOn)
	{
		CursorOff();
		Pointer_Renderer->SetSprite("spr_GameCursor_0.png");
		Pointer_Renderer->SetPivot(EPivot::LEFTTOP);
	}
	else
	{
		CursorOff();
		Pointer_Renderer->SetSprite("spr_GameCursor1_0.png");
		Pointer_Renderer->SetPivot(EPivot::MAX);
	}
}