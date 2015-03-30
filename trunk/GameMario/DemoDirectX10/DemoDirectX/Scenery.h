#include "MarioGame.h"
#ifndef	_SCENERY_H
#define  _SCENERY_H
class CScenery:public CStaticObject
{
private:
protected:
	///-------
	CSprite *sprite;
	LPD3DXSPRITE spriteHandle;
	//---
	void SetKind(int kind);
public:
	CScenery(void);
	//--0-bụi cây to(300,150)
	//--1-xương rồng(150,200)
	//--2-bụi cây nhỏ(270,83)
	//--3-mồng tơi(100,271)
	//--4-cỏ(200,100)
	//--5-thông(200,250)
	//--6-diếp cá(100,100)
	//--7-mây xấu(200,100)
	//--8-chỉ đường(100,100)
	//--9-mây đẹp(200,100)
	CScenery(D3DXVECTOR3 _pos,int kind=0);
	void Render();
	void Update(CQuadTreeNode* root,DWORD t);	~CScenery(void);
};
#endif
