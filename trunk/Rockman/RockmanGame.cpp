#include "RockmanGame.h"
#include "BigEye.h"
#include "Land.h"
#include "MoveMap.h"
#include "Map.h"
#include "PLayingGameState.h"
#include "MenuState.h"
#include "ChangeState.h"

CRockmanGame::CRockmanGame(void)
{

}
CRockmanGame::CRockmanGame( HINSTANCE hInstance ):CGame(hInstance)
{	
}
CRockmanGame::~CRockmanGame(void)
{
	//Release resource
	CResourceManager::Release();
}
LPD3DXSPRITE CRockmanGame::GetSpriteHandle()
{
	return m_SpriteHandler;
}
LPDIRECT3DDEVICE9 CRockmanGame::GetDevice3d()
{
	return _d3ddv;
}
void CRockmanGame::RenderWorld()
{	
	m_StateManager->Draw(GetSpriteHandle(), m_camera);
}

void CRockmanGame::UpdateWorld()
{
	m_StateManager->Update(m_time->GetDeltaTime(), m_camera, m_input);
}
void CRockmanGame::InitGame()
{
	CGame::InitGame();
	m_StateManager->InitFirstState(new CChangeState(m_StateManager));
}
LPD3DXFONT CRockmanGame::GetLPFont()
{
	return m_GraphicText;
}


