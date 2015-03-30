
//#pragma once

#include "MarioGame.h"

#ifndef _GAME_H	
#define _GAME_H
#define WIDTHSCREEN 800
#define  HEIGHT 600
//class CGame;

#define KEYBOARD_BUFFER_SIZE	1024

class CGame
{

private:
	HWND _hWnd;
	HINSTANCE _hInstance;
	LPDIRECT3D9 _d3d;

	LPDIRECT3DSURFACE9 _backbuffer;

	LPDIRECTINPUT8 _input;
	LPDIRECTINPUTDEVICE8  _keyboardDevice;
	char keys[256];
	DIDEVICEOBJECTDATA  _KeyEvents[KEYBOARD_BUFFER_SIZE];

	bool _InitWindow();
	bool _InitDirectX();
	bool _InitInput();

	
	void _ProcessKeyBoard();//

	////--------
	DWORD deltaTime;

protected:
	DWORD deltaTimePress;
	DWORD timePressStart;
	LPD3DXSPRITE _spriteHandler;
	LPDIRECT3DDEVICE9 _d3ddv;
	bool IsKeyDown(int keycode);	
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
	virtual void LoadResource();
	virtual void ProcessInput(DWORD deltaTime);
	virtual void InitGame();

public:
	CGame();
	CGame(HINSTANCE hInstance);
	void Init();
	int RunGame();
	~CGame(void);
	
};
#endif
