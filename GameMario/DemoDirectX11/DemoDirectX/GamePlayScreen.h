#include "MarioGame.h"
#ifndef _GAMEPLAYSCREEN_H
#define _GAMEPLAYSCREEN_H
#define WIDTHSCREEN 800
#define  HEIGHTSCREEN 600
#define  MAXSTATE 5
class CGamePlayScreen:public CGameScreen
{
private:
	float pauseAlpha;
	LPD3DXFONT gFont;
	LPD3DXSPRITE spriteHandle;
	void Update(DWORD deltaTime);
	void Render();
	void UpdateRectScreen();
	void RenderParameter();
	void RenderTextAndSurface();
	//-------
	void ResetScreen();
	//---
	bool transXLeft;
	DWORD timeStartStand;
	bool stand;
	CMapIO *mapIO;
	bool isStating;
	//------------
public:
	void Active();
	void Update(DWORD deltaTime, bool otherScreenHasFocus,bool coverByOtherScreen);
	void Draw(DWORD deltaTime);
	//---------
	void InKey(DWORD deltaTime);
	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);
	CGamePlayScreen(void);
	~CGamePlayScreen(void);
	//---------
// 	list<CStaticObject*> listObjectInScreen;
// 	list<CStaticObject*> listObjectUpdated;
// 	list<CStaticObject*> listAnimation;
// 	list<CStaticObject*> listObjects;
	RECT rectScreen;
	//CQuadTree *quadTree;
	CMario *mario;
};
#endif // _GAMEPLAYSCREEN_H

