#include "Coin.h"
CCoin::CCoin(void)
{
}
CCoin::CCoin( D3DXVECTOR3 _pos,int _kind)
{
	id =11;	
	kind = _kind;
	pos = D3DXVECTOR3(_pos.x, _pos.y,0);
	sprite = new CSprite(marioGame->spriteItems,350,250,7,5);
	sprite->IndexOf(6);
	rectagle =  CusRect(pos.x, pos.y, sprite->widthOfSprite, sprite->heightOfSprite);
	firstTop = rectagle.top-10;
	//
	state = 0;
	if(kind==1)
		id = 21;
	else if(kind ==2)
		id = 22;

}

CCoin::CCoin( D3DXVECTOR3 _pos,bool life )
{
	id =13;	
	this->life = life;
	pos = D3DXVECTOR3(_pos.x, _pos.y,0);
	sprite = new CSprite(marioGame->spriteItems,350,250,7,5);
	rectagle =  CusRect(pos.x, pos.y, sprite->widthOfSprite, sprite->heightOfSprite);
	firstTop = rectagle.top-10;
	vy = vx = 0;
	vy -= 50;
	sprite->IndexOf(9);
	//this->life = false;
	
}

CCoin::~CCoin(void)
{
	delete sprite;
}
void CCoin::Render()
{
	sprite->Render(pos.x, pos.y,vx,0.5);
}
void CCoin::SetState(int _state)
{
	if(state==0)
		marioGame->listObjectUpdated.push_back(new CBlock(pos,3));
	state = _state;
	if(state==1)
	{
		vy -= 50;
		sprite->IndexOf(9);
		this->life = false;
		marioGame->listAnimation.push_back(this);
	}	
	//id = 11;
}
void CCoin::SetLife( bool _life )
{
	this->life = _life;
}
void CCoin::_Update(CQuadTreeNode* root,DWORD deltaTime)
{

	if(!life)
	{
		pos.y+=vy;		
		if(pos.y>firstTop)
		{
			visible = false;
			return;
		}		
	}
	else
		if(life)
		{
			vx = vy = 0;
			if(kind ==0)
				Update1();
			else if(kind==1)
				Update2();
			else if(kind==2)
				sprite->IndexOf(7);
		}
		rectagle.UpdateRect(pos.x, pos.y);
		//sprite->IndexOf(0);
		//------
		if(checked&&life)
			marioGame->listObjectUpdated.push_back(this);

}
void CCoin::Update1()
{
	sprite->NextOf(21,30);
}
void CCoin::Update2()
{
	sprite->NextOf(14,19);
}