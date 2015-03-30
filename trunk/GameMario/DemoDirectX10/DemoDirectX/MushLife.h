#include "MarioGame.h"
#ifndef	_MUSHLIFE_H
#define  _MUSHLIFE_H
class CMushLife:public CMotionObject
{
private:

protected:
	int kind;
	CSprite *sprite;
	void CheckCollision(CQuadTreeNode* root);
	float firstTop;
	void Update1();
	void Update2();
public:
	
	int state;
	CMushLife(void);
	CMushLife(D3DXVECTOR3 _pos,int kind = 0);
	void Render();
	void SetState(int _state);
	void SetLife(bool _life);
	void _Update(CQuadTreeNode* root,DWORD deltaTime);
	~CMushLife(void);
};
#endif
