#include "MarioGame.h"
#ifndef	_PIPEHOR_H
#define  _PIPEHOR_H
class CPipeHor:public CStaticObject
{
private:
	void SetKind(int kind);
	int width;
protected:
	CSprite *sprite;
public:
	CPipeHor(void);
	CPipeHor(D3DXVECTOR3 _pos,int kind = 1);
	void Render();
	bool IsCreep(CMario* mario);
	~CPipeHor(void);
};
#endif
