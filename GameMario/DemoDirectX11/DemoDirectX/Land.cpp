#include "Land.h"


CLand::CLand(void)
{
}

CLand::CLand( D3DXVECTOR3 _pos,int _kind )
{
	pos = _pos;
	kind = _kind;
	spriteHandle = marioGame->GetSpriteHandle();
	sprite = new CSprite(CRescource::GetInstance()->GetSprite(IMAGE_BLOCKS),150,200,3,2);
	SetKind();
	rectagle =  CusRect(pos.x, pos.y, 150, sprite->heightOfSprite);
	
}

CLand::~CLand(void)
{
	delete sprite;
}

void CLand::Render()
{
	sprite->IndexOf(startIndex+1);
	sprite->Render((int)pos.x+sprite->widthOfSprite, (int)pos.y,0,0);
	sprite->IndexOf(startIndex+2);
	sprite->Render((int)pos.x+2*50, (int)pos.y,0,0.1);
	sprite->IndexOf(startIndex);
	sprite->Render((int)pos.x, (int)pos.y,0,0.1);
}
void CLand::Update( CQuadTreeNode* root,DWORD t )
{
}
void CLand::SetKind()
{
	if(kind==1)
	{
		id = -20;
		startIndex = 3;
	}
	else if(kind==2)
	{
		id = -21;
		startIndex = 0;
	}
}
