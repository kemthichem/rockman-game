#include "MarioGame.h"
#ifndef	_COIN_H
#define  _COIN_H
class CCoin:public CMotionObject
{
private:
	int kind;
	int state;	
	void Update1();
	void Update2();
protected:	
	int firstTop;
	CSprite *sprite;	
public:	
	CCoin(void);
	CCoin(D3DXVECTOR3 _pos,int kind = 0);
	CCoin(D3DXVECTOR3 _pos,bool life);
	void Render();	
	void SetState(int _state);
	void SetLife(bool _life);
	void _Update(CQuadTreeNode* root,DWORD deltaTime);
	~CCoin(void);
};
#endif
