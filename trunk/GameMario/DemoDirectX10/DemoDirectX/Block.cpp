#include "Block.h"

CBlock::CBlock(void)
{
}

CBlock::CBlock( D3DXVECTOR3 _pos,int kind)
{
	pos = _pos;
	spriteHandle = marioGame->GetSpriteHandle();
	sprite = new CSprite(marioGame->spriteBlocks,400,250,8,5);
	rectagle =  CusRect(pos.x, pos.y, sprite->widthOfSprite, sprite->heightOfSprite);
	SetKind(kind);
}

CBlock::~CBlock(void)
{
	delete sprite;
}

void CBlock::Render()
{
	sprite->Render(pos.x, pos.y,0);
}

void CBlock::Update( CQuadTreeNode* root,DWORD t )
{
}

void CBlock::SetKind(int kind)
{
	if(kind==1)
	{
		sprite->IndexOf(6);
	}
	else if(kind==2)
	{
		sprite->IndexOf(7);
	}
	else if(kind==3)
	{
		sprite->IndexOf(15);
	}
	else if(kind==4)
	{
		sprite->IndexOf(23);
	}
	else if(kind==5)
	{
		sprite->IndexOf(31);
	}
	id = -10-kind;
	//-11->-15
}
