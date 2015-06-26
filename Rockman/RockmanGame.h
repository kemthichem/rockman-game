#ifndef	_ROCKMANGAME_H
#define _ROCKMANGAME_H
//---
#include "utils.h"
#include "Game.h"
#include "Rockman.h"
#include "QuadTree.h"

class CRockmanGame : public CGame
{	
private:
	CQuadTree *quadTree;

protected:
	virtual void RenderWorld();
	virtual void UpdateWorld();
	virtual void RenderTextAndSurface();
	
public:
	LPD3DXSPRITE GetSpriteHandle();
	LPDIRECT3DDEVICE9 GetDevice3d();
	LPD3DXFONT GetLPFont();
	CRockmanGame(void);
	CRockmanGame(HINSTANCE hInstance);
	CRockman *rockman;
	virtual void InitGame();
	vector<CEntity*> m_listObject;
	~CRockmanGame(void);
};

#endif