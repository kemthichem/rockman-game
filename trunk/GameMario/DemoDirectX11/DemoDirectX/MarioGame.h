
#ifndef	_MARIOGAME_H
#define  _MARIOGAME_H
#include <d3d9.h>
#include<d3dx9.h>
#include <windows.h>
#include <dinput.h>
#include <stdlib.h> 
#include "list"
#include <vector>
#include <map>
#include <string>
#include "dirent.h"

//--------------------
#include "SoundManager.h"
#include "Rescource.h"
//----------
#include "CusRect.h"
#include "utils.h"
#include "Game.h"
#include "StaticObject.h"
#include "Sprite.h"
#include "QuadTreeNode.h"
#include "QuadTree.h"
#include "Mario.h"
#include "Brick.h"
#include "Block.h"
#include "Flag.h"
#include "House.h"
#include "Turtle.h"
#include "Enemy.h"
#include "Eato.h"
#include "MushLife.h"
#include "MushRoom.h"
#include "Star.h"
#include "Coin.h"
#include "Coin1.h"
#include "FragBrick.h"
#include "Bullet.h"
#include "Land.h"
#include "PipeVer.h"
#include "PipeHor.h"
#include "Pipe1.h"
#include "Scenery.h"
#include "MapIO.h"
#include "Score.h"
#include "ScoreEff.h"
///--------------
//---------------Game screens
#include "GameScreen.h"
#include"ScreenManager.h"
#include "BackgroundScreen.h"
#include "ButtonGame.h"
#include "MenuScreen.h"
#include "MainMenuScreen.h"
#include "PauseScreen.h"
#include "LoadingScreen.h"
#include "GamePlayScreen.h"
#include "SaveScreen.h"
#include "StateScreen.h"
#include "LoadScreen.h"
//#include "Screen.h"
//-----

const int MARIO = 0;
const int BLOCK = -2;
//#include "Brick.h"


class CMarioGame;

extern CMarioGame *marioGame; 
using namespace std;
class CMarioGame : public CGame
{
private:

	bool isPause;
	//---
	bool transXLeft;
	DWORD timeStartStand;
	bool stand;
	//------------
	
	//----------------
	CScreenManager *screenManager;
	//-------

	void Render();
	void UpdateWorld(DWORD deltaTime);
	void ProcessInput(DWORD deltaTime);
	void RenderTextAndSurface();
	void OnKeyDown(int keyCode);
	void OnKeyUp(int keycode);
	void InitGame();
	void UpdateRectScreen();
public:
	LPD3DXSPRITE GetSpriteHandle();
	LPDIRECT3DDEVICE9 GetDevice3d();
	LPD3DXFONT GetLPFont();
	CMarioGame(void);
	CMarioGame(HINSTANCE hInstance);
	~CMarioGame(void);
	//------------------
	list<CStaticObject*> listObjectInScreen;
	list<CStaticObject*> listObjectUpdated;
	list<CStaticObject*> listAnimation;
	list<CStaticObject*> listObjects;
	RECT rectScreen;
	CQuadTree *quadTree;
	CScore * score;
	CMario *mario;
	//--------------
	
	
};
#endif
