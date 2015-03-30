
#ifndef	_MARIOGAME_H
#define  _MARIOGAME_H
#include <d3d9.h>
#include<d3dx9.h>
#include <windows.h>
#include <dinput.h>
#include <stdlib.h> 
#include "list"
//--------------------
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
///--------------

const int MARIO = 0;
const int BLOCK = -2;
//#include "Brick.h"


class CMarioGame;

extern CMarioGame *marioGame; 

class CMarioGame : public CGame
{
private:

	bool isPause;
	//---
	bool transXLeft;
	DWORD timeStartStand;
	bool stand;
	//------------
	CMapIO *mapIO;
	//----------------

	//-------


	void Render();
	void UpdateWorld(DWORD deltaTime);
	void ProcessInput(DWORD deltaTime);
	void LoadResource();
	void OnKeyDown(int keyCode);
	void OnKeyUp(int keycode);
	void InitGame();
	void UpdateRectScreen();
public:
	CMario *mario;
	LPDIRECT3DSURFACE9 background;
	LPD3DXSPRITE GetSpriteHandle();
	LPDIRECT3DDEVICE9 GetDevice3d();
	CMarioGame(void);
	CMarioGame(HINSTANCE hInstance);
	~CMarioGame(void);
	list<CStaticObject*> listObjectInScreen;
	list<CStaticObject*> listObjectUpdated;
	list<CStaticObject*> listAnimation;
	list<CStaticObject*> listObjects;
	//---
	LPDIRECT3DTEXTURE9 spriteMarioSmall;
	LPDIRECT3DTEXTURE9 spriteMarioLarge;
	LPDIRECT3DTEXTURE9 spriteMarioGun;
	LPDIRECT3DTEXTURE9 spriteMarioConvert;
	//---
	LPDIRECT3DTEXTURE9 spriteBlocks;
	LPDIRECT3DTEXTURE9 spriteBullet;
	LPDIRECT3DTEXTURE9 spriteTurtle;
	LPDIRECT3DTEXTURE9 spriteItems;
	LPDIRECT3DTEXTURE9 spriteEato;
	LPDIRECT3DTEXTURE9 spriteEatoEx;
	LPDIRECT3DTEXTURE9 spriteEatoPipe;
	LPDIRECT3DTEXTURE9 spriteEnemy;
	LPDIRECT3DTEXTURE9 spritePipe;
	//---Scenery
	LPDIRECT3DTEXTURE9 spriteScenery;
	RECT rectScreen;
	CQuadTree *quadTree;
	
	
};
#endif
