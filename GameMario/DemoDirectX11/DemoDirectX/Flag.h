#include "MarioGame.h"
#ifndef	_FLAG_H
#define  _FLAG_H

class CFlag:public CStaticObject
{
private:
	CSprite *spritePillars;
	CSprite *spriteFlag;
	LPD3DXSPRITE spriteHandle;
	int state;
	LONG posYFlag;
public:

	CFlag(void);
	CFlag(D3DXVECTOR3 _pos);
	~CFlag(void);
	void Render();
	void Update(CQuadTreeNode* root,DWORD t);
	void SetState();
	
};
#endif
