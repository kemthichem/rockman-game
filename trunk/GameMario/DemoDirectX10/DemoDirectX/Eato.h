#include "MarioGame.h"
#ifndef	_EATO_H
#define  _EATO_H
class CFrag;
class CEato:public CMotionObject
{
private:
	bool isEx;
	DWORD timeStartEx;
	DWORD timeStartGrow;
	int kind;
	int maxTop;
	int turnDown;
protected:
	CSprite *sprite;
	LPD3DXSPRITE spriteHandle;
public:
	CEato(void);
	CEato(D3DXVECTOR3 _pos,int kind = 0);
	void Render();
	void Update(CQuadTreeNode* root,DWORD t);
	void SetLifeEx();
	~CEato(void);
};
#endif
