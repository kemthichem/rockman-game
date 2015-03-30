
#include "MarioGame.h"
#ifndef _SCREENMANAGER_H
#define _SCREENMANAGER_H
class CScreenManager
{
private:
	LPD3DXSPRITE spriteHandle;
	LPDIRECT3DDEVICE9 d3ddv;
public:
	CScreenManager(void);
	~CScreenManager(void);

	//--
	list<CGameScreen*> screens;
	list<CGameScreen*> tempScreens;
	//--
	void Update(DWORD deltaTime);
	void Draw(DWORD deltaTime);
	void Render();
	void FadeBackBufferToBlack(float alpha);
	void AddScreen(CGameScreen* gameScreen);
	void RemoveScreen(CGameScreen* gameScreen);
	list<CGameScreen*> GetScreens();
	//----------------
	void InKey(DWORD deltaTime);
	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);


};

#endif // SCREENMANAGER
