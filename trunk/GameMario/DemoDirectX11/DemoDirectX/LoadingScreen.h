#include "MarioGame.h"
#ifndef _LOADSCREEN_H
#define _LOADSCREEN_H
class CLoadingScreen:public CGameScreen
{
private:

	LPD3DXSPRITE spriteHandle;
	LPDIRECT3DDEVICE9 d3ddv;
	//-----------
	LPDIRECT3DTEXTURE9 bg;
	LPDIRECT3DSURFACE9 fr;
	bool loadingIsSlow;
	bool otherScreenToLow;
	bool otherScreensAreGone;
	list<CGameScreen*> screensToLoad;
	void SetTransforms(float rotate);
public:
	static void Load(CScreenManager* screenManager,bool loadIsLow, list<CGameScreen*> screensToLoad);
	CLoadingScreen(CScreenManager* screenManager,bool loadIsLow, list<CGameScreen*> screensToLoad );
	CLoadingScreen(void);
	~CLoadingScreen(void);
	//------------
	void Update(DWORD deltaTime, bool otherScreenHasFocus,bool coverByOtherScreen);
	void Draw(DWORD deltaTime);
	void Active(){};
};
#endif // _LOADSCREEN_H

