#include "LoadingScreen.h"

CLoadingScreen::CLoadingScreen(CScreenManager* screenManager,bool loadingIsSlow, list<CGameScreen*> screensToLoad )
{
	this->screenManager = screenManager;
	otherScreensAreGone = false;
	transTimeOn = 5000;
	this->loadingIsSlow = loadingIsSlow;
	this->screensToLoad = screensToLoad;
	spriteHandle = marioGame->GetSpriteHandle();
	d3ddv = marioGame->GetDevice3d();
	bg = CRescource::GetInstance()->GetSprite(IMAGE_LOADINGBG);
	fr = CRescource::GetInstance()->GetSurface(IMAGE_LOADINGFR);
	if(!loadingIsSlow) transTimeOn = 200;
}

CLoadingScreen::CLoadingScreen( void )
{
	
}

CLoadingScreen::~CLoadingScreen(void)
{
	bg->Release();
	fr->Release();
	d3ddv->Release();
	spriteHandle->Release();
	screensToLoad.clear();
}

void CLoadingScreen::Load( CScreenManager* screenManager,bool loadingIsSlow, list<CGameScreen*> screensToLoad )
{
	for (CGameScreen* screen :screenManager->GetScreens())
		screen->ExitScreen();
	// Create and activate the loading screen.
	CLoadingScreen* loadingScreen = new CLoadingScreen(screenManager,
		loadingIsSlow,
		screensToLoad);
	screenManager->AddScreen(loadingScreen);
}

void CLoadingScreen::Update( DWORD deltaTime, bool otherScreenHasFocus,bool coveredByOtherScreen )
{
	CGameScreen::Update(deltaTime, otherScreenHasFocus, coveredByOtherScreen);

	// If all the previous screens have finished transitioning
	// off, it is time to actually perform the load.
	if (otherScreensAreGone)
	{
		this->screenManager->RemoveScreen(this);

		for (CGameScreen* screen : screensToLoad)
		{
			if (screen != NULL)
			{
				this->screenManager->AddScreen(screen);
			}
		}
	}
}

void CLoadingScreen::Draw( DWORD deltaTime )
{
	int _alpha = (int)(TransAlpha()*255);
	RECT r;
	if ((stateScreen == StateScreen::Actived) &&
		(this->screenManager->GetScreens().size() == 1))
	{
		otherScreensAreGone = true;
	}
	if (loadingIsSlow)
	{		
		r.left = 300;
		r.top = 310-TransAlpha()*150;
		r.right = r.left+200;r.bottom = r.top+150;
		D3DXVECTOR3 pos(400-60/2,300-60/2,0);
		//--
 		d3ddv->StretchRect(fr,NULL, marioGame->_backbuffer,NULL, D3DTEXF_NONE);
		d3ddv->ColorFill(marioGame->_backbuffer, &r, D3DCOLOR_XRGB(11,248,221));
		r.top = r.left = 0;
		r.right = 800;r.bottom = 600;
 		spriteHandle->Draw(bg,&r, NULL,new D3DXVECTOR3(0,0,0), D3DCOLOR_XRGB(255,255,255));		
	}
	spriteHandle->Draw(CRescource::GetInstance()->GetSprite(IMAGE_BLANK),&r,NULL, NULL, D3DCOLOR_ARGB(255-_alpha,0,0,0));
}
