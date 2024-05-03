#include "PreCompile.h"
#include "Holo_Interface.h"

#include <EngineCore/TextWidget.h>
#include <EngineCore/Image.h>

AHolo_Interface::AHolo_Interface()
{
}

AHolo_Interface::~AHolo_Interface()
{
}

void AHolo_Interface::BeginPlay()
{//인터페이스를 관리하는 개념의 클래스


	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "Holo_HpBar");
		Image->SetupAttachment(this);
		Image->SetSprite("Holo_HpBar.png");
		Image->SetAutoSize(0.5f, true);
		Image->SetPosition({ -400, 300 });

	}

	{
		UTextWidget* Image = CreateWidget<UTextWidget>(GetWorld(), "TestText");
		Image->SetupAttachment(this);
		Image->SetFont("궁서");
		Image->SetScale(10.0f);
		Image->SetColor(Color8Bit::Black);
		Image->SetPosition({ 400, 300 });
		Image->SetText("TestText");

	}

	AddToViewPort(1);


}