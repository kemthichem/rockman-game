#include "Bullet.h"
CBullet::CBullet(void)
{
	id = 10;
	pos = D3DXVECTOR3(0,0,0);
}
CBullet::CBullet( D3DXVECTOR3 _pos)
{

}
CBullet::~CBullet(void)
{
	delete sprite;
}
void CBullet::Render()
{
	sprite->Render((int)pos.x, (int)pos.y,vx,0.6);
}
void CBullet::Setlife( bool _life )
{
	this->life = _life;	
}
void CBullet::_Update(CQuadTreeNode* root,DWORD deltaTime)
{
	CusRect rectScreen = marioGame->rectScreen;
	if(!this->life)
		return;
	CheckCollision(root);
	if(state == 1)
	{
		pos.x += vx;
		pos.y += vy;
		rectagle.UpdateRect((LONG)pos.x, (LONG)pos.y);
		if(pos.x>= rectScreen.right||pos.x<rectScreen.left||pos.y>rectScreen.bottom)
		{
			this->life = false;
		}
		sprite->NextOf(4,7);
	}

	else
		if(state ==2)
		{
			if(GetTickCount()- timeStartEx> 400)
			{
				this->life = false;
			}
			sprite->NextOf(0,5);
		}
		//------
		if(checked&&life)
			marioGame->listObjectUpdated.push_back(this);	

}
void CBullet::CheckCollision(CQuadTreeNode* root)
{
	checked = true;
	CusRect overRect = this->rectagle.OverRect(CusRect(rectagle, vx, vy));//xác định overRect
	list<CStaticObject*> listCollision = root->ListObjectInRect(overRect);
	for(CStaticObject* ob:listCollision)
	{
		if(ob->id==10||ob->id<-30){ continue; }
		int collision = ob->rectagle.InterSect(this->rectagle,vx,vy);//check collision
		if(collision!=0)
		{
			if(ob->id == 1){((CTurtle*)ob)->SetLife(false);SetEx(true);break;}
			else if(ob->id == 2){((CEnemy*)ob)->SetLife(false);SetEx(true);break;}
			else if(ob->id == 3||ob->id==4){((CEato*)ob)->SetLifeEx();SetEx(true);break;}
			if(collision==1)//collision horizontal
			{
				SetPosX(ob);vx = 0;SetEx(true);break;
				if (ob->rectagle.InterSect(this->rectagle,vx,0)!=0)
				{
					
					;//if(ob->id <0){ SetPosX(ob);SetEx(true);}
				}
			}
			else//collision vertical
			{
				if(state==1)
				if(ob->id <0||ob->id>20)
				{ SetPosY(ob);Bounce();break;}
			}
		}
	}
}
void CBullet::Bounce()
{
	vy = 0;
	pos.y -= 10;
	if(vy>=0)
	{	
		vy  -= 15;
	}
}
void CBullet::SetEx( bool _ex )
{
	SoundManager::GetInst()->PlayEffSound(SOUND_E_BULLETEX,false);
	timeStartEx = GetTickCount();
	state = 2;
	sprite = new CSprite(CRescource::GetInstance()->GetSprite(IMAGE_BULLET),192,32,6,1);
	//0->5
	vx = vy = 0;
	rectagle =  CusRect(pos.x, pos.y, sprite->widthOfSprite, sprite->heightOfSprite);
}
void CBullet::Set( D3DXVECTOR3 _pos, int dir )
{
	SoundManager::GetInst()->PlayEffSound(SOUND_E_SHOT,false);
	pos = _pos;
	vx = (float)dir*15;//12;	
	vy = -20;
	sprite = new CSprite(CRescource::GetInstance()->GetSprite(IMAGE_BULLET),100,64,4,2);
	//4->7
	rectagle =  CusRect(pos.x, pos.y, sprite->widthOfSprite, 10);
	state = 1;
	life = true;
	marioGame->listObjectUpdated.push_back(this);
}