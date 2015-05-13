#include "RockmanGame.h"
#include "BigEye.h"
#include "Land.h"

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
		(*it)->Render(GetSpriteHandle(), m_camera);
	} 
}
void CRockmanGame::ProcessInput( float deltaTime )
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
void CRockmanGame::UpdateWorld(float deltaTime, CCamera *_camera, CInput *_input)
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
void CRockmanGame::InitGame()
{	
	//
	rockman = new CRockman(D3DXVECTOR3(100,600,0));
	CRockman::posInMap = D3DXVECTOR2(2000,600);

	CLand *land[15];
	land[0] = new CLand(D3DXVECTOR3(000,30,0));
	land[1] = new CLand(D3DXVECTOR3(70,30,0));
	land[2] = new CLand(D3DXVECTOR3(140,30,0));
	land[3] = new CLand(D3DXVECTOR3(210,30,0));
	land[4] = new CLand(D3DXVECTOR3(280,30,0));
	land[5] = new CLand(D3DXVECTOR3(350,30,0));
	land[6] = new CLand(D3DXVECTOR3(420,30,0));
	land[7] = new CLand(D3DXVECTOR3(490,30,0));
	land[8] = new CLand(D3DXVECTOR3(560,30,0));
	land[9] = new CLand(D3DXVECTOR3(630,30,0));
	land[10] = new CLand(D3DXVECTOR3(700,30,0));
	land[11] = new CLand(D3DXVECTOR3(770,30,0));
	land[12] = new CLand(D3DXVECTOR3(840,30,0));
	land[13] = new CLand(D3DXVECTOR3(910,30,0));
	land[14] = new CLand(D3DXVECTOR3(980,30,0));

	CBigEye *bigEye = new CBigEye(D3DXVECTOR3(300,135,0));

	listObject.push_back(rockman);
	for (int i = 0; i < 15; i++) {
		if (land[i] != NULL)
			listObject.push_back(land[i]);
	}
	listObject.push_back(bigEye);
}
LPD3DXFONT CRockmanGame::GetLPFont()
{
	return g_Font;
}


