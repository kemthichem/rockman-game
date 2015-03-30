#include "MarioGame.h"
#ifndef _BUTTON_H
#define _BUTTON_H
#define PI 3.14159265358979f
class CButtonGame
{
private:
	LPDIRECT3DTEXTURE9 image;
	char* stringContent;
	LPD3DXSPRITE spriteHandle;
	int width, height;
	void SetTransForm();
	void SetDeafaultTrans();
	float rotation;
public:
	RECT sRect;
	D3DXVECTOR3 pos;
	float alpha;
	bool selected;
	int Index;
	CButtonGame();
	CButtonGame(LPDIRECT3DTEXTURE9 image,RECT srect);
	~CButtonGame(void);
	virtual void Update(DWORD deltaTime);
	virtual void Draw(DWORD deltaTime);
	virtual void DrawText(){};
};
class CButtonText:public CButtonGame
{
public:
	CButtonText(string text);
	~CButtonText(void);
	///------
	void Draw(DWORD deltaTime);
	void DrawText();
	void Update(DWORD deltaTime);
	string filePathSave();
protected:
private:
	string buttonTitle;
	LPD3DXFONT gFont;
	LPDIRECT3DDEVICE9 d3ddv;
	RECT rect;
	
};
#endif // _BUTTON_H

