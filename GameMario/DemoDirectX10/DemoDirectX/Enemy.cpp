#include "Enemy.h"
CEnemy::CEnemy(void)
{
}
CEnemy::CEnemy( D3DXVECTOR3 _pos )
{
	id =2;
	pos = _pos;
	sprite = new CSprite(marioGame->spriteEnemy,550,41,11,1);
	rectagle =  CusRect(pos.x, pos.y, sprite->widthOfSprite, sprite->heightOfSprite);
	vx = 3;//4;//12;
}
CEnemy::~CEnemy(void)
{
	delete sprite;
}
void CEnemy::Render()
{
	sprite->Render(pos.x, pos.y,vx);
}
void CEnemy::SetLife( bool _life )
{
	if(!life)
		return;
	this->life = _life;
	if(!life)
	{
		sprite->IndexOf(1);
		vx *=1;
		vy = 0;
		vy -= 40;
		checked = true;
		marioGame->listAnimation.push_back(this);
		stateDie = 1;
	}
}
void CEnemy::SetLife0( bool _life )
{
	if(!life)
		return;
	this->life = _life;
	if(!life)
	{
		sprite->IndexOf(0);
		vx =vy = 0;
		//vy -= 20;*
		checked = true;
		marioGame->listAnimation.push_back(this);
		stateDie = 0;
		timeStartDie = GetTickCount();
	}
}
void CEnemy::_Update(CQuadTreeNode* root,DWORD deltaTime)
{
	if(!this->life)
		//return;
	{	
		if(stateDie==1)//chết lật ngữa
		{
			pos.x += vx;
			pos.y += vy;
			if(pos.y>marioGame->rectScreen.bottom)
			{
				visible = false;
				return;
			}
		}
		else
			if(stateDie == 0)//chết bị đè
			{
				if(GetTickCount()- timeStartDie> 400)
				{
					this->visible = false;
					return;
				}
			}
	}
	else
	{

		CheckCollision(root);
		sprite->NextOf(2,9);
		pos.x += vx;
		pos.y += vy;
		if(vx==0&&vy==0)
		{
			checked = false;
		}
		rectagle.UpdateRect(pos.x, pos. y);

		//sprite->IndexOf(10);
		//------
		if(checked&&life)
			marioGame->listObjectUpdated.push_back(this);	
	}

}
void CEnemy::CheckCollision(CQuadTreeNode* root)
{
	checked = true;
	CusRect overRect = this->rectagle.OverRect(CusRect(rectagle, vx, vy));//xác định overRect
	list<CStaticObject*> listCollision = root->ListObjectInRect(overRect,true);
	for(CStaticObject* ob:listCollision)
	{
		if(ob->id==2||ob->id<-30){ continue; }
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
				if(ob->id == 0){((CMario*)ob)->SetLife(false);}
			}
			else//collision vertical
			{
				if(ob->id <0||ob->id>20){ SetPosY(ob);}
				//if(vy < 0)//collision top
				if(this->rectagle.top>=ob->rectagle.bottom)//collision top
				{
					;
				}
				else
				{
					//if(vy > 0)//collision bottom
					if(this->rectagle.bottom<=ob->rectagle.top)//collision bottom
					{
						//if(ob->id == -1){ SetPosY(ob);}
						//else 
							if(ob->id == 0){((CMario*)ob)->SetLife(false);}
					}
				}
			}
		}
	}
}
