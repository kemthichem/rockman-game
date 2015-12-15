#include "RockmanGame.h"
#include "BigEye.h"
#include "Block.h"
#include "Map.h"
#include "PLayingGameState.h"
#include "ChangeState.h"

CRockmanGame::CRockmanGame( HINSTANCE hInstance ):CGame(hInstance)
{	
}
CRockmanGame::~CRockmanGame(void)
{
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
	m_StateManager->Draw(GetSpriteHandle());
}

void CRockmanGame::UpdateWorld()
{
	m_StateManager->Update(m_time->GetDeltaTime(), m_input);
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

void CRockmanGame::RenderTextAndSurface()
{
	m_StateManager->RenderTextAndSurface();
}


