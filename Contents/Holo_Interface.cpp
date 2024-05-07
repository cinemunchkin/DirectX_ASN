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

	Interface_Char();

	AddToViewPort(1);
	
}

void AHolo_Interface::Tick(float _DeltaTime)
{
	TimeFlow(_DeltaTime);

}


void  AHolo_Interface::Interface_Char()
{
		
	{// 인터페이스 상단바
		UImage* Image = CreateWidget<UImage>(GetWorld(), "Interface_Bar");
		Image->SetupAttachment(this);
		Image->SetSprite("Interface_Bar.png");
		Image->SetAutoSize(2.1f, true);
		Image->SetPosition({ 0, 340 });
		//Image->SetMulColor(FVector{255,255,255,100});
		Image->SetPlusColor(FVector(0,0,0,0));
	}


	{// HP 글씨
		UImage* Image = CreateWidget<UImage>(GetWorld(), "HP_Bar_Char");
		Image->SetupAttachment(this);
		Image->SetSprite("HP_Bar_Char.png");
		Image->SetAutoSize(2.0f, true);
		Image->SetPosition({ -531, 338 });

	}


	{// 캐릭터 프사
		UImage* Image = CreateWidget<UImage>(GetWorld(), "Ina_Interface");
		Image->SetupAttachment(this);
		Image->SetSprite("Ina_Interface.png");
		Image->SetAutoSize(1.9f, true);
		Image->SetPosition({ -590, 310 });
		//Image->SetScale({ 43 * 1.9f, 38 * 1.9f });

	}

	{// 텍스트 테스트 갈무리체 음영
		UTextWidget* Image = CreateWidget<UTextWidget>(GetWorld(), "TestText");
		Image->SetupAttachment(this);
		Image->SetFont("Galmuri9");
		Image->SetScale(20.0f);
		Image->SetColor(Color8Bit::Black);
		Image->SetPosition({ -480, 297 });
		Image->SetText("홀로큐어 얍!");

	}

	{// 텍스트 테스트 갈무리체 
		UTextWidget* Image = CreateWidget<UTextWidget>(GetWorld(), "TestText");
		Image->SetupAttachment(this);
		Image->SetFont("Galmuri9");
		Image->SetScale(20.0f);
		Image->SetColor(Color8Bit::White);
		Image->SetPosition({ -480, 300 });
		Image->SetText("홀로큐어 얍!");

	}

	{ //HP 체력치 숫자 음영
		UTextWidget* Image = CreateWidget<UTextWidget>(GetWorld(), "TestText");
		Image->SetupAttachment(this);
		Image->SetScale(17.0f);
		Image->SetColor(Color8Bit::Black);
		Image->SetPosition({ -400, 335 });
		Image->SetFont("Galmuri7");
		Image->SetText("75/75");

	}

	{ //HP 체력치 숫자
		UTextWidget* Image = CreateWidget<UTextWidget>(GetWorld(), "TestText");
		Image->SetupAttachment(this);
		Image->SetScale(17.0f);
		Image->SetColor(Color8Bit::White);
		Image->SetPosition({ -400, 338 });
		Image->SetFont("Galmuri7");
		Image->SetText("75/75");

	}

}

void  AHolo_Interface::TimeFlow(float _DeltaTime)
{

	for (int i = 0; i < 1000000; i++)
	{
		

		{ //HP 체력치 숫자
			UTextWidget* Image = CreateWidget<UTextWidget>(GetWorld(), "TestText");
			Image->SetupAttachment(this);
			Image->SetScale(17.0f);
			Image->SetColor(Color8Bit::White);
			Image->SetPosition({ -400, 338 });
			Image->SetFont("Galmuri7");
			Image->SetText("AAA");

		}

	}
}
