#include "GameState.h"
#include"GamestateManager.h"

CGameState::CGameState(void)
{
}

CGameState::CGameState(CGameStateManager* _game)
{
	this->m_StateManager = _game;
	Init();
}
void CGameState::Init()
{
	m_time = 0.0f;
	m_background = NULL;
}

void CGameState::Update(CInput* _keyboard,float _time,CCamera* _camera)
{

}

void CGameState::Render(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{

}
void CGameState::StopSoundBackGound()
{
}
CGameState::~CGameState(void)
{
}
