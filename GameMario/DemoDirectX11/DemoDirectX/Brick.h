#include "MarioGame.h"
#ifndef	_BRICK_H
#define  _BRICK_H
class CFrag;
class CBrick:public CStaticObject
{
private:
	CFrag* frapBrick[4];
	float maxTop;
	bool ex;
	void CheckCollision(CQuadTreeNode* root);
	bool isPush;
protected:
	CSprite *sprite;
	LPD3DXSPRITE spriteHandle;
public:
	void SetEx(bool _life);
	void SetPush(bool _isPush);
	
	CBrick(void);
	CBrick(D3DXVECTOR3 _pos);
	void Render();
	void Update(CQuadTreeNode* root,DWORD t);
	~CBrick(void);
};
#endif
