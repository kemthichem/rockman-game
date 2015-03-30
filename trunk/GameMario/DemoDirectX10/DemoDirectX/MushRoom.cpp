#include "Mushroom.h"
CMush::CMush(void)
{
}
CMush::CMush( D3DXVECTOR3 _pos ,int _kind):CMushLife(_pos,_kind)
{
	id =13;
	vx = 0;
	if(kind==1)
		id = 27;
	else if(kind ==2)
		id = 28;
}
CMush::~CMush(void)
{
}	
void CMush::SetType(int type)
{
	if(state==0)
		marioGame->listObjectUpdated.push_back(new CBlock(pos,5));
	state = 1;
	this->type = type;
	if(type==1)
		sprite->IndexOf(0);
	if(type==2)
		sprite->IndexOf(2);
}
void CMush::_Update(CQuadTreeNode* root,DWORD deltaTime)
{	
	if(state ==1)
	{
		checked = true;
  		vx = vy = 0;
		pos.y-=2;
		if(pos.y<firstTop)
		{
			state = 2;
			if(type==1)
			vx =-4;
			id = 13;
		}
	}
	else
		if(state==0)
		{
			vx = vy = 0;
			if(kind==1)
				Update1();
			else if(kind ==2)
				Update2();
		//	CheckCollision(root);
		}
		if(state ==2)
		{		
			CheckCollision(root);
			pos.x += vx;
			pos.y += vy;
			
		}
		rectagle.UpdateRect(pos.x, pos.y);
		//sprite->IndexOf(0);
		//------
		if(checked&&life)
			marioGame->listObjectUpdated.push_back(this);

}