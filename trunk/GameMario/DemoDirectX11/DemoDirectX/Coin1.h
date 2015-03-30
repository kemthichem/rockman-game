#include "MarioGame.h"
#ifndef	_COIN1_H
#define  _COIN1_H
class CCoin1:public CCoin
{
private:
	int numCoin;
	void CheckCollision( CQuadTreeNode* root );
	bool isPush;
	int maxTop;
protected:

public:
	CCoin1(void);
	///----number Coin =1;
	CCoin1(D3DXVECTOR3 _pos,int numCoin=1);
	void SetNumCoin();
	void _Update(CQuadTreeNode* root,DWORD deltaTime);
	~CCoin1(void);
};
#endif
