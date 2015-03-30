#include "MainMenuScreen.h"


CMainMenuScreen::CMainMenuScreen(void)
{
	RECT r;
	r.top = r.left = 0;
	r.bottom = 50;
	r.right = 151;
	playButton = new CButtonGame(CRescource::GetInstance()->GetSprite(IMAGE_BUTTON),r);
	AddButton(playButton);
	r.left = 150;
	r.right = 300;
	loadButton = new CButtonGame(CRescource::GetInstance()->GetSprite(IMAGE_BUTTON), r);
	AddButton(loadButton);
	
	r.left = 300;
	r.right = 450;
	helpButton = new CButtonGame(CRescource::GetInstance()->GetSprite(IMAGE_BUTTON),r);
	AddButton(helpButton);
	r.left = 450;
	r.right = 600;
	exitButton = new CButtonGame(CRescource::GetInstance()->GetSprite(IMAGE_BUTTON), r);
	AddButton(exitButton);
	//---------
	menuTitle = "Main Menu";
	//---
	SoundManager::GetInst()->PlayBgSound(SOUND_B_MENU,true);
	
}


CMainMenuScreen::~CMainMenuScreen(void)
{
	delete playButton;
	delete loadButton;
	delete helpButton;
	delete exitButton;
}

void CMainMenuScreen::PlayButtonClick()
{
	CRescource::mapFilePath = "Map/map1.txt";
	list<CGameScreen*> listToLoad;
	listToLoad.push_back(new CGamePlayScreen());
	CLoadingScreen::Load(screenManager, true,listToLoad);
}

void CMainMenuScreen::ButtonCLick()
{
	if(playButton->selected) PlayButtonClick();
	else if(helpButton->selected) HelpButtonClick();
	else if(exitButton->selected) ExitButtonClick();
	else if(loadButton->selected) LoadButtonClick();
}

void CMainMenuScreen::HelpButtonClick()
{
	ExitScreen();
	screenManager->AddScreen(new CBackgroundScreen(3));
}

void CMainMenuScreen::LoadButtonClick()
{
	ExitScreen();
	screenManager->AddScreen(new CLoadScreen());
}

void CMainMenuScreen::ExitButtonClick()
{
	PostMessage(marioGame->_hWnd,WM_QUIT,0,0);
}
