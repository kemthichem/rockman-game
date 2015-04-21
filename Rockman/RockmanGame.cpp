#include "RockmanGame.h"

CRockmanGame::CRockmanGame(void)
{
}
CRockmanGame::CRockmanGame( HINSTANCE hInstance ):CGame(hInstance)
{	
}
CRockmanGame::~CRockmanGame(void)
{
	//delete rockman;
	for(list<CEntity*>::const_iterator it = listObject.begin(); it != listObject.end(); it++)
	{
		delete *it;
	} 
	listObject.clear();
}
LPD3DXSPRITE CRockmanGame::GetSpriteHandle()
{
	return _spriteHandler;
}
LPDIRECT3DDEVICE9 CRockmanGame::GetDevice3d()
{
	return _d3ddv;
}
void CRockmanGame::Render()
{
	for(list<CEntity*>::const_iterator it = listObject.begin(); it != listObject.end(); it++)
	{
		(*it)->Render(GetSpriteHandle(), mCamera);
	} 
}
void CRockmanGame::ProcessInput( DWORD deltaTime )
{
	/*if(IsKeyDown(DIK_RIGHT))
		rockman->TurnRight(deltaTime);
	else
		if(IsKeyDown(DIK_LEFT))
			rockman->TurnLeft(deltaTime);
		else
			if(IsKeyDown(DIK_DOWN))
				rockman->Sitting(deltaTime);	
			else
				rockman->Stop(deltaTime);*/
}
void CRockmanGame::UpdateWorld(DWORD deltaTime, CCamera *_camera, CInput *_input)
{
	for(list<CEntity*>::const_iterator it = listObject.begin(); it != listObject.end(); it++)
	{
		(*it)->Update(deltaTime, _camera, _input);
	} 
}
void CRockmanGame::RenderTextAndSurface()
{
	//screenManager->Render();
}
void CRockmanGame::OnKeyDown( int keyCode )
{
	//switch (keyCode)
	//{
	//case DIK_LEFT:
	//	//	SoundManager::GetInst()->PlayEffSound(SOUND_E_JUMP,false);
	//	break;
	//case  DIK_RIGHT:
	//	timePressStart = GetTickCount();
	//	break;
	//case DIK_SPACE:
	//	rockman->Jump();
	//	break;
	//case DIK_A:
	//	rockman->Shoot();
	//	break;
	//	//case DIK_P:
	//	//if(!isPause)
	//	//isPause = true;
	//	//else isPause = false;

	//}
	//screenManager->OnKeyDown(keyCode);
}
void CRockmanGame::OnKeyUp( int keycode )
{
	/*switch (keycode)
	{
	case DIK_LEFT:
		deltaTimePress = (GetTickCount() - timePressStart)/100;
		break;
	case DIK_RIGHT:
		deltaTimePress = (GetTickCount() - timePressStart)/100;
		break;
	case  DIK_A:
		rockman->NoShoot();
		break;
	}*/
	//screenManager->OnKeyUp(keycode);
}
void CRockmanGame::UpdateRectScreen()
{
	// 	LONG centerX = rockman->rectagle.left-(WIDTHSCREEN/2);
	// 	int distance = 100;
	// 	if(rockman->rectagle.left>WIDTHSCREEN/2)
	// 	{
	// 		if(rockman->IsTurn())
	// 		{
	// 			stand = false;
	// 			if(rockman->rectagle.left>(rectScreen.left+WIDTHSCREEN)-(WIDTHSCREEN/2-distance))
	// 			{
	// 				rectScreen.left = rockman->rectagle.left-(WIDTHSCREEN/2+distance);
	// 				transXLeft = true;
	// 			}
	// 			else if(rockman->rectagle.left<rectScreen.left+(WIDTHSCREEN/2-distance))
	// 			{
	// 				rectScreen.left = rockman->rectagle.left-(WIDTHSCREEN/2-distance);
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
	// 	if(rockman->rectagle.top>HEIGHTSCREEN/2+200)
	// 	rectScreen.top = rockman->rectagle.top - (HEIGHTSCREEN/2);
	// 	else
	// 		rectScreen.top = 0;
	// 
	// 	// rectScreen.top = rectScreen.top>0?rectScreen.top:0;
	//  	rectScreen.bottom = rectScreen.top+HEIGHTSCREEN;
}
void CRockmanGame::InitGame()
{	
	//
	rockman = new CRockman(D3DXVECTOR3(100,100,0));
	CRockman::posInMap = D3DXVECTOR2(1000,600);
	listObject.push_back(rockman);
}
LPD3DXFONT CRockmanGame::GetLPFont()
{
	return g_Font;
}


