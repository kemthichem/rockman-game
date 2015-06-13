#include"ChangeState.h"
#include"GamestateManager.h"
#include"PLayingGameState.h"

#define TIME_IN_STATE (25.0f)

CChangeState::CChangeState()
{
}
CChangeState::CChangeState(CGameStateManager* _game):CGameState(_game)
{
	 m_RockmanSprite = NULL;
	this->m_StateManager = _game;
}
void CChangeState::Init()
{
	CGameState::Init();
	m_background = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_BG_MENU), D3DXVECTOR2(800,600), 1, 1);
	
	m_RockmanSprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), 
		D3DXVECTOR2(960,320), 12, 4, 
		D3DXVECTOR2(0,0), D3DXVECTOR2(11,8), D3DXVECTOR2(28,14));

	m_time = 0;
}
void CChangeState::Update(CInput* _input,float _time,CCamera* _camera)
{
	if (m_time < TIME_IN_STATE) {
		m_time += _time;
		m_RockmanSprite->IndexOf(13);
	} else {
		m_StateManager->ChangeState(new CPLayingGameState(m_StateManager));
	}	
}
void CChangeState::Render(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	//m_background->Render(_spriteHandle,D3DXVECTOR3(0,0,0));
	m_RockmanSprite->Render(_spriteHandle,D3DXVECTOR3(400 - m_RockmanSprite->GetWidthRectSprite()/2 - 100,300,0));

	DrawTextChangeState();
}
CChangeState::~CChangeState()
{
	delete m_background;
	delete m_RockmanSprite;
}

void CChangeState::DrawTextChangeState()
{
	RECT r = {300, 250, 800, 600};

	string textToDraw = "Stage ";
	textToDraw.append(std::to_string(CPLayingGameState::g_Stage));
	m_StateManager->m_GraphicText->DrawText(NULL, textToDraw.c_str(), -1, &r, NULL, D3DCOLOR_XRGB(255,255,255));

	r.top = 315;
	r.left = 350;
	textToDraw = " x    ";
	textToDraw.append(std::to_string(CPLayingGameState::g_LifeOfRockman));
	m_StateManager->m_GraphicText->DrawText(NULL, textToDraw.c_str(), -1, &r, NULL, D3DCOLOR_XRGB(255,255,255));
}
