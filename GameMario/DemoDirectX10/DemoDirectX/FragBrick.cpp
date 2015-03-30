#include "FragBrick.h"
CFrag::CFrag(void)
{
}
CFrag::CFrag( D3DXVECTOR3 _pos, int _vx ,int _vy)
{
	id =-10;
	pos = _pos;
	spriteHandle = marioGame->GetSpriteHandle();
	sprite = new CSprite(marioGame->spriteItems,20,80,1,4);
	//3
	sprite->IndexOf(3);
	//rectagle =  CusRect(pos.x, pos.y, 16,15);
	vx = _vx;//12;
	state = 0;
	vy = _vy;
}
CFrag::~CFrag(void)
{
	delete sprite;
	spriteHandle->Release();
}
void CFrag::Render()
{
	sprite->Render(pos.x, pos.y,vx);
}

void CFrag::_Update(CQuadTreeNode* root,DWORD deltaTime)
{
	pos.x += vx;
	pos.y += vy;
	//rectagle.UpdateRect(pos.x,pos.y);
	if(pos.y>marioGame->rectScreen.bottom)
	{
		visible = false;
		return;
	}
	
}
