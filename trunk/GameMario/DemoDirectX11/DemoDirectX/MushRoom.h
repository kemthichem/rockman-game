#include "MarioGame.h"
#ifndef	_MUSH_H
#define  _MUSH_H
class CMush:public CMushLife
{
private:
public:
	int type;
	CMush(void);
	CMush(D3DXVECTOR3 _pos,int kind = 0);
	void SetType(int type);
	void _Update(CQuadTreeNode* root,DWORD deltaTime);
	~CMush(void);
	//void CheckCollision(CQuadTreeNode* root);
};
#endif
