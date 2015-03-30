#include "Turtle.h"
CTurtle::CTurtle(void)
{
}
CTurtle::CTurtle( D3DXVECTOR3 _pos )
{
	id =1;
	pos = _pos;
	sprite = new CSprite(CRescource::GetInstance()->GetSprite(IMAGE_TURTLE),250,70,5,1);
	rectagle =  CusRect(pos.x, pos.y, sprite->widthOfSprite, sprite->heightOfSprite);
	vx = -4;//4;//15;
	state = 1;
}
CTurtle::~CTurtle(void)
{
	delete sprite;
}
void CTurtle::Render()
{
	sprite->Render((int)pos.x, (int)pos.y,vx);
}
void CTurtle::SetState( int _state )
{
	SoundManager::GetInst()->PlayEffSound(SOUND_E_TOUCH_TIRTLE,false);
	state = _state;
	if(_state==1)
	{
		marioGame->score->SetScore(this,100);
		vx = -5;
	}
	else
		if(abs(vx) == 15)
		{
			vx = 0;
			marioGame->score->SetScore(this,200);
		}
		else	
		{
			vx =15;
			marioGame->score->SetScore(this,100);
		}
}
void CTurtle::SetLife( bool _life )
{
	SoundManager::GetInst()->PlayEffSound(SOUND_E_TOUCH_TIRTLE,false);
	
	if(this->life)
	{
	state = 0;
	sprite->IndexOf(4);
	vx =0;
	vy = 0;
	vy -= 20;
	checked = true;
	marioGame->score->SetScore(this,100);
	this->life = _life;
	marioGame->listAnimation.push_back(this);
	}

}
void CTurtle::_Update(CQuadTreeNode* root,DWORD deltaTime)
{
	if(!this->life)
		//return;
	{	if(pos.y>marioGame->rectScreen.bottom)
	{
		visible = false;
		return;
	}
	}
	else
	CheckCollision(root);
	pos.x += vx;
	pos.y += vy;
	if(vx==0&&vy==0)
	{
		checked = false;
	}
	if(state ==1)
	{	
		rectagle.UpdateRect((int)pos.x, (int)pos. y);
		//sprite->IndexOf(10);
		sprite->NextOf(0,1);
	}
	else
	if(state ==2)
	{
		rectagle.UpdateRect((int)pos.x, (int)pos.y,50,30);
		sprite->NextOf(2,3);
		if(vx==0)
			sprite->IndexOf(2);
	}
//------
	if(checked&&life)
		marioGame->listObjectUpdated.push_back(this);	

}
void CTurtle::CheckCollision(CQuadTreeNode* root)
{
	checked = true;
	CusRect overRect = this->rectagle.OverRect(CusRect(rectagle, vx, vy));//xác định overRect
	list<CStaticObject*> listCollision = root->ListObjectInRect(overRect,true);
	for(CStaticObject* ob:listCollision)
	{
		if(ob->id==1||ob->id<-30){ continue; }
		int collision = ob->rectagle.InterSect(this->rectagle,vx,vy);//check collision
		if(collision!=0)
		{
			
			if(collision==1)//collision horizontal
			{
				if (ob->rectagle.InterSect(this->rectagle,vx,0)!=0)//collision horizontal if vy=0
				{
					if(ob->id <0||ob->id>20)
					{ SetPosX(ob);vx *= -1;continue;}
				}
				//else if(ob->id <0){ SetPosY(ob);}
				if(ob->id == MARIO)	{((CMario*)ob)->SetLife(false);}
				else if(state==2){
					if(ob->id>0&&ob->id<10)
						((CMotionObject*)ob)->SetLife(false);
				}
			}
			else//collision vertical
			{
				if(ob->id <0||ob->id>20){ SetPosY(ob);}
				//if(vy < 0)//collision top
				if(this->rectagle.top>=ob->rectagle.bottom)//collision TOP
				{
					;
				}
				else
				{
					//if(vy > 0)//collision bottom
					if(this->rectagle.bottom<=ob->rectagle.top)//collision BOTTOM
					{
					/*	if(ob->id == -1){ SetPosY(ob);}
						else */
							if(ob->id == 0){((CMario*)ob)->SetLife(false);}
					}
				}
			}
		}
	}
}

