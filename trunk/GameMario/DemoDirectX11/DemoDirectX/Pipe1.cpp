#include "Pipe1.h"
CPipe1::CPipe1(void)
{
}
CPipe1::CPipe1( D3DXVECTOR3 _pos,int kind):CPipeVer(_pos,kind)
{
	eato = new CEato(D3DXVECTOR3(pos.x+25, pos.y, 0),1);
	marioGame->quadTree->AddObject(eato);
	SetKind(kind);
}
CPipe1::~CPipe1(void)
{
}
void CPipe1::SetKind( int kind )
{
	
		if(kind==1)
		{
			height = 200;
		}
		else if(kind==2)
		{
			height = 350;
		}
		else if(kind==3)
		{
			height = 700;
		}
		id = -6-kind;
		rectagle =  CusRect(pos.x, pos.y, sprite->widthOfSprite, height);
	
}
