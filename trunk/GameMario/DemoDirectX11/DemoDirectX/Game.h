
//#pragma once

#include "MarioGame.h"

#ifndef _GAME_H	
#define _GAME_H

//class CGame;

#define KEYBOARD_BUFFER_SIZE	1024

class CGame
{

private:

	HINSTANCE _hInstance;
	LPDIRECT3D9 _d3d;

	

	LPDIRECTINPUT8 _input;
	LPDIRECTINPUTDEVICE8  _keyboardDevice;
	char keys[256];
	DIDEVICEOBJECTDATA  _KeyEvents[KEYBOARD_BUFFER_SIZE];
	bool _InitWindow();
	bool _InitDirectX();
	bool _InitInput();
	bool _InitFont();
	void _ProcessKeyBoard();//

	////--------
	DWORD deltaTime;

protected:
	DWORD deltaTimePress;
	DWORD timePressStart;
	LPD3DXSPRITE _spriteHandler;
	LPDIRECT3DDEVICE9 _d3ddv;
	LPD3DXFONT g_Font;
	static LRESULT CALLBACK _WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void _Render();
	void _Process();
	void _Update();
	void Release();
	//-----------
	//--các hàm tương tác

	virtual void OnKeyUp(int keycode);
	virtual void OnKeyDown(int keycode);
	virtual void UpdateWorld(DWORD deltaTime);
	virtual void Render();
	virtual void RenderTextAndSurface();
	virtual void ProcessInput(DWORD deltaTime);
	virtual void InitGame();

public:
	HWND _hWnd;
	LPDIRECT3DSURFACE9 _backbuffer;
	CGame();
	CGame(HINSTANCE hInstance);
	void Init();
	int RunGame();
	bool IsKeyDown(int keycode);	
	~CGame(void);
	
};
#endif
