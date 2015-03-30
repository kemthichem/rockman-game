#include "MarioGame.h"
#ifndef _MENUSCREEN_H
#define  _MENUSCREEN_H
class CMenuScreen:public CGameScreen
{
private:
	
	
	//---
	int countButton;
	int indexSelected;
	void NextIndex(bool increas);
	
protected:
	char* menuTitle;
	list<CButtonGame*> listButton;
	void AddButton(CButtonGame* b);
	virtual void ButtonCLick()=0;
public:
	CMenuScreen(void);
	~CMenuScreen(void);
	void Update(DWORD deltaTime, bool otherScreenHasFocus,bool coverByOtherScreen);
	void Draw(DWORD deltaTime);
	void Active();
	virtual void RenderTextAndSurface();
	//----------
	void InKey(DWORD deltaTime);
	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode){};
	
};
#endif // _MENUSCREEN_H

