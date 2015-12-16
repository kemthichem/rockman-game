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
	CCamera *m_Camera;

	void DrawText();
	void UpdateState();
	POINT * getCameraPath();
protected:
	//virtual void CleanUp();
	virtual void Render(LPD3DXSPRITE _spriteHandle);
	virtual void Update(CInput* _input,float _time);
	virtual void RenderTextAndSurface();
	/*virtual void Init();TODO*/
public:
	CPLayingGameState(void);
	~CPLayingGameState(void);
	CPLayingGameState(CGameStateManager *_gameState);
	CRockman *rockman;
	virtual void Init();

	/**Score, Life of Rockman, Stage**/
	static int g_Score;
	static int g_Stage;
	static int g_LifeOfRockman;
	static ChangeState g_ChangeState;
};
#endif