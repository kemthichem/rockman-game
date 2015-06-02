#ifndef MENUSTATE_H_
#define MENUSTATE_H_
#include"GameState.h"
#include"PLayingGameState.h"
class CMenuState:public CGameState
{
private:
	int m_Select ;
	CSprite *m_menunewgame;
	CSprite *m_menuabout;
	CSprite *m_menuexit;
	CSprite *m_menuoption;
	CSprite *m_menucontinue;
	D3DXVECTOR2 m_posSelect;// vi tri ve  select 

public:
	CMenuState();
	~CMenuState();
	CMenuState(CGameStateManager* _stateManager);
	void Init();
	void CleanUp();
	void Update(CInput* ,float,CCamera* _camera);
	void Render(LPD3DXSPRITE,CCamera* _camera);
	GameStateId GetGameStateId();
};
#endif