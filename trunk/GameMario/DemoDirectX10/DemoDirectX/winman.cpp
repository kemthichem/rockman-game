
#include "MarioGame.h"

CMarioGame *marioGame;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	marioGame = new CMarioGame(hInstance);
	marioGame->Init();
	marioGame->RunGame();
	return 0;
}