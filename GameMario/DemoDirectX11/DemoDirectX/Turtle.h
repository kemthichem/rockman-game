#include "MarioGame.h"
#ifndef	_TURTLE_H
#define  _TURTLE_H
class CTurtle:public CMotionObject
{
private:
	CSprite *sprite;
	void CheckCollision(CQuadTreeNode* root);
public:
	int state;
	CTurtle(void);
	CTurtle(D3DXVECTOR3 _pos);
	void Render();
	void SetState(int State);
	void SetLife(bool _life);
	void _Update(CQuadTreeNode* root,DWORD deltaTime);
	~CTurtle(void);
};
#endif
