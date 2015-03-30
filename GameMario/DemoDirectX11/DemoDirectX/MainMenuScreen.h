#include "MarioGame.h"
#ifndef _MainMenu_H
#define _MainMenu_H
class CMainMenuScreen: public CMenuScreen
{
private:
	CButtonGame* playButton;
	CButtonGame* helpButton;
	CButtonGame* loadButton;
	CButtonGame* exitButton;
	//---------------
	void ButtonCLick();
	void PlayButtonClick();
	void HelpButtonClick();
	void LoadButtonClick();
	void ExitButtonClick();
public:
	CMainMenuScreen(void);
	~CMainMenuScreen(void);
	
};
#endif // _MainMenu_H

