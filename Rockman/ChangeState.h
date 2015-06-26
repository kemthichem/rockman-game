#ifndef _CHANGESTATE_H_
#define _CHANGESTATE_H_
#include"GameState.h"
#include"PLayingGameState.h"
class CChangeState:public CGameState
{
private:
	CSprite *m_RockmanSprite;
	void DrawTextChangeState();
public:
	CChangeState();
	~CChangeState();
	CChangeState(CGameStateManager* _stateManager);
	void Init();
	void Render(LPD3DXSPRITE,CCamera* _camera);
	void Update(CInput* _input,float _time,CCamera* _camera);
	virtual void RenderTextAndSurface();
	
};
#endif