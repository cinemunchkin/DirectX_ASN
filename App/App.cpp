#include "PreCompile.h"

#include <Contents/HoloCore.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UEngineCore::Start<UHoloCore>(hInstance);
}