#include "Coin1.h"
CCoin1::CCoin1(void)
{
}
CCoin1::CCoin1( D3DXVECTOR3 _pos,int _numCoin):CCoin(_pos)
{
	numCoin = _numCoin;
	id =23;
	sprite->IndexOf(7);
	isPush = false;
	maxTop = rectagle.top - 6;
	if(numCoin==10)
		id = 24;
}
CCoin1::~CCoin1(void)
{

}
void CCoin1::_Update(CQuadTreeNode* root,DWORD deltaTime)
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
	}
	//else
	vy = 0;
	sprite->IndexOf(7);
	rectagle.UpdateRect(pos.x, pos.y);
	if(checked&&life)
		marioGame->listObjectUpdated.push_back(this);
}
void CCoin1::SetNumCoin()
{
	if(numCoin>0)
	{
		isPush = true;
		marioGame->listAnimation.push_back(new CCoin(pos,false));
		numCoin--;
	}
	if(numCoin<=0)
	{
		life = false;
		marioGame->listObjectUpdated.push_back(new CBlock(pos,3));
	}

}
void CCoin1::CheckCollision( CQuadTreeNode* root )
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

				if(this->rectagle.top>=ob->rectagle.bottom)//collision top
				{
					if(ob->id == 1){((CTurtle*)ob)->SetLife(false);}
					if(ob->id == 2){((CEnemy*)ob)->SetLife(false);}
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