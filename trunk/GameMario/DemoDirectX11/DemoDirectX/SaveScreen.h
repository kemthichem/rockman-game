#include "MarioGame.h"
#ifndef _SAVESCREEN_H
#define _SAVESCREEN_H
class CSaveScreen:public CMenuScreen
{
private:
	string name;
	LPD3DXFONT gFont;
	CButtonText* saveButton;
	CButtonText* cancelButton;
	void RenderTextAndSurface();
	void OnKeyDown(int keyCode);
public:
	void ButtonCLick();
	void SaveClick();
	void CancelClick();
	CSaveScreen(void);
	~CSaveScreen(void);
};
#endif // _SAVESCREEN_H

