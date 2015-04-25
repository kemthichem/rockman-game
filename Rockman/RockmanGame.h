#ifndef	_ROCKMANGAME_H
#define _ROCKMANGAME_H
//---
#include "utils.h"
#include "Game.h"
#include "Entity.h"
#include "Rockman.h"


class CRockmanGame : public CGame
{	
private:
	void Render();
	void UpdateWorld(float, CCamera*, CInput*);
	void ProcessInput(float deltaTime);
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

	list<CEntity*> listObject;
	~CRockmanGame(void);
};

#endif