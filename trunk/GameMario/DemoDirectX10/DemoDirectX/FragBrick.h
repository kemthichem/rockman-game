#include "MarioGame.h"
#ifndef	_FRAG_H
#define  _FRAG_H
class CFrag:public CMotionObject
{
private:
	CSprite *sprite;
	LPD3DXSPRITE spriteHandle;
public:
	int state;
	CFrag(void);
	CFrag(D3DXVECTOR3 _pos, int vx,int vy);
	void Render();
	void _Update(CQuadTreeNode* root,DWORD deltaTime);
	~CFrag(void);
};
#endif
