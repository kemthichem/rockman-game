#include "GamePlayScreen.h"

CGamePlayScreen::CGamePlayScreen(void)
{
	transTimeOff = 200; transTimeOn = 5000;
	spriteHandle = marioGame->GetSpriteHandle();
	isStating = false;
}

CGamePlayScreen::~CGamePlayScreen(void)
{
	delete mapIO;
	delete mario;
	spriteHandle->Release();
	gFont->Release();
	// 	listAnimation.clear();
	// 	listObjectInScreen.clear();
	// 	listObjects.clear();
	// 	listObjectUpdated.clear();
}


void CGamePlayScreen::Update( DWORD deltaTime, bool otherScreenHasFocus,bool coveredByOtherScreen )
{
	CGameScreen::Update(deltaTime, otherScreenHasFocus, false);
	// Gradually fade in or out depending on whether we are covered by the pause screen.
	if (coveredByOtherScreen)
		pauseAlpha = Min(pauseAlpha + 1.0f / 32, 1);
	else
		pauseAlpha = Max(pauseAlpha - 1.0f / 32, 0);

	if (IsActive())
	{Update(deltaTime);}

}
void CGamePlayScreen::Draw( DWORD deltaTime )
{
	Render();
	rectToDrawText.top = 300;
	if (transPosition > 0 || pauseAlpha > 0)
	{
		float alpha = Lerp(1.0f - TransAlpha(), 1.0f, pauseAlpha / 2);
		screenManager->FadeBackBufferToBlack(alpha);
	}
}
void CGamePlayScreen::Active()
{
	rectScreen.top = 0;
	rectScreen.left = 0;
	rectScreen.right = WIDTHSCREEN;
	rectScreen.bottom = HEIGHTSCREEN;
	//--------------
	marioGame->listAnimation.clear();
	marioGame->listObjectInScreen.clear();
	marioGame->listObjects.clear();
	marioGame->listObjectUpdated.clear();
	//--------------
	marioGame->score = new CScore();
	mapIO = new CMapIO(CRescource::mapFilePath.c_str());
	marioGame->quadTree = new CQuadTree(mapIO->GetWidht(), mapIO->GetHeight());
	mapIO->LoadMap();
	mario = marioGame->mario;
	marioGame->quadTree->AddListObject(marioGame->listObjects);
	if(mario->rectagle.left<WIDTHSCREEN/2)
		rectScreen.left = 0;
	else rectScreen.left =mario->rectagle.left-WIDTHSCREEN/2;
	SoundManager::GetInst()->PlayBgSound(SOUND_B_GAME1,true);
	gFont = marioGame->GetLPFont();
}	

