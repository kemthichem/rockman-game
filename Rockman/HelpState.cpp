#include"HelpState.h"
#include"GamestateManager.h"
#include"PLayingGameState.h"
#include "MenuState.h"

CHelpState::CHelpState()
{
}
CHelpState::CHelpState(CGameStateManager* _game):CGameState(_game)
{
	this->m_StateManager = _game;
}
void CHelpState::Init()
{
	CGameState::Init();
	m_background = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_BG_HELP), D3DXVECTOR2(800,600), 1, 1);
	m_time = 0;
}
void CHelpState::Update(CInput* _input,float _time,CCamera* _camera)
{
	if (_input->GetKeyDown()==DIK_ESCAPE)
	{
		m_StateManager->ChangeState(new CMenuState(m_StateManager));
		return;
	}
	
}
void CHelpState::Render(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	m_background->Render(_spriteHandle, _camera, D3DXVECTOR3(0,0,0));

}
CHelpState::~CHelpState()
{
	delete m_background;
}
