#ifndef MENUSTATE_H_
#define MENUSTATE_H_
#include"GameState.h"
#define COUNT_ITEM 6

class CMenuState:public CGameState
{
private:
	int m_indexSelect ;
	CSprite *m_spriteItem;
	CSprite *m_spriteSelect;
	D3DXVECTOR2 m_posSelect;
	RECT arrayRectItem[COUNT_ITEM];

public:
	CMenuState();
	~CMenuState();
	CMenuState(CGameStateManager* _stateManager);
	void Init();
	void CleanUp();
	void Update(CInput* ,float);
	void Render(LPD3DXSPRITE);
	GameStateId GetGameStateId();
};
#endif