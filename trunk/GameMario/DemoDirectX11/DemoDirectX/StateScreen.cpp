#include "StateScreen.h"


CStateScreen::CStateScreen(void)
{
	gFont = marioGame->GetLPFont();
	spriteHandle = marioGame->GetSpriteHandle();
	//-------
	transTimeOff = transTimeOn = 1000;

}


CStateScreen::~CStateScreen(void)
{
	spriteHandle->Release();
	gFont->Release();

}

void CStateScreen::Draw( DWORD deltaTime )
{
	RECT r;
	r.top = r.left = 0;
	r.bottom = 600;
	r.right = 800;
	//spriteHandle->Draw(CRescource::GetInstance()->GetSprite(IMAGE_BG1),&r,NULL, new D3DXVECTOR3(0,0,0),D3DCOLOR_XRGB(255,255,255));
	marioGame->GetDevice3d()->Clear(0, 0, D3DCLEAR_TARGET, D3DCOLOR_XRGB(101, 242, 230), 1.0f, 0);
	//---------
	 	r.top = 0;r.left = 0;
	 	r.bottom = 50;
	 	r.right = 50;
		spriteHandle->Draw(CRescource::GetInstance()->GetSprite(IMAGE_LIFE),&r,NULL, new D3DXVECTOR3(325,HEIGHTSCREEN/2-10,0),D3DCOLOR_XRGB(255,255,255));

}

void CStateScreen::Active()
{
	level = marioGame->score->Level();
	life = marioGame->score->NumLife();
	//marioGame->score->SetTime(0);
	timeStartScreen = GetTickCount();

	SoundManager::GetInst()->PlayBgSound(SOUND_B_LOSE_STATE,false);
}

void CStateScreen::Update( DWORD deltaTime, bool otherScreenHasFocus,bool coverByOtherScreen )
{
	if(GetTickCount() - timeStartScreen>7000)
	{
		screenManager->RemoveScreen(this);
		SoundManager::GetInst()->PlayBgSound(SOUND_B_GAME1,true);

	}
}

void CStateScreen::RenderTextAndSurface()
{
	RECT r;
	r.top = r.left = 0;
	r.bottom = 600;
	r.right = 800;
	//spriteHandle->Draw(CRescource::GetInstance()->GetSprite(IMAGE_BLANK),&r,NULL, new D3DXVECTOR3(0,0,0),D3DCOLOR_XRGB(255,255,255));
	//marioGame->GetDevice3d()->StretchRect(CRescource::GetInstance()->GetSurface(IMAGE_BLANK),&r,marioGame->_backbuffer,NULL,D3DTEXF_NONE);
	rectToDrawText.top = HEIGHTSCREEN/2;
	string s = " X ";
	s.append(to_string(life));
	gFont->DrawText(NULL, s.c_str(),-1,&rectToDrawText,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	//----
	rectToDrawText.top = HEIGHTSCREEN/2-50;
	s = "WORLD ";
	s.append(to_string(level));
	gFont->DrawText(NULL, s.c_str(),-1,&rectToDrawText,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
}
