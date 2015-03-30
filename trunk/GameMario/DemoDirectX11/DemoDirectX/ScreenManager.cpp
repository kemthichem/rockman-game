#include "ScreenManager.h"


CScreenManager::CScreenManager(void)
{
	spriteHandle = marioGame->GetSpriteHandle();
	d3ddv = marioGame->GetDevice3d();

}


CScreenManager::~CScreenManager(void)
{
}

void CScreenManager::FadeBackBufferToBlack( float alpha )
{
	RECT rect;
	rect.top = rect.left = 0;
	rect.bottom = 600; rect.right = 800;
	D3DXVECTOR3 pos(0,0,0);
	int a = (int)(alpha*255);
	if(a!=0)
	spriteHandle->Draw(CRescource::GetInstance()->GetSprite(IMAGE_BLANK),&rect,NULL, &pos, D3DCOLOR_ARGB(a,0,0,0));
}

void CScreenManager::Draw( DWORD deltaTime )
{
	for (CGameScreen* screen: screens)
	{
		if (screen->stateScreen == CGameScreen::StateScreen::Hidden)
			continue;
		screen->Draw(deltaTime);
		
	}
	//FadeBackBufferToBlack(x);
}

void CScreenManager::Update( DWORD deltaTime )
{

	// Make a copy of the master screen list, to avoid confusion if
	// the process of updating one screen adds or removes others.
	tempScreens.clear();

	for (CGameScreen* screen : screens)
		tempScreens.push_back(screen);

	bool otherScreenHasFocus = false;//!Game.IsActive;
	 bool coveredByOtherScreen = false;

	// Loop as long as there are screens waiting to be updated.
	while (tempScreens.size() > 0)
	{
		// Pop the topmost screen off the waiting list.
		CGameScreen* screen = *(--tempScreens.cend());
		tempScreens.pop_back();

	//	tempScreensList.RemoveAt(tempScreensList.Count - 1);

		// Update the screen.
		screen->Update(deltaTime, otherScreenHasFocus,coveredByOtherScreen);

		if (screen->stateScreen == CGameScreen::StateScreen::TransitionOn ||
			screen->stateScreen == CGameScreen::StateScreen::Actived)
		{
			// If this is the first active screen we came across,
			// give it a chance to handle input.
			if (!otherScreenHasFocus)
			{
				//screen.HandleInput(gameTime, input);
				otherScreenHasFocus = true;
			}
			if (!screen->isPopup)
				coveredByOtherScreen = true;

		}
	}

}

void CScreenManager::AddScreen( CGameScreen* screen )
{
	screen->screenManager = this;
	screen->isExiting = false;
	screen->Active();
	screens.push_back(screen);
}

void CScreenManager::RemoveScreen( CGameScreen* screen )
{
	screens.remove(screen);
	tempScreens.remove(screen);
}

void CScreenManager::InKey( DWORD deltaTime )
{
	if(screens.size()!=0)
	(*--screens.cend())->InKey(deltaTime);
}

void CScreenManager::OnKeyDown( int keyCode )
{
	if(screens.size()!=0)
	(*--screens.cend())->OnKeyDown(keyCode);
}

void CScreenManager::OnKeyUp( int keyCode )
{
	if(screens.size()!=0)
	(*--screens.cend())->OnKeyUp(keyCode);
}

list<CGameScreen*> CScreenManager::GetScreens()
{
	return screens;
}

void CScreenManager::Render()
{
	for (CGameScreen* screen: screens)
	{
		if (screen->stateScreen == CGameScreen::StateScreen::Hidden)
			continue;
		screen->RenderTextAndSurface();

	}
}
