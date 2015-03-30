﻿#include "Eato.h"


CEato::CEato(void)
{
}

CEato::CEato( D3DXVECTOR3 _pos,int kind)
{
	pos = _pos;
	this->kind = kind;
	isEx = false;
	id = 3;
	spriteHandle = marioGame->GetSpriteHandle();
	if(kind==0)
	{
		sprite = new CSprite(CRescource::GetInstance()->GetSprite(IMAGE_EATO),150,50,3,1);
	}
	else if(kind == 1)
	{
		sprite = new CSprite(CRescource::GetInstance()->GetSprite(IMAGE_EATO1), 200,50,4,1);
		id = 4;
	}

	//kind = 1
	rectagle =  CusRect(pos.x, pos.y, sprite->widthOfSprite, sprite->heightOfSprite);
	maxTop = rectagle.top;
	timeStartGrow = GetTickCount();
	turnDown = false;
}

CEato::~CEato(void)
{
	delete sprite;
	spriteHandle->Release();
}

void CEato::Render()
{

	sprite->Render((int)pos.x, (int)pos.y,0,0.61);
}
void CEato::Update( CQuadTreeNode* root,DWORD t )
{
	if(!life)
	{
		sprite->NextOf(0,11);
		if(GetTickCount()-timeStartEx>400)
			this->visible = false;
		return;
	}
	if(kind==0)
		sprite->NextOf(0,2);
	else if(kind==1)
	{
		
		if(GetTickCount()-timeStartGrow>5000)
		{
			sprite->NextOf(0,3);
			checked = true;
			id = 4;
			if(!turnDown)
				pos.y -=2;
			else pos.y+=2;
			if(pos.y<maxTop-rectagle.height&&!turnDown)
			{
				turnDown = true;
			}
			if(pos.y>=maxTop&turnDown)
			{
				turnDown=false;
				id = -10;
				timeStartGrow = GetTickCount();
			}
			rectagle.UpdateRect(pos.x,pos.y);
		}
	
	}
	if(checked&&life)
	marioGame->listObjectUpdated.push_back(this);
}

void CEato::SetLifeEx()
{
	life = false;
	timeStartEx = GetTickCount();
	isEx = true;
	marioGame->score->SetScore(this,100);
	sprite = new CSprite(CRescource::GetInstance()->GetSprite(IMAGE_EATOEX), 120,100,3,4);
	pos.y+=10;
	marioGame->listAnimation.push_back(this);
}
