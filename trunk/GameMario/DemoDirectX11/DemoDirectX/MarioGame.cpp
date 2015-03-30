#include "MarioGame.h"
CMarioGame::CMarioGame(void)
{
}
CMarioGame::CMarioGame( HINSTANCE hInstance ):CGame(hInstance)
{	
	isPause = false;
	rectScreen.top = 0;
	rectScreen.left = 0;
	rectScreen.right = WIDTHSCREEN;
	rectScreen.bottom = HEIGHTSCREEN;
}
CMarioGame::~CMarioGame(void)
{
	//delete mario;
	delete quadTree;
	delete mario;
/*	spriteMarioSmall->Release();*/
// 	spriteBullet->Release();
// 	spriteTurtle->Release();
// 	spriteBlocks->Release();
// 	spriteEnemy->Release();
// 	spriteItems->Release();
// 	spriteMarioConvert->Release();
// 	spriteMarioGun->Release();
// 	spriteMarioLarge->Release();
	//spriteScenery->Release();
}
LPD3DXSPRITE CMarioGame::GetSpriteHandle()
{
	return _spriteHandler;
}
LPDIRECT3DDEVICE9 CMarioGame::GetDevice3d()
{
	return _d3ddv;
}
void CMarioGame::Render()
{
	screenManager->Draw(1000/30);
	//quadTree->Render();
}
void CMarioGame::ProcessInput( DWORD deltaTime )
{

	screenManager->InKey(deltaTime);
}
void CMarioGame::UpdateWorld( DWORD deltaTime )
{
	//if(isPause)
	//	return;
	//listObjectUpdated.clear();
	//UpdateRectScreen();//--
	//listObjectInScreen = quadTree->ListObjectInRect(rectScreen);
	//quadTree->Update(deltaTime);	
	//quadTree->AddListObject(listObjectUpdated);
	//list<CStaticObject*>::iterator it = listAnimation.begin();
	//int n = listAnimation.size();
	//for (int i = 0; i < n; i++)
	//{		
	//	(*it)->Update(quadTree->root, deltaTime);
	//	if(!(*it)->visible)
	//		it = listAnimation.erase(it);
	//	else
	//	{
	//		++it;
	//	}
	//}
	screenManager->Update(deltaTime);

}
void CMarioGame::RenderTextAndSurface()
{
	screenManager->Render();
}
void CMarioGame::OnKeyDown( int keyCode )
{
// 	switch (keyCode)
// 	{
// 	case DIK_LEFT:
// 	//	SoundManager::GetInst()->PlayEffSound(SOUND_E_JUMP,false);
// 		break;
// 	case  DIK_RIGHT:
// 		timePressStart = GetTickCount();
// 		break;
// 	case DIK_SPACE:
//  		mario->Jump();
// 		break;
// 	case DIK_A:
// 		mario->Shoot();
// 		break;
// 	case DIK_P:
// 		if(!isPause)
// 		isPause = true;
// 		else isPause = false;
// 
// 	}
	screenManager->OnKeyDown(keyCode);
}
void CMarioGame::OnKeyUp( int keycode )
{
// 	switch (keycode)
// 	{
// 	case DIK_LEFT:
// 		deltaTimePress = (GetTickCount() - timePressStart)/100;
// 		break;
// 	case DIK_RIGHT:
// 		deltaTimePress = (GetTickCount() - timePressStart)/100;
// 		break;
// 	case  DIK_A:
// 		mario->NoShoot();
// 		break;
// 	}
	screenManager->OnKeyUp(keycode);
}
void CMarioGame::UpdateRectScreen()
 {
// 	LONG centerX = mario->rectagle.left-(WIDTHSCREEN/2);
// 	int distance = 100;
// 	if(mario->rectagle.left>WIDTHSCREEN/2)
// 	{
// 		if(mario->IsTurn())
// 		{
// 			stand = false;
// 			if(mario->rectagle.left>(rectScreen.left+WIDTHSCREEN)-(WIDTHSCREEN/2-distance))
// 			{
// 				rectScreen.left = mario->rectagle.left-(WIDTHSCREEN/2+distance);
// 				transXLeft = true;
// 			}
// 			else if(mario->rectagle.left<rectScreen.left+(WIDTHSCREEN/2-distance))
// 			{
// 				rectScreen.left = mario->rectagle.left-(WIDTHSCREEN/2-distance);
// 				transXLeft = false;
// 			}
// 		}
// 		else
// 		{
// 			if(!stand){timeStartStand = GetTickCount();stand = true;}
// 			if(GetTickCount()-timeStartStand>300)
// 			{
// 
// 				if(!transXLeft)
// 				{
// 					if(rectScreen.left > centerX)
// 					{
// 						rectScreen.left-=8;
// 						if(rectScreen.left<centerX) rectScreen.left = centerX;					 
// 					}
// 				}
// 				else
// 					if(rectScreen.left < centerX)
// 					{
// 						rectScreen.left+=8;
// 						if(rectScreen.left>centerX) rectScreen.left = centerX;					 
// 					}
// 	
// 			}
// 		}		
// 	}
// 	else
// 		if(rectScreen.left>0)
// 		{
// 			rectScreen.left-=8;
// 		}
// 	rectScreen.right = rectScreen.left+WIDTHSCREEN;
// 	if(mario->rectagle.top>HEIGHTSCREEN/2+200)
// 	rectScreen.top = mario->rectagle.top - (HEIGHTSCREEN/2);
// 	else
// 		rectScreen.top = 0;
// 
// 	// rectScreen.top = rectScreen.top>0?rectScreen.top:0;
//  	rectScreen.bottom = rectScreen.top+HEIGHTSCREEN;
}
void CMarioGame::InitGame()
{	
	/*mapIO = new CMapIO("Map/map1.txt");
	quadTree = new CQuadTree(mapIO->GetWidht(), mapIO->GetHeight());
	mapIO->LoadMap();
	quadTree->AddListObject(listObjects);
	mario = new CMario(D3DXVECTOR3(100,0,0));
	quadTree->AddObject(mario);*/
	//
	mario = new CMario(D3DXVECTOR3(0,0,0));
	screenManager = new CScreenManager();
	screenManager->AddScreen(new CBackgroundScreen());
	screenManager->AddScreen(new CMainMenuScreen());

}
LPD3DXFONT CMarioGame::GetLPFont()
{
	return g_Font;
}
