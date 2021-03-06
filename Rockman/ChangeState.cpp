#include"ChangeState.h"
#include"GamestateManager.h"
#include"MenuState.h"
#include "ResourceManager.h"
#include "Define.h"

#define TIME_IN_STATE (3.0f)

CChangeState::CChangeState()
{
}
CChangeState::CChangeState(CGameStateManager* _game):CGameState(_game)
{
	 m_TimeChange = 0;
	this->m_StateManager = _game;
}
void CChangeState::Init()
{
	CGameState::Init();
	m_background = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_BG_CHANGE_STATE), D3DXVECTOR2(WIDTH_SCREEN, HEIGHT_SCREEN), 1, 1);
	
	m_time = 0;
}
void CChangeState::Update(CInput* _input,float _time)
{

	if (_input->GetKeyDown()==DIK_RETURN)
	{
		m_StateManager->ChangeState(new CMenuState(m_StateManager));
		return;
	}
}
void CChangeState::Render(LPD3DXSPRITE _spriteHandle)
{
	RECT rect = {0, 0, WIDTH_SCREEN, HEIGHT_SCREEN};
	m_background->Draw(_spriteHandle, rect, D3DX_RESIZE_FILL);
}
CChangeState::~CChangeState()
{
	delete m_background;
}

void CChangeState::DrawTextChangeState()
{
	RECT r = {325, 480, 800, 600};

	string textToDraw = "PRESS START ";
	if (m_TimeChange < TIME_IN_STATE) {
		m_StateManager->m_GraphicText->DrawText(NULL, textToDraw.c_str(), -1, &r, NULL, D3DCOLOR_XRGB(255,255,255));
		m_TimeChange += 0.16f;
	} else 
		if (m_TimeChange < TIME_IN_STATE * 2) {
			m_TimeChange += 0.16f;
		} else {
			m_TimeChange = 0;
		}
}

void CChangeState::RenderTextAndSurface()
{
	DrawTextChangeState();
}
