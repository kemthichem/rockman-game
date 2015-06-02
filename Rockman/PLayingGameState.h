#ifndef PLAYINGSTATE_H_
#define PLAYINGSTATE_H_

#include "utils.h"
#include "Game.h"
#include "Rockman.h"
#include "QuadTree.h"
#include "GameState.h"
#include"GameStateManager.h"

class CPLayingGameState : public CGameState
{
private:
	CQuadTree *quadTree;


protected:
	//virtual void CleanUp();
	virtual void Render(LPD3DXSPRITE _spriteHandle,CCamera* _camera);
	virtual void Update(CInput* _input,float _time,CCamera* _camera);
	virtual void Init();
public:
	CPLayingGameState(void);
	CPLayingGameState(CGameStateManager *_gameState);
	CRockman *rockman;

	vector<CEntity*> m_listObject;
	~CPLayingGameState(void);
};
#endif