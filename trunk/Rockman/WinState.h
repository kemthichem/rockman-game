#ifndef  _WINSTATE_H_
#define _WINSTATE_H_
#include"GameState.h"
#include"PLayingGameState.h"
class CWinState:public CGameState
{
private:
public:
	CWinState();
	~CWinState();
	CWinState(CGameStateManager* _stateManager);
	void Init();
	void Render(LPD3DXSPRITE,CCamera* _camera);
	void Update(CInput* _input,float _time,CCamera* _camera);
};
#endif