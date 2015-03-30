#include "Flag.h"

CFlag::CFlag(void)
{
}

CFlag::CFlag( D3DXVECTOR3 _pos)
{
	id = -25;
	pos = _pos;
	spriteHandle = marioGame->GetSpriteHandle();
	spritePillars = new CSprite(CRescource::GetInstance()->GetSprite(IMAGE_BLOCKS),200,350,10,1);
	spriteFlag = new CSprite(CRescource::GetInstance()->GetSprite(IMAGE_BLOCKS),250,100,5,2);
	rectagle =  CusRect(pos.x, pos.y, spritePillars->widthOfSprite, spritePillars->heightOfSprite);
	spritePillars->IndexOf(9);
	spriteFlag->IndexOf(9);
	state = 1;
	posYFlag = (LONG)pos.y;
}

CFlag::~CFlag(void)
{
	delete spritePillars;
	delete spriteFlag;
}

void CFlag::Render()
{
	spritePillars->Render((int)pos.x, (int)pos.y,0);
	spriteFlag->Render((int)pos.x+16, (int)posYFlag,0);
}

void CFlag::Update( CQuadTreeNode* root,DWORD t )
{
	if(state==2&&posYFlag<(rectagle.bottom-45))
		posYFlag+=10;

}

void CFlag::SetState()
{
	state = 2;
	id = 50;
}
