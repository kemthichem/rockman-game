#include "PipeHor.h"
CPipeHor::CPipeHor(void)
{
}
CPipeHor::CPipeHor( D3DXVECTOR3 _pos,int kind)
{
	pos = D3DXVECTOR3(_pos.x, _pos.y,0);
	sprite = new CSprite(marioGame->spritePipe,200,200,4,2);

	SetKind(kind);
}
CPipeHor::~CPipeHor(void)
{
	delete sprite;
}
void CPipeHor::Render()
{
	int num = width/50;
	for(int i = 0; i<num; i++)
	{
		if(i==0) sprite->IndexOf(4);
		else if(i==num-1) sprite->IndexOf(7);
		else sprite->IndexOf(5);
		sprite->Render(pos.x+i*50,pos.y, 0,0.601);
	}
}
void CPipeHor::SetKind(int kind)
{
	if(kind==1)
	{
		id = -1;
		width = 200;
	}
	else if(kind==2)
	{
		id = -2;
		width = 2000;
	}
	rectagle =  CusRect(pos.x, pos.y, width, sprite->heightOfSprite);
}

bool CPipeHor::IsCreep( CMario* mario )
{
	if(mario->rectagle.bottom<this->rectagle.bottom&&mario->rectagle.bottom>this->rectagle.bottom-20)
		return true;
	return false;
}
