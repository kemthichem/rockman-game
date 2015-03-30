#include "MarioGame.h"
#ifndef	_ENEMY_H
#define  _ENEMY_H
class CEnemy:public CMotionObject
{
private:
	CSprite *sprite;
	void CheckCollision(CQuadTreeNode* root);
	int stateDie;
	DWORD timeStartDie;
public:
	CEnemy(void);
	CEnemy(D3DXVECTOR3 _pos);
	void Render();
	void SetLife(bool _life);
	void SetLife0(bool _life);
	void _Update(CQuadTreeNode* root,DWORD deltaTime);
	~CEnemy(void);
};
#endif
