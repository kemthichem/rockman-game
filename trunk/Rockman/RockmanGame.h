#ifndef	_ROCKMANGAME_H
#define _ROCKMANGAME_H
#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>
#include <dinput.h>
#include <stdlib.h> 
#include "list"
#include <vector>
#include <map>
#include <string>

//---
#include "utils.h"
#include "Game.h"
#include "ResourceManager.h"
#include "CusRect.h"
#include "StaticObject.h"
#include "Sprite.h"
#include "Rockman.h"
class CRockmanGame;

extern CRockmanGame *rockmanGame; 
class CRockmanGame : public CGame
{	
private:
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
	CRockmanGame(void);
	CRockmanGame(HINSTANCE hInstance);
	CRockman *rockman;
	~CRockmanGame(void);
};

#endif