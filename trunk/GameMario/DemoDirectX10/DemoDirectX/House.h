#include "MarioGame.h"
#ifndef	_HOUSE_H
#define  _HOUSE_H

class CHouse:public CStaticObject
{
private:
	CSprite *spriteHouse;
	CSprite *spriteFire;
	LPD3DXSPRITE spriteHandle;
	int state;
	LONG posIndex;
	D3DXVECTOR3 posFire[10];
	int bonus;
	void SetPosGun();
	//----
	DWORD timeStartWin;
	DWORD timePreFire;
public:

	CHouse(void);
	CHouse(D3DXVECTOR3 _pos);
	~CHouse(void);
	void Render();
	void Update(CQuadTreeNode* root,DWORD t);
	void SetState(int bonus=1);
	
};
#endif
