#ifndef _OVERCHANGESTATE_H_
#define _OVERCHANGESTATE_H_
#include"GameState.h"
#include"PLayingGameState.h"
class CGameOverState:public CGameState
{
private:
public:
	CGameOverState();
	~CGameOverState();
	CGameOverState(CGameStateManager* _stateManager);
	void Init();
	void Render(LPD3DXSPRITE);
	void Update(CInput* _input,float _time);
};
#endif