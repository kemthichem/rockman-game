
#include "Star.h"
CStar::CStar(void)
{
}
CStar::CStar( D3DXVECTOR3 _pos):CMushLife(_pos)
{
	id =29;
}
CStar::~CStar(void)
{
	
}
void CStar::SetState(int _state)
{
	if(state==0)
		marioGame->listObjectUpdated.push_back(new CBlock(pos,5));
	state = _state;
	id = 29;
}
void CStar::Bounce()
{
	vy = 0;
	pos.y -= 30;
	if(vy>=0)
	{	
		vy  -= 30;
	}
}
void CStar::_Update(CQuadTreeNode* root,DWORD deltaTime)
{
	if(state ==1)
	{
		checked = true;
  		vx = vy = 0;
		pos.y-=2;
		if(pos.y<firstTop)
		{
			state = 2;
			vx =-7;
		}
	}
	else
		if(state==0)
		{
			vx = vy = 0;
			Update1();
		//	CheckCollision(root);
		}
		if(state ==2)
		{		
			CheckCollision(root);
			pos.x += vx;
			pos.y += vy;			
		}
		rectagle.UpdateRect(pos.x, pos.y);
		if(state==1)
			sprite->NextOf(3,5);
		//sprite->IndexOf(0);
		//------
		if(checked&&life)
			marioGame->listObjectUpdated.push_back(this);

}
void CStar::CheckCollision(CQuadTreeNode* root)
{
	checked = true;
	CusRect overRect = this->rectagle.OverRect(CusRect(rectagle, vx, vy));//xác định overRect
	list<CStaticObject*> listCollision = root->ListObjectInRect(overRect,true);
	for(CStaticObject* ob:listCollision)
	{
		if(ob->id==29||ob->id<-30){ continue; }
		int collision = ob->rectagle.InterSect(this->rectagle,vx,vy);//check collision
		if(collision!=0)
		{
			if(collision==1)//collision horizontal
			{
				if (ob->rectagle.InterSect(this->rectagle,vx,0)!=0)//collision horizontal if vy=0
				{
					if(ob->id <0||ob->id>20){ SetPosX(ob);vx *= -1;}
					
				}
			}
			else//collision vertical
			{
				if(ob->id <0||ob->id>20){ SetPosY(ob);Bounce();break;}
			}
		}
	}
}
