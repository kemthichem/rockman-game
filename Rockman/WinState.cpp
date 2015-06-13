#include"WinState.h"
#include"GamestateManager.h"
#include"PLayingGameState.h"
#include "MenuState.h"

CWinState::CWinState()
{
}
CWinState::CWinState(CGameStateManager* _game):CGameState(_game)
{
	this->m_StateManager = _game;
}
void CWinState::Init()
{
	CGameState::Init();
	m_background = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_BG_WIN), D3DXVECTOR2(800,600), 1, 1);
	m_time = 0;
}
void CWinState::Update(CInput* _input,float _time,CCamera* _camera)
{
	if (_input->GetKeyDown()==DIK_ESCAPE)
	{
		m_StateManager->ChangeState(new CMenuState(m_StateManager));
		return;
	}
	
}
void CWinState::Render(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	m_background->Render(_spriteHandle,D3DXVECTOR3(0,0,0));

}
CWinState::~CWinState()
{
	delete m_background;
}
