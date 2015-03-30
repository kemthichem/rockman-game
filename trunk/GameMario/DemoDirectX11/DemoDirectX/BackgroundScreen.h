#include "MarioGame.h"
#ifndef _BACKGROUNDSCREEN_H
#define _BACKGROUNDSCREEN_H
class CBackgroundScreen:public CGameScreen
{
	float x;
	LPDIRECT3DDEVICE9 d3ddv;
	LPD3DXSPRITE spriteHandle;
	LPDIRECT3DTEXTURE9 image;
public:
	CBackgroundScreen(void);
	CBackgroundScreen(int kind);
	~CBackgroundScreen(void);
	//----------------
	void Update(DWORD deltaTime,bool otherScreenHasFocus,bool coverByOtherScreen);
	void Draw(DWORD deltaTime);
	void Active(){};
	void OnKeyDown(int keyCode);
};

#endif // _BACKGROUNDSCREEN_H