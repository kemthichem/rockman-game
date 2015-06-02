#include "RockmanGame.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CRockmanGame rockmanGame(hInstance);
	rockmanGame.InitGame();
	rockmanGame.RunGame();
	return 0;
}