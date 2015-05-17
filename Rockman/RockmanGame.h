#ifndef	_ROCKMANGAME_H
#define _ROCKMANGAME_H
//---
#include "utils.h"
#include "Game.h"
#include "Entity.h"
#include "Rockman.h"
#include "BigEye.h"
#include "QuadTree.h"


class CRockmanGame : public CGame
{	
private:
	CQuadTree *quadTree;

	void Render();
	void UpdateWorld(float, CCamera*, CInput*);
	void ProcessInput(float deltaTime);
	void InitGame();
public:
	LPD3DXSPRITE GetSpriteHandle();
	LPDIRECT3DDEVICE9 GetDevice3d();
	LPD3DXFONT GetLPFont();
	CRockmanGame(void);
	CRockmanGame(HINSTANCE hInstance);
	CRockman *rockman;
	CBigEye *bigEye;

	list<CEntity*> m_listObject;
	~CRockmanGame(void);
};

#endif