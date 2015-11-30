#include"About.h"
#include"GamestateManager.h"
#include"PLayingGameState.h"
#include "MenuState.h"

CAboutState::CAboutState()
{
}
CAboutState::CAboutState(CGameStateManager* _game):CGameState(_game)
{
	this->m_StateManager = _game;
}
void CAboutState::Init()
{
	CGameState::Init();
	m_background = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_BG_ABOUT), D3DXVECTOR2(800,600), 1, 1);
	m_time = 0;
}
void CAboutState::Update(CInput* _input,float _time)
{
	if (_input->GetKeyDown()==DIK_ESCAPE)
	{
		m_StateManager->ChangeState(new CMenuState(m_StateManager));
		return;
	}
	
}
void CAboutState::Render(LPD3DXSPRITE _spriteHandle)
{
	m_background->Render(_spriteHandle, NULL, D3DXVECTOR3(0,0,0));

}
CAboutState::~CAboutState()
{
	delete m_background;
}
