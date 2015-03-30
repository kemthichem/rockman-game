#include "PauseScreen.h"


CPauseScreen::CPauseScreen(void)
{
	RECT r;
	r.top = 50;r.left = 0;
	r.bottom = 100;
	r.right = 151;
	resumeButton = new CButtonGame(CRescource::GetInstance()->GetSprite(IMAGE_BUTTON),r);
	AddButton(resumeButton);
	r.left = 300;
	r.right = 450;
	saveButton = new CButtonGame(CRescource::GetInstance()->GetSprite(IMAGE_BUTTON),r);	
	r.left = 450;
	r.right = 600;
	mainMenuButton = new CButtonGame(CRescource::GetInstance()->GetSprite(IMAGE_BUTTON), r);
	AddButton(mainMenuButton);
	AddButton(saveButton);
	//---------
	menuTitle = "Pause Menu";
}


CPauseScreen::~CPauseScreen(void)
{
	delete resumeButton;
	delete mainMenuButton;
	delete saveButton;
}

void CPauseScreen::ButtonCLick()
{
	if(resumeButton->selected) ResumeButtonClick();
	else if(mainMenuButton->selected) MainMenuButtonClick();
	else if(saveButton->selected) SaveButtonClick();
}

void CPauseScreen::ResumeButtonClick()
{
	ExitScreen();
}

void CPauseScreen::SaveButtonClick()
{
	ExitScreen();
	screenManager->AddScreen(new CSaveScreen());
}

void CPauseScreen::MainMenuButtonClick()
{
	list<CGameScreen*> listToLoad;
	listToLoad.push_back(new CBackgroundScreen());
	listToLoad.push_back(new CMainMenuScreen());
	CLoadingScreen::Load(screenManager, false, listToLoad);
}