//----------Update & Render------------------
void CGamePlayScreen::UpdateRectScreen()
{
	LONG centerX = mario->rectagle.left-(WIDTHSCREEN/2);
	int distance = 100;
	if(mario->rectagle.left>WIDTHSCREEN/2)
	{
		if(mario->IsTurn())
		{
			stand = false;
			if(mario->rectagle.left>(rectScreen.left+WIDTHSCREEN)-(WIDTHSCREEN/2-distance))
			{
				rectScreen.left = mario->rectagle.left-(WIDTHSCREEN/2+distance);
				transXLeft = true;
			}
			else if(mario->rectagle.left<rectScreen.left+(WIDTHSCREEN/2-distance))
			{
				rectScreen.left = mario->rectagle.left-(WIDTHSCREEN/2-distance);
				transXLeft = false;
			}
		}
		else
		{
			if(!stand){timeStartStand = GetTickCount();stand = true;}
			if(GetTickCount()-timeStartStand>300)
			{

				if(!transXLeft)
				{
					if(rectScreen.left > centerX)
					{
						rectScreen.left-=8;
						if(rectScreen.left<centerX) rectScreen.left = centerX;					 
					}
				}
				else
					if(rectScreen.left < centerX)
					{
						rectScreen.left+=8;
						if(rectScreen.left>centerX) rectScreen.left = centerX;					 
					}

			}
		}		
	}
	else
		if(rectScreen.left>0)
		{
			rectScreen.left-=8;
		}
		rectScreen.right = rectScreen.left+WIDTHSCREEN;
// 		if(mario->rectagle.top>HEIGHTSCREEN/2+200)
// 			rectScreen.top = mario->rectagle.top - (HEIGHTSCREEN/2);
// 		else
// 			rectScreen.top = 0;

		// rectScreen.top = rectScreen.top>0?rectScreen.top:0;
		rectScreen.bottom = rectScreen.top+HEIGHTSCREEN;
}
void CGamePlayScreen::Update( DWORD deltaTime )
{
	marioGame->rectScreen = rectScreen;
	//-----------
	marioGame->listObjectUpdated.clear();
	UpdateRectScreen();//--
	marioGame->listObjectInScreen = marioGame->quadTree->ListObjectInRect(rectScreen);
	marioGame->quadTree->Update(deltaTime);	
	marioGame->quadTree->AddListObject(marioGame->listObjectUpdated);
	list<CStaticObject*>::iterator it = marioGame->listAnimation.begin();
	int n = marioGame->listAnimation.size();
	for (int i = 0; i < n; i++)
	{		
		(*it)->Update(marioGame->quadTree->root, deltaTime);
		if(!(*it)->visible)
			it = marioGame->listAnimation.erase(it);
		else
		{
			++it;
		}
	}
	//-------Update score-----
	marioGame->score->SetTime(-1);
	if(!mario->life)//chết--game over--qua màn.
		ResetScreen();
	//---------

}
void CGamePlayScreen::Render()
{
	//if(screenManager->GetScreens().size()>=2) return;
	marioGame->quadTree->Render();
	RenderParameter();

}

void CGamePlayScreen::RenderParameter()
{


	RECT r;
	r.top = r.left = 0;
	r.bottom  =50; 
	D3DXVECTOR3 pos(10,50,0);
	for(int i = 0; i<marioGame->score->NumLife(); i++)
	{
		pos.x=(float)(i*50+5);	
		r.left = (i%2)*50;
		r.right = r.left+50;
		spriteHandle->Draw(CRescource::GetInstance()->GetSprite(IMAGE_LIFE),&r,NULL,&pos,D3DCOLOR_XRGB(255,255,255));
	}
	pos.y = 0;
	pos.x = 400;
	r.left = 100;
	r.right  = 200;
	spriteHandle->Draw(CRescource::GetInstance()->GetSprite(IMAGE_LIFE),&r,NULL,&pos,D3DCOLOR_XRGB(255,255,255));
}

void CGamePlayScreen::ResetScreen()
{
	if(!mario->visible)
	{
		if(!SoundManager::GetInst()->IsSoundEffPlaying(SOUND_E_DEATH))
		{
			marioGame->listAnimation.clear();
			marioGame->listObjectInScreen.clear();
			marioGame->listObjects.clear();
			marioGame->listObjectUpdated.clear();
			if(marioGame->score->NumLife()>=0)//còn mạng
			{
				//----------------
				int posXmario =mario->rectagle.left;
				marioGame->quadTree = new CQuadTree(mapIO->GetWidht(), mapIO->GetHeight());
				mapIO->ReLoadMap(posXmario);
				marioGame->quadTree->AddListObject(marioGame->listObjects);				
				screenManager->AddScreen(new CStateScreen());			
				mario = marioGame->mario;
				if(mario->rectagle.left<WIDTHSCREEN/2)
					rectScreen.left = 0;
				else rectScreen.left =mario->rectagle.left-WIDTHSCREEN/2;

			}
			else//game over
			{
				this->ExitScreen();
				screenManager->AddScreen(new CBackgroundScreen(1));
			}	
		}
	}
	else//win states
	{
		if(marioGame->score->WinState)
		{
			if(marioGame->score->Level()>=MAXSTATE)
			{
				ExitScreen();
				screenManager->AddScreen(new CBackgroundScreen(2));
				return;
			}

			marioGame->listAnimation.clear();
			marioGame->listObjectInScreen.clear();
			marioGame->listObjects.clear();
			marioGame->listObjectUpdated.clear();
			rectScreen.left = 0;
			marioGame->score->Reset(1,1);
			marioGame->quadTree = new CQuadTree(mapIO->GetWidht(), mapIO->GetHeight());
			mapIO = new CMapIO(CMapIO::NextMap(CRescource::mapFilePath).c_str());
			mapIO->LoadMap();
			mario = marioGame->mario;
			marioGame->quadTree->AddListObject(marioGame->listObjects);			
			screenManager->AddScreen(new CStateScreen());
		}
	}
}

