#include "RockmanGame.h"
#include "PlayingGameState.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//CRockmanGame rockmanGame(hInstance);
	//rockmanGame.InitGame();
	//rockmanGame.RunGame();
	CPLayingGameState playingGameState;
	playingGameState.Init();

	return 0;
}