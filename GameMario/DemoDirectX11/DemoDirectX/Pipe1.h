#include "MarioGame.h"
#ifndef	_PIPE1_H
#define  _PIPE1_H
class CPipe1:public CPipeVer
{
private:
	CEato *eato;
	void SetKind(int kind);
protected:
public:	
	int state;
	CPipe1(void);
	CPipe1(D3DXVECTOR3 _pos,int kind);
	~CPipe1(void);
};
#endif
