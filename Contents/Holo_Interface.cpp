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
		UImage* Image = CreateWidget<UImage>(GetWorld(), "Ina_Interface");
		Image->SetupAttachment(this);
		Image->SetSprite("Ina_Interface.png");
		Image->SetAutoSize(0.5f, true);
		Image->SetPosition({ -590, 310 });
		Image->SetScale({43*1.9f, 38*1.9f});

	}


	//{
	//	UImage* Image = CreateWidget<UImage>(GetWorld(), "Holo_HpBar");
	//	Image->SetupAttachment(this);
	//	Image->SetSprite("Holo_HpBar.png");
	//	Image->SetAutoSize(0.5f, true);
	//	Image->SetPosition({ -400, 300 });

	//}


	{
		UTextWidget* Image = CreateWidget<UTextWidget>(GetWorld(), "TestText");
		Image->SetupAttachment(this);
		Image->SetFont("Galmuri9");
		Image->SetScale(20.0f);
		Image->SetColor(Color8Bit::Black);
		Image->SetPosition({ -400, 297 });
		Image->SetText("홀로큐어 얍!");

	}


	{
		UTextWidget* Image = CreateWidget<UTextWidget>(GetWorld(), "TestText");
		Image->SetupAttachment(this);
		Image->SetFont("Galmuri9");
		Image->SetScale(20.0f);
		Image->SetColor(Color8Bit::White);
		Image->SetPosition({ -400, 300 });
		Image->SetText("홀로큐어 얍!");

	}

	AddToViewPort(1);


}