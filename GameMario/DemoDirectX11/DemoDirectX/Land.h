#include "MarioGame.h"
#ifndef	_LAND_H
#define  _LAND_H

class CLand:public CStaticObject
{
private:
	int startIndex;
	int kind;
	float maxTop;
	CSprite *sprite;
	LPD3DXSPRITE spriteHandle;
	void SetKind();
public:

	CLand(void);
	CLand(D3DXVECTOR3 _pos,int kind = 1);
	void Render();
	void Update(CQuadTreeNode* root,DWORD t);
	~CLand(void);
};
#endif
