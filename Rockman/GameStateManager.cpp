#include "GameStateManager.h"
#include "GameState.h"

CGameStateManager::CGameStateManager(void)
{
}

void CGameStateManager::InitFirstState(CGameState* _state)
{
	m_ListState.push_back(_state);
	m_ListState.back()->Init();
}
void CGameStateManager::Init(HWND _wndHandle,LPD3DXSPRITE _spriteHandler, LPD3DXFONT _font)
{
	this->m_wndHandle = _wndHandle;
	m_spriteHandle = _spriteHandler;
	m_GraphicText = _font;
}
void CGameStateManager::CleanUp()
{
	D3DXMATRIX reset;
	D3DXMatrixIdentity(&reset);
	m_spriteHandle->SetTransform(&reset);
}
void CGameStateManager::ChangeState(CGameState* _nextState)
{
	this->m_nextState = _nextState;

	if (!m_ListState.empty())
	{
		CleanUp();
		delete m_ListState.back();
		m_ListState.pop_back();
	}

	m_ListState.push_back(m_nextState);
	m_ListState.back()->Init();
}
void CGameStateManager::Update(float _time, CInput *_input)
{
	m_ListState.back()->Update(_input, _time);
}

void CGameStateManager::Draw(LPD3DXSPRITE _spriteHandler)
{
	m_ListState.back()->Render(_spriteHandler);
}
CGameStateManager::~CGameStateManager(void)
{
	for(int i = 0; i < m_ListState.size(); ++i)
		delete m_ListState[i];
	m_ListState.empty();
}

void CGameStateManager::RenderTextAndSurface()
{
	m_ListState.back()->RenderTextAndSurface();
}
