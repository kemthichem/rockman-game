#ifndef _CHANGESTATE_H_
#define _CHANGESTATE_H_
#include"GameState.h"
#include"PLayingGameState.h"
class CChangeState:public CGameState
{
private:
	CSprite *m_RockmanSprite;
	float m_TimeChange;
	void DrawTextChangeState();
public:
	CChangeState();
	~CChangeState();
	CChangeState(CGameStateManager* _stateManager);
	void Init();
	void Render(LPD3DXSPRITE);
	void Update(CInput* _input,float _time);
	virtual void RenderTextAndSurface();
	
};
#endif