#ifndef _ABOUTSTATE_H_
#define _ABOUTSTATE_H_
#include"GameState.h"
class CAboutState:public CGameState
{
private:
public:
	CAboutState();
	~CAboutState();
	CAboutState(CGameStateManager* _stateManager);
	void Init();
	void Render(LPD3DXSPRITE);
	void Update(CInput* _input,float _time);
};
#endif