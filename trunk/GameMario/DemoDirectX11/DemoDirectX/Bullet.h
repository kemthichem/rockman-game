#include "MarioGame.h"
#ifndef	_BULLET_H
#define  _BULLET_H
class CBullet:public CMotionObject
{
private:
	CSprite *sprite;
	void CheckCollision(CQuadTreeNode* root);
	void Bounce();
	int state;
	DWORD timeStartEx;
public:

	CBullet(void);
	CBullet(D3DXVECTOR3 _pos);
	void Set(D3DXVECTOR3 _pos, int dir);
	void Render();
	void Setlife(bool _life);
	void SetEx(bool _ex);
	void _Update(CQuadTreeNode* root,DWORD deltaTime);
	~CBullet(void);
};
#endif