void CGamePlayScreen::RenderTextAndSurface()
{
	///-------------Draw Score;
	rectToDrawText.top = 10;
	string s = "Score: ";
	s .append(std::to_string(marioGame->score->Score()));
	rectToDrawText.left = 0;	
	gFont->DrawText(NULL,s.c_str(),-1,&rectToDrawText,NULL,D3DCOLOR_XRGB(255,255,255));

	s = "Level: ";
	s.append(std::to_string(marioGame->score->Level()));
	rectToDrawText.left = 200;	
	gFont->DrawText(NULL,s.c_str(),-1,&rectToDrawText,NULL,D3DCOLOR_XRGB(255,255,255));

	s = "Time: ";
	s.append(std::to_string(marioGame->score->Time()));
	rectToDrawText.left = 650;	
	gFont->DrawText(NULL,s.c_str(),-1,&rectToDrawText,NULL,D3DCOLOR_XRGB(255,255,255));
	s = "Time: ";
	s.append(std::to_string(marioGame->score->Time()));
	rectToDrawText.left = 650;	
	gFont->DrawText(NULL,s.c_str(),-1,&rectToDrawText,NULL,D3DCOLOR_XRGB(255,255,255));
	s = "X ";
	s.append(std::to_string(marioGame->score->NumCoin()));
	rectToDrawText.left = 450;	
	gFont->DrawText(NULL,s.c_str(),-1,&rectToDrawText,NULL,D3DCOLOR_XRGB(255,255,255));
	//------
}



///---------Input----------
void CGamePlayScreen::InKey( DWORD deltaTime )
{
	if(marioGame->IsKeyDown(DIK_RIGHT))
		mario->TurnRight(deltaTime);
	else
		if(marioGame->IsKeyDown(DIK_LEFT))
			mario->TurnLeft(deltaTime);
		else
			if(marioGame->IsKeyDown(DIK_DOWN))
				mario->Sitting(deltaTime);	
			else
				mario->Stop(deltaTime);
}

void CGamePlayScreen::OnKeyDown( int keyCode )
{
	switch (keyCode)
	{
	case DIK_ESCAPE:
	case DIK_P:
		SoundManager::GetInst()->PlayEffSound(SOUND_E_PAUSE,false);
		screenManager->AddScreen(new CPauseScreen());
		break;
	case DIK_SPACE:
		mario->Jump();
		SoundManager::GetInst()->PlayEffSound(SOUND_E_JUMP,false);
		break;
	case DIK_A:
		mario->Shoot();
		break;
	case DIK_Z:
		if(mario->life&&marioGame->score->NumLife()>0)
		{
			screenManager->AddScreen(new CStateScreen());
		}
		// 		mario = new CMario(D3DXVECTOR3(100,0,0));
		// 		marioGame->quadTree->AddObject(mario);
		break;
	default:
		break;
	}
}

void CGamePlayScreen::OnKeyUp( int keyCode )
{
	switch (keyCode)
	{
	case  DIK_A:
		mario->NoShoot();
		break;
	}
}

