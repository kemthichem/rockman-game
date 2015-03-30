#include "Brick.h"


CBrick::CBrick(void)
{
}

CBrick::CBrick( D3DXVECTOR3 _pos )
{
	isPush = false;
	ex = false;
	id = -10;
	pos = _pos;
	spriteHandle = marioGame->GetSpriteHandle();
	sprite = new CSprite(CRescource::GetInstance()->GetSprite(IMAGE_ITEM),350,150,7,3);
	//1
	sprite->IndexOf(7);
	rectagle =  CusRect(pos.x, pos.y, sprite->widthOfSprite, sprite->heightOfSprite);
	maxTop = pos.y-6;
	frapBrick[0] = new CFrag(D3DXVECTOR3( rectagle.left,rectagle.top,0), -10, -60);
	frapBrick[1] = new CFrag(D3DXVECTOR3(rectagle.left,rectagle.top+20, 0),-10, -40);
	frapBrick[2] = new CFrag(D3DXVECTOR3(rectagle.left+20,rectagle.top, 0),10 ,-60);
	frapBrick[3] = new CFrag(D3DXVECTOR3( rectagle.left+20,rectagle.top+20,0),20, -40);

}

CBrick::~CBrick(void)
{
	delete sprite;
}

void CBrick::Render()
{
	sprite->Render((int)pos.x, (int)pos.y,0);
}

void CBrick::Update( CQuadTreeNode* root,DWORD t )
{
	if(isPush)
	{
	
		if(pos.y>maxTop)
			pos.y-=2;
		else
			if(pos.y == maxTop)
				pos.y -= 2;
			else
			{
				pos.y = maxTop+6;
				isPush = false;
			}
			CheckCollision(root);
			rectagle.UpdateRect(pos.x, pos.y);
			marioGame->listObjectUpdated.push_back(this);
	}
	else
	if(ex)
	{
		if(pos.y>maxTop+4)
		{			
			CheckCollision(root);
			pos.y-=2;
			rectagle.UpdateRect(pos.x,pos.y);
			marioGame->listObjectUpdated.push_back(this);
		}
		else{
				life = false;
				for (int i = 0; i < 4; i++)
				{
					marioGame->listAnimation.push_back(frapBrick[i]);
				}
			}
		
	}

}

void CBrick::CheckCollision( CQuadTreeNode* root )
{
	checked = true;
	CusRect overRect = this->rectagle.OverRect(CusRect(rectagle, 0, -2));//xác định overRect
	list<CStaticObject*> listCollision = root->ListObjectInRect(overRect);
	for(CStaticObject* ob:listCollision)
	{
		if(ob->id==-1){ continue; }
		int collision = ob->rectagle.InterSect(this->rectagle,0,-2);//check collision
		if(collision!=0)
		{

			if(collision==1)//collision horizontal
			{
				;
			}
			else//collision vertical
			{

				//if(vy < 0)//collision top
				if(this->rectagle.top>=ob->rectagle.bottom)//collision top
				{
					if(ob->id == 1){((CTurtle*)ob)->SetLife(false);}
					if(ob->id == 2){((CEnemy*)ob)->SetLife(false);}
				}
				else
				{
					//if(vy > 0)//collision bottom
					if(this->rectagle.bottom<=ob->rectagle.top)//collision bottom
					{
							;					
					}
				}

			}
		}
	}

}

void CBrick::SetEx( bool _ex )
{
	SoundManager::GetInst()->PlayEffSound(SOUND_E_BROKEN,false);
	this->ex = _ex;
}

void CBrick::SetPush( bool _isPush )
{
	SoundManager::GetInst()->PlayEffSound(SOUND_E_BRICK_UP,false);
	this->isPush = _isPush;
}
