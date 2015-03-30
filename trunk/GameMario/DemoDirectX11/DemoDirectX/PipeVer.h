#include "MarioGame.h"
#ifndef	_PIPEVER_H
#define  _PIPEVER_H
class CPipeVer:public CStaticObject
{
private:
	int kind;
	void SetKind(int kind);
protected:
	int height;
	CSprite *sprite;
public:
	CPipeVer(void);
	CPipeVer(D3DXVECTOR3 _pos,int height);
	~CPipeVer(void);
	bool IsCreep(CMario* mario,CQuadTreeNode* r);
	void Render();
	
};
#endif
