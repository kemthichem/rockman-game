#include "MushLife.h"
CMushLife::CMushLife(void)
{
}
CMushLife::CMushLife( D3DXVECTOR3 _pos,int _kind)
{
	id =12;	
	kind = _kind;
	pos = D3DXVECTOR3(_pos.x, _pos.y,0);
	sprite = new CSprite(CRescource::GetInstance()->GetSprite(IMAGE_ITEM),350,150,7,3);
	sprite->IndexOf(6);
	rectagle =  CusRect(pos.x, pos.y, sprite->widthOfSprite, sprite->heightOfSprite);
	//
	state = 0;
	firstTop = pos.y-rectagle.height-2;
	vx = 4;
	if(kind==1)
		id = 25;
	else if(kind ==2)
		id = 26;
}
CMushLife::~CMushLife(void)
{
	delete sprite;
}
void CMushLife::Render()
{
	sprite->Render((int)pos.x, (int)pos.y,vx,0.5);
}
void CMushLife::SetState(int _state)
{
	if(state==0)
		marioGame->listObjectUpdated.push_back(new CBlock(pos,5));
	state = _state;
	if(state==1)
	{
		sprite->IndexOf(1);
	}	
}
void CMushLife::SetLife( bool _life )
{
	this->life = _life;
}
void CMushLife::_Update(CQuadTreeNode* root,DWORD deltaTime)
{

	if(state ==1)
	{
		checked = true;
  		vx = vy = 0;
		pos.y-=2;
		if(pos.y<firstTop)
		{
			state = 2;
			vx =-4;
			id = 12;
		}
	}
	else
		if(state==0)
		{
			vx = vy = 0;
			if(kind ==1)
				Update1();
			else if(kind==2)
				Update2();
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
void CMushLife::CheckCollision(CQuadTreeNode* root)
{
	checked = true;
	CusRect overRect = this->rectagle.OverRect(CusRect(rectagle, vx, vy));//xác định overRect
	list<CStaticObject*> listCollision = root->ListObjectInRect(overRect,true);
	for(CStaticObject* ob:listCollision)
	{
		if(ob->id<-30){ continue; }
		int collision = ob->rectagle.InterSect(this->rectagle,vx,vy);//check collision
		if(collision!=0)
		{
			if(collision==1)//collision horizontal
			{
				if (ob->rectagle.InterSect(this->rectagle,vx,0)!=0)//collision horizontal if vy=0
				{
					if(ob->id <0||ob->id>20)
					{ SetPosX(ob);vx *= -1;}
					
				}
			}
			else//collision vertical
			{
				if(ob->id <0||ob->id>20)
				{ SetPosY(ob);}
				if(this->rectagle.top>=ob->rectagle.bottom)//collision top
				{
					;
				}
				else
				{
					if(this->rectagle.bottom<=ob->rectagle.top)//collision bottom
					{
						;
					}
				}
			}
		}
	}
}
void CMushLife::Update1()
{
	sprite->NextOf(14,19);
}
void CMushLife::Update2()
{
	sprite->IndexOf(7);
}
