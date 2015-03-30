#include "Rockman.h"

CRockman::CRockman(void)
{
	//acc = ACCLE;
	//	gravity = GRAVITY;
	state = 0;
	sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), 300, 100, 6, 1);
	rectagle = sprite->rect;
}
CRockman::CRockman( D3DXVECTOR3 _pos)
{
	id = 0;
	pos = _pos;
	vx = 0;
	vy = 0.0f;
	maxSpeedvx = 15;
	powerJumb = 50;
	lastvx = 1;
	state = 0;
	//spriteCovert = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_RockmanCONVERT),235,90,5,1);
	//spriteCovert->IndexOf(0);
	sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), 960, 320, 12, 4);
	rectagle =  CusRect(pos.x, pos.y,sprite->widthOfSprite, sprite->heightOfSprite);
	//--Gun
	isShooted = false;
	numberBullet = 2;
	//-----
	isBounce = false;
	isSmall = true;
	isSitting = false;
	//------
	timeSuper = 15000;//15s
}
CRockman::~CRockman(void)
{
	delete sprite;
	delete[] bullet;
}
void CRockman::Bounce()
{
	vy+=-40;
	state = 2;
}
void CRockman::Jump()
{
	if(vy == 0)
		vy+=-(powerJumb+abs(vx));
	state = 2;
}
void CRockman::Stop(int time)
{
	isSitting = false;
	vx = 0;
	/*if(vx!=0)
	lastvx = vx;
	if(vx>0)
	{
	vx+= -ACCLE*5;
	if(vx<=0)
	{
	vx=0;
	state = 0;
	}

	}
	else
	{
	if(vx<0)
	vx+= ACCLE*5;
	if(vx>=0)
	{
	vx=0;
	state = 0;
	}
	}*/
	if(vx==0)
		if(state!=6&&state!=5)
			state = 0;
}
void CRockman::TurnRight(int time)
{
	if(state!=2||vy==0)
		state = 1;
	vx = 10;
	//if(vx<0)
	//{
	//	vx += 20*(ACCLE);
	//	state = 3;
	//}
	//else
	//	vx += (ACCLE)*time;
	lastvx = vx;
}
void CRockman::TurnLeft(int time)
{
	if(state!=2||vy==0)
		state =1;
	vx = -10;
	//if(vx>0)
	//{
	//	vx += 20*(-ACCLE);
	//	state = 3;
	//}
	//else
	//	vx += (-ACCLE)*time;
	if(vx!=0)
		lastvx = vx;
}
void CRockman::Sitting(int time)
{
	if(state!=2)
	{
		state = 4;
		isSitting = true;
	}
	vx = 0;
}
void CRockman::NoShoot()
{
	state = 0;
}
void CRockman::Shoot()
{
	state = 6;
	isShooted = true;
}
//-----
void CRockman::Render()
{
		sprite->Render((int)pos.x, (int)pos.y, lastvx, 0.61);
}

//----
void CRockman::_Update( CQuadTreeNode* root,DWORD deltaTime )
{
#pragma region constrain coor

	if(vx>=maxSpeedvx)
		vx = maxSpeedvx;
	else
	{
		if(vx<-maxSpeedvx)
			vx = -maxSpeedvx;
	}
	if(pos.x<=10)
	{
		vx = 0;
		pos.x = 11;	
	}
	if(pos.y+vy<0)
		vy = 0;
	if(isShooted)
	{
		isShooted = false;
	}
#pragma endregion
#pragma region animation
	if(!this->life)
	{	
		vx = 0;
		state = 5;
		pos.x += vx;
		pos.y +=vy;
		if(pos.y>600)//rockmanGame->rectScreen.bottom)
		{
			visible = false;
			return;
		}
	}
	else
		//-----------------------------------------------------------------
#pragma endregion 
	{
		pos.x += vx;
		pos.y +=vy;
		if(isBounce)
		{
			Bounce();
			isBounce = false;
		}
		rectagle.UpdateRect(pos.x, pos. y);
	}

#pragma region Update sprite
	int n = 0;
	if(state==0)//--stand
		sprite->NextOf(12,14);
	else
		if(state == 1)//--go
			sprite->NextOf(24,27);
		else
			if(state==2)//--jump
				sprite->NextOf(36,37);
			else
				if(state == 3)//brake
					sprite->IndexOf(0);
				else
					if(state == 4)//sitting
						sprite->IndexOf(5);
					else
						if(state ==5)//--die
							sprite->IndexOf(6);
						else
							if(state==6)//shoot
								sprite->IndexOf(1);
#pragma endregion 
}

///---------------
