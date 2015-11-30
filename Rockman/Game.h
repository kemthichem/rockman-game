#ifndef _GAME_H	
#define _GAME_H

#include <d3d9.h>
#include <d3dx9.h>
#include "Windows.h"
#include "Input.h"
#include "Time.h"
#include "GameStateManager.h"

class CGame
{
private:
	HINSTANCE _hInstance;
	LPDIRECT3D9 _d3d;
	bool _InitWindow();
	bool _InitDirectX();
	bool _InitInput();
	bool _InitFont();

	////--------
	DWORD m_deltaTime;
	void Render();
	void Release();
protected:
	CInput *m_input;
	CTimer *m_time;
	CGameStateManager *m_StateManager;

	LPD3DXSPRITE m_SpriteHandler;
	LPDIRECT3DDEVICE9 _d3ddv;
	LPD3DXFONT m_GraphicText;
	static LRESULT CALLBACK _WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	virtual void UpdateWorld();
	virtual void RenderWorld();
	virtual void RenderTextAndSurface();
	
public:
	HWND m_hWnd;
	LPDIRECT3DSURFACE9 _backbuffer;
	CGame();
	CGame(HINSTANCE hInstance);
	int RunGame();
	virtual void InitGame();
	~CGame(void);
};
#endif
