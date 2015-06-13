#include"GameOverState.h"
#include"GamestateManager.h"
#include"MenuState.h"

#define TIME_IN_STATE (25.0f)

CGameOverState::CGameOverState()
{
}
CGameOverState::CGameOverState(CGameStateManager* _game):CGameState(_game)
{
	this->m_StateManager = _game;
}
void CGameOverState::Init()
{
	CGameState::Init();
	m_background = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_BG_GAMEOVER), D3DXVECTOR2(800,600), 1, 1);
	m_time = 0;
}
void CGameOverState::Update(CInput* _input,float _time,CCamera* _camera)
{
	if (m_time < TIME_IN_STATE) {
		m_time += _time;
	} else {
		m_StateManager->ChangeState(new CMenuState(m_StateManager));
	}	
}
void CGameOverState::Render(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	m_background->Render(_spriteHandle,D3DXVECTOR3(0,0,0));

}
CGameOverState::~CGameOverState()
{
	delete m_background;
}
