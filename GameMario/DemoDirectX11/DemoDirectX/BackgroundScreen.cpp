#include "BackgroundScreen.h"


CBackgroundScreen::CBackgroundScreen(void)
{
	d3ddv = marioGame->GetDevice3d();
	spriteHandle = marioGame->GetSpriteHandle();
	transTimeOn = transTimeOff = 1000;
	image = CRescource::GetInstance()->GetSprite(IMAGE_BGSCREEN);
}

CBackgroundScreen::CBackgroundScreen( int kind )
{
	d3ddv = marioGame->GetDevice3d();
	spriteHandle = marioGame->GetSpriteHandle();
	transTimeOn = transTimeOff = 1000;
	if(kind==1)//Game Over
	{
			image = CRescource::GetInstance()->GetSprite(IMAGE_BGGAMEOVER);
			SoundManager::GetInst()->PlayBgSound(SOUND_B_LOSE_STATE);
	}

	else if (kind==2)//Game Win
	{
		image = CRescource::GetInstance()->GetSprite(IMAGE_BGGAMEWIN);
		SoundManager::GetInst()->PlayBgSound(SOUND_B_WIN_STATE);
	}
	else if (kind==3)//Game Win
	{
		image = CRescource::GetInstance()->GetSprite(IMAGE_BGHELP);
		SoundManager::GetInst()->PlayBgSound(SOUND_B_ABOUT_STATE);
	}

}

CBackgroundScreen::~CBackgroundScreen(void)
{
	spriteHandle->Release();
	d3ddv->Release();
	image->Release();
}

void CBackgroundScreen::Update( DWORD deltaTime,bool otherScreenHasFocus,bool coverByOtherScreen )
{
	CGameScreen::Update(deltaTime,otherScreenHasFocus,coverByOtherScreen);
}
void CBackgroundScreen::Draw( DWORD deltaTime )
{
 	RECT rect;
 	rect.top = rect.left = 0;
 	rect.bottom =600; rect.right = 800;
 	D3DXVECTOR3 pos(0,0,0);
 	int _alpha = (int)(TransAlpha()*255);
 	spriteHandle->Draw(image,&rect,NULL, &pos, D3DCOLOR_XRGB(_alpha,_alpha,_alpha)); 
	
}

void CBackgroundScreen::OnKeyDown( int keyCode )
{
	switch (keyCode)
	{
	case DIK_ESCAPE:
		ExitScreen();
		screenManager->AddScreen(new CMainMenuScreen());
	default:
		break;
	}
}
