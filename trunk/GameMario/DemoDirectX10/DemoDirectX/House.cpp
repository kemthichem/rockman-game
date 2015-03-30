#include "House.h"

CHouse::CHouse(void)
{
}

CHouse::CHouse( D3DXVECTOR3 _pos)
{
	id = -26;
	pos = _pos;
	spriteHandle = marioGame->GetSpriteHandle();
	spriteHouse = new CSprite(marioGame->spriteBlocks,800,400,2,1);
	spriteFire = new CSprite(marioGame->spriteBullet,192,32,6,1);
	rectagle =  CusRect(pos.x+117, pos.y, spriteHouse->widthOfSprite, spriteHouse->heightOfSprite);
	spriteHouse->IndexOf(1);
	state = 1;
	SetPosGun();
	posIndex = 0;
}

CHouse::~CHouse(void)
{
	delete spriteFire;
	delete spriteHouse;
}

void CHouse::Render()
{
	spriteHouse->Render(pos.x,pos.y,0,1);
	if(state==1) return;
	if(GetTickCount()-timeStartWin>2000)
	{
		if(posIndex<bonus)
		spriteFire->Render(posFire[posIndex].x, posFire[posIndex].y,0);
		else return;
		if(GetTickCount()-timePreFire >1000)
		{	
			timePreFire = GetTickCount();
			posIndex++;
		}	
	}
}

void CHouse::Update( CQuadTreeNode* root,DWORD t )
{
	spriteFire->NextOf(0,5);

}

void CHouse::SetState(int _bonus)
{
	timeStartWin = GetTickCount();
	timePreFire =timeStartWin+1000;
	state = 2;
	id = 50;
	bonus = _bonus;
}
void CHouse::SetPosGun()
{
	posFire[0] = D3DXVECTOR3(pos.x+28,pos.y+118,0);
	posFire[1] = D3DXVECTOR3(pos.x+268,pos.y+105,0);
	posFire[2] = D3DXVECTOR3(pos.x+55,pos.y+19,0);
	posFire[3] = D3DXVECTOR3(pos.x+251,pos.y+22,0);
	posFire[4] = D3DXVECTOR3(pos.x+150,pos.y-50,0);
}
