#include "MarioGame.h"
#ifndef _STATESCREEN_H
#define _STATESCREEN_H
class CStateScreen:public CGameScreen
{
private:
	DWORD timeStartScreen;
	int level;
	int life;
	LPD3DXFONT gFont;
	LPD3DXSPRITE spriteHandle;
	void Draw(DWORD deltaTime);
	void Active();
	void Update(DWORD deltaTime, bool otherScreenHasFocus,bool coverByOtherScreen);
	void RenderTextAndSurface();
public:
	CStateScreen(void);
	~CStateScreen(void);
};
#endif // _STATESCREEN_H

