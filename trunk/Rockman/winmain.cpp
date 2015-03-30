#include "RockmanGame.h"

CRockmanGame *rockmanGame;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	rockmanGame = new CRockmanGame(hInstance);
	rockmanGame->Init();
	rockmanGame->RunGame();
	return 0;
}