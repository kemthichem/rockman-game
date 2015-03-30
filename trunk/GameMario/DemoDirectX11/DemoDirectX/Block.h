#include "MarioGame.h"
#ifndef	_BLOCK_H
#define  _BLOCK_H

class CBlock:public CStaticObject
{
private:
	CSprite *sprite;
	LPD3DXSPRITE spriteHandle;
	void SetKind(int kind);
public:

	CBlock(void);
	CBlock(D3DXVECTOR3 _pos,int kind = 1);
	void Render();
	void Update(CQuadTreeNode* root,DWORD t);
	~CBlock(void);
};
#endif
