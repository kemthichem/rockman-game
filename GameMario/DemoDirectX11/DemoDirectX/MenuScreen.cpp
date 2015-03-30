#include "MenuScreen.h"

CMenuScreen::CMenuScreen(void)
{
	transTimeOff = 100; transTimeOn = 2000;
	menuTitle = "Menu Screen";
}

CMenuScreen::~CMenuScreen(void)
{
	listButton.clear();
	
}

void CMenuScreen::Active()
{
	float y = 140;
	float center = 800/2;
	int n = listButton.size();
	list<CButtonGame*>::iterator it = listButton.begin();
	for (int i = 0; i < n; i++)
	{
		RECT r = (*it)->sRect;
		 D3DXVECTOR3 _pos(center-(r.right-r.left)/2,y+(i*((r.bottom-r.top)+20)),0);		
		 (*it)->pos = _pos;
		 it++;
	}
	//-------------
	countButton = listButton.size();
	indexSelected = 0;
}

void CMenuScreen::Update( DWORD deltaTime, bool otherScreenHasFocus,bool coverByOtherScreen )
{
	//------------
	list<CButtonGame*>::iterator it = listButton.begin();
	for(;it!=listButton.end();it++)
	{
		(*it)->alpha = TransAlpha();
		(*it)->selected = (*it)->Index ==indexSelected;
		//(*it)->Update(deltaTime);
	}
	CGameScreen::Update(deltaTime,otherScreenHasFocus,coverByOtherScreen);
}

void CMenuScreen::Draw( DWORD deltaTime )
{

	// Draw all of the buttons
	for(CButtonGame* b: listButton)
		b->Draw(deltaTime);

	//---------

}

void CMenuScreen::NextIndex(bool increas)
{
	//if(indexSelected==-1&&stateScreen!=StateScreen::Actived) return;
	if(increas)
		indexSelected = (indexSelected+1)%countButton;
	else
		indexSelected = (indexSelected+countButton-1)%countButton;
}

void CMenuScreen::AddButton( CButtonGame* b )
{
	b->Index =listButton.size();
	listButton.push_back(b);
}

///---------------------------
void CMenuScreen::InKey( DWORD deltaTime )
{

}

void CMenuScreen::OnKeyDown( int keyCode )
{
	switch (keyCode)
	{
	case DIK_DOWN:
		NextIndex(true);
		break;
	case DIK_UP:
		NextIndex(false);
		break;
	case DIK_RETURN:
		ButtonCLick();
		break;
	default:
		break;
	}
}



void CMenuScreen::RenderTextAndSurface()
{

	// Draw the menu title centered on the screen
	float transitionOffset = (float)pow(transPosition,2);
	
	LONG posYDrawText = 80;
	posYDrawText -= (LONG)(transitionOffset*100);
	rectToDrawText.top = posYDrawText;
	marioGame->GetLPFont()->DrawText(NULL,menuTitle,-1,&rectToDrawText,DT_CENTER,
		D3DCOLOR_XRGB(255,255,255));

	for(CButtonGame* b: listButton)
		b->DrawTextA();
}



