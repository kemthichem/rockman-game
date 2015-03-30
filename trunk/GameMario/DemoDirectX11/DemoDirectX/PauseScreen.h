#include "MarioGame.h"
#ifndef _PAUSESCREEN_H
#define _PAUSESCREEN_H
class CPauseScreen:public CMenuScreen
{
private:
	CButtonGame* resumeButton;
	CButtonGame* saveButton;
	CButtonGame* mainMenuButton;
	//---------------
	void ButtonCLick();
	void ResumeButtonClick();
	void SaveButtonClick();
	void MainMenuButtonClick();
public:
	CPauseScreen(void);
	~CPauseScreen(void);
};
#endif // _PAUSESCREEN_H

