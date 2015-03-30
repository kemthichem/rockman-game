#include "PipeVer.h"
CPipeVer::CPipeVer(void)
{

}
CPipeVer::CPipeVer( D3DXVECTOR3 _pos,int kind)
{
	pos = D3DXVECTOR3(_pos.x, _pos.y,0);
	sprite = new CSprite(CRescource::GetInstance()->GetSprite(IMAGE_PIPE),200,100,2,2);//horizontal
	SetKind(kind);
}
CPipeVer::~CPipeVer(void)
{
	delete sprite;
}
void CPipeVer::Render()
{
	int num = height/50;
	for(int i = 0; i<num; i++)
	{
		if(i==0) sprite->IndexOf(0);
		else if(i==num-1) sprite->IndexOf(3);
		else if(i<num/2)sprite->IndexOf(2);
		else sprite->IndexOf(1);
		sprite->Render((int)pos.x,(int)(pos.y+i*50),0, 0.6);
	}
}
void CPipeVer::SetKind(int kind)
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
	else if(kind==4)
	{
		height = 1000;
	}
	id = -2-kind;
	rectagle =  CusRect(pos.x, pos.y, sprite->widthOfSprite, height);
}
bool CPipeVer::IsCreep( CMario* mario,CQuadTreeNode *root )
{
	if(mario->rectagle.left>this->rectagle.left+15&&mario->rectagle.right<this->rectagle.right-15)
	{	
	//	checked = true;
		CusRect nextRect = CusRect((LONG)this->pos.x,(LONG) this->rectagle.bottom+1, (LONG)mario->rectagle.width, (LONG)mario->rectagle.height);
		list<CStaticObject*> listNextOb = root->ListObjectInRect(nextRect,true);
		if(listNextOb.size()==0)
			return true;
	}
	return false;
}
