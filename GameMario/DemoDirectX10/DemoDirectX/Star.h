#include "MarioGame.h"
#ifndef	_STAR_H
#define  _STAR_H
class CStar:public CMushLife
{
private:
	void CheckCollision(CQuadTreeNode* root);
	void Bounce();
public:
	CStar(void);
	CStar(D3DXVECTOR3 _pos);
	void SetState(int _state);
	void _Update(CQuadTreeNode* root,DWORD deltaTime);
	~CStar(void);

};
#endif
