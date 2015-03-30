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
	rectScreen.bottom = HEIGHT;
}
CMarioGame::~CMarioGame(void)
{
	delete mario;
	delete quadTree;
	delete mapIO;
	spriteMarioSmall->Release();
	spriteBullet->Release();
	spriteTurtle->Release();
	spriteBlocks->Release();
	spriteEnemy->Release();
	spriteItems->Release();
	spriteMarioConvert->Release();
	spriteMarioGun->Release();
	spriteMarioLarge->Release();
	spriteScenery->Release();
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
	quadTree->Render();
}
void CMarioGame::ProcessInput( DWORD deltaTime )
{
	if(!isPause){
	if(IsKeyDown(DIK_RIGHT))
		mario->TurnRight(deltaTime);
	else
	if(IsKeyDown(DIK_LEFT))
		mario->TurnLeft(deltaTime);
	else
		if(IsKeyDown(DIK_DOWN))
			mario->Sitting(deltaTime);	
			else
			mario->Stop(deltaTime);
	}
}
void CMarioGame::UpdateWorld( DWORD deltaTime )
{
	if(isPause)
		return;
	listObjectUpdated.clear();
	//listAnimation.clear();
	UpdateRectScreen();//--
	listObjectInScreen = quadTree->ListObjectInRect(rectScreen);
	quadTree->Update(deltaTime);	
	quadTree->AddListObject(listObjectUpdated);
	list<CStaticObject*>::iterator it = listAnimation.begin();
	int n = listAnimation.size();
	for (int i = 0; i < n; i++)
	{		
		(*it)->Update(quadTree->root, deltaTime);
		if(!(*it)->visible)
			it = listAnimation.erase(it);
		else
		{
		++it;
		}
	}
}
void CMarioGame::LoadResource()
{
	background = LoadSurface(marioGame->GetDevice3d(),"Resource/background1.png" );
	spriteMarioSmall = LoadTexture(marioGame->GetDevice3d(), "Resource/marioImage/mario_small.png");
	spriteMarioLarge = LoadTexture(marioGame->GetDevice3d(), "Resource/marioImage/mario_large.png");
	spriteMarioGun = LoadTexture(marioGame->GetDevice3d(), "Resource/marioImage/mario_gun.png");
	spriteMarioConvert = LoadTexture(marioGame->GetDevice3d(), "Resource/marioImage/mario_convert.png");
	spriteBullet = LoadTexture(marioGame->GetDevice3d(),"Resource/bullet.png");
	spriteTurtle = LoadTexture(marioGame->GetDevice3d(),"Resource/turtle.png");	
	spriteBlocks = LoadTexture(marioGame->GetDevice3d(),"Resource/blocks.png");
	spriteItems = LoadTexture(marioGame->GetDevice3d(),"Resource/item.png");
	spriteEnemy = LoadTexture(marioGame->GetDevice3d(),"Resource/enemy.png");
	spriteEato = LoadTexture(marioGame->GetDevice3d(),"Resource/eato1.png");
	spriteEatoEx = LoadTexture(marioGame->GetDevice3d(),"Resource/eatoex.png");
	spriteEatoPipe = LoadTexture(marioGame->GetDevice3d(),"Resource/eato.png");
	spritePipe = LoadTexture(marioGame->GetDevice3d(),"Resource/pipe.png");
	spriteScenery = LoadTexture(marioGame->GetDevice3d(),"Resource/Scenery.png");

}
void CMarioGame::OnKeyDown( int keyCode )
{
	switch (keyCode)
	{
	case DIK_LEFT:
	case  DIK_RIGHT:
		timePressStart = GetTickCount();
		break;
	case DIK_SPACE:
 		mario->Jump();
		break;
	case DIK_A:
		mario->Shoot();
		break;
	case DIK_P:
		if(!isPause)
		isPause = true;
		else isPause = false;

	}
}
void CMarioGame::OnKeyUp( int keycode )
{
	switch (keycode)
	{
	case DIK_LEFT:
		deltaTimePress = (GetTickCount() - timePressStart)/100;
		break;
	case DIK_RIGHT:
		deltaTimePress = (GetTickCount() - timePressStart)/100;
		break;
	case  DIK_A:
		mario->NoShoot();
		break;
	}
}
void CMarioGame::UpdateRectScreen()
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
	if(mario->rectagle.top>HEIGHT/2+200)
	rectScreen.top = mario->rectagle.top - (HEIGHT/2);
	else
		rectScreen.top = 0;
	rectScreen.bottom = rectScreen.top+HEIGHT;
}
void CMarioGame::InitGame()
{	
		mapIO = new CMapIO("Map/map1.txt");
		quadTree = new CQuadTree(mapIO->GetWidht(), mapIO->GetHeight());
		mapIO->LoadMap();
		quadTree->AddListObject(listObjects);
		mario = new CMario(D3DXVECTOR3(100,0,0));
		quadTree->AddObject(mario);
}