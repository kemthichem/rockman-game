#ifndef _HELPSTATE_H_
#define _HELPSTATE_H_
#include"GameState.h"
#include"PLayingGameState.h"
class CHelpState:public CGameState
{
private:
public:
	CHelpState();
	~CHelpState();
	CHelpState(CGameStateManager* _stateManager);
	void Init();
	void Render(LPD3DXSPRITE,CCamera* _camera);
	void Update(CInput* _input,float _time,CCamera* _camera);
};
#endif