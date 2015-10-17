#ifndef PLAYINGSTATE_H_
#define PLAYINGSTATE_H_

#include "utils.h"
#include "Game.h"
#include "Rockman.h"
#include "QuadTree.h"
#include "GameState.h"
#include"GameStateManager.h"
#include "Map.h"
#include "SceneryTile.h"

enum ChangeState
{
	CHANGE_NONE,
	CHANGE_NEXT,
	CHANGE_FAIL
};

class CPLayingGameState : public CGameState
{
private:
	CQuadTree *quadTree;
	CMap m_Map;
	CSceneryTile *m_ScereryTile;

	void DrawText();
	void UpdateState();
protected:
	//virtual void CleanUp();
	virtual void Render(LPD3DXSPRITE _spriteHandle,CCamera* _camera);
	virtual void Update(CInput* _input,float _time,CCamera* _camera);
	virtual void RenderTextAndSurface();
	virtual void Init();
public:
	CPLayingGameState(void);
	~CPLayingGameState(void);
	CPLayingGameState(CGameStateManager *_gameState);
	CRockman *rockman;

	/**Score, Life of Rockman, Stage**/
	static int g_Score;
	static int g_Stage;
	static int g_LifeOfRockman;
	static ChangeState g_ChangeState;
};
#endif