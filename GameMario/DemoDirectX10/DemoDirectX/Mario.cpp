#include "Mario.h"

bool compSortObjectTop (CStaticObject* first, CStaticObject* second){
	//bool isPri = (first->id>second->id);
	bool isPri = first->rectagle.top<second->rectagle.top;
	return isPri;
}
bool compSortObjectBottom (CStaticObject* first, CStaticObject* second){
	//bool isPri = (first->id>second->id);
	bool isPri = first->rectagle.bottom>second->rectagle.bottom;
	return isPri;
}
bool compSortObjectRight (CStaticObject* first, CStaticObject* second){
	//bool isPri = (first->id>second->id);
	bool isPri = first->rectagle.right>second->rectagle.right;
	return isPri;
}
bool compSortObjectLeft (CStaticObject* first, CStaticObject* second){
	//bool isPri = (first->id>second->id);
	bool isPri = first->rectagle.bottom>second->rectagle.bottom;
	if(!isPri)first->rectagle.left<second->rectagle.left;
	return isPri;
}
CMario::CMario(void)
{
	//acc = ACCLE;
	//	gravity = GRAVITY;
	state = 0;
	sprite = new CSprite(marioGame->spriteMarioSmall, 300, 100, 6, 1);
	rectagle = sprite->rect;
}
CMario::CMario( D3DXVECTOR3 _pos)
{
	id = 0;
	pos = _pos;
	vx = 0;
	vy = 0.0f;
	maxSpeedvx = 15;
	powerJumb = 50;
	lastvx = 1;
	state = 0;
	spriteCovert = new CSprite(marioGame->spriteMarioConvert,235,90,5,1);
	spriteCovert->IndexOf(0);
	sprite = new CSprite(marioGame->spriteMarioSmall, 329, 60, 7, 1);
	rectagle =  CusRect(pos.x, pos.y,sprite->widthOfSprite, sprite->heightOfSprite);
	//--Gun
	isShooted = false;
	isGun = false;
	numberBullet = 2;
	for (int i = 0; i < 3; i++){bullet[i] = new CBullet();}
	//-----
	isBounce = false;
	isSmall = true;
	isConvert = false;
	isConvertGun = false;
	isConvertLarge = false;
	isSuper = false;
	isSitting = false;
	isCreep = false;
	isWin = false;
	//------
	timeSuper = 15000;//15s
}
CMario::~CMario(void)
{
	delete sprite;
	delete *bullet;
}
void CMario::Bounce()
{
	vy+=-40;
	state = 2;
}
void CMario::Jump()
{
	if(vy == 0&&!isCreep)
		vy+=-(powerJumb+abs(vx));
	state = 2;
}
void CMario::Stop(int time)
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
void CMario::TurnRight(int time)
{
	if(isCreep) return;
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
void CMario::TurnLeft(int time)
{
	if(isCreep) return;
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
void CMario::Sitting(int time)
{
	if(state!=2)
	{
		state = 4;
		isSitting = true;
	}
	vx = 0;
}
void CMario::NoShoot()
{
	state = 0;
}
void CMario::Shoot()
{
	if(!isGun) return;
	state = 6;
	isShooted = true;
}
//-----
void CMario::Render()
{
	if(!isConvert)
	{
		sprite->Render(pos.x, pos.y, lastvx,0.61);		
	}
	else
	{
		int _y = pos.y;
		if(isSmall) _y-=30;
		//if(isConvert)
		spriteCovert->Render(pos.x, _y, lastvx,0.61);
	}
}
bool CMario::IsTurn()
{
	if(vx!=0) return true;
	return false;
}
//----
void CMario::_Update( CQuadTreeNode* root,DWORD deltaTime )
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
		CreateBullet();
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
		if(pos.y>marioGame->rectScreen.bottom)
		{
			visible = false;
			return;
		}
	}
	else
		//-----------------------------------------------------------------
#pragma endregion 
	{
		CheckCollision(root);
		if(isCreep)
		{
			Creeping();
		}
		else
			if(isWin)
			{
				GoWin();
			}
		else
		{
			pos.x += vx;
			pos.y +=vy;
			if(isBounce)
			{
				Bounce();
				isBounce = false;
			}
		}
		rectagle.UpdateRect(pos.x, pos. y);
		if(vx==0&&vy==0&&!isCreep)
		{
			checked = false;
		}
	}


#pragma region Update sprite
	int n = 0;
	if(isSuper) n = 2;
	if(state==0)//--stand
		sprite->NextAt(0,n);
	else
		if(state ==1)//--go
			sprite->NextAt(0,n+1);
		else
			if(state==2)//--jump
				sprite->IndexOf(4);
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
	if(isConvert) Converting();
	if(isSuper) Flashing();
	//---add list updated
	if(checked&&life)
		marioGame->listObjectUpdated.push_back(this);
}
bool CMario::CheckCollision(CQuadTreeNode *root)
{
	checked = true;
	CusRect overRect = this->rectagle.OverRect(CusRect(rectagle, vx, vy));//xác định overRect
	list<CStaticObject*> listCollision = root->ListObjectInRect(overRect,true);
	if(vy<0)
	{
		listCollision.sort(compSortObjectBottom);
	}	
	else if(vy>0)
		listCollision.sort(compSortObjectTop);
	for(CStaticObject* ob:listCollision)
	{
		if(!ob->life||ob->id==0||ob->id<=-30){ continue; }
		int collision = ob->rectagle.InterSect(this->rectagle,vx,vy);//check collision
		if(collision!=0)
		{
			if(ob->id ==3) this->SetLife(false);
			else
			#pragma region Get items
			//--get item.
			if(ob->id==12){if(((CMushLife*)ob)->state==2){ob->life = false;/*--increase life*/;}}
			else if(ob->id==13){if(((CMush*)ob)->state==2){ob->life = false;int type = ((CMush*)ob)->type;if(type == 1) this->SetLarge(false);else if(type == 2) this->SetGun();}}
			else if(ob->id==29){if(((CStar*)ob)->state==2){ob->life = false;SetSuper();}}
			else if(ob->id==11){ob->life = false;/*increase scores*/;}
			else if(ob->id==-25&&!isWin){((CFlag*)ob)->SetState();pos.x = ob->rectagle.left+16;isWin = true;distance = ob->rectagle.bottom;}
			else if(ob->id==-26){((CHouse*)ob)->SetState(5);this->life = false;}
			//------va ch?m v?i enemy khi là super
			if(isSuper)
			{
				if(ob->id <10&&ob->id>0)
				{((CMotionObject*)ob)->SetLife(false);}
			}
#pragma endregion 
			//-----
			if(collision==1)//collision horizontal
			{
				if(ob->rectagle.InterSect(this->rectagle,vx,0)!=0)
				{
					if(0>ob->id&&ob->id>-3&&((CPipeHor*)ob)->IsCreep(this)){ SetCreep(ob);}
					else
						if(ob->id <0||ob->id>20){ SetPosX(ob);vx = 0;}//--
				}
				else
					if(ob->id <0||ob->id >20){ SetPosY(ob);break;}
					//--
					else if(0<ob->id&&ob->id<10){this->SetLife(false);}

			}
			else//collision vertical
			{
				if(ob->id <-10/*&&ob->id!=-7&&ob->id!=-6*/){ SetPosY(ob);break;}//--va cham theo phương dọc vs block
				if(this->rectagle.top>=ob->rectagle.bottom)//collision top
				{

					if(0<ob->id&&ob->id<10){this->SetLife(false);}//--mario chết
					//---va chạm block
					else if(ob->id == -10){ SetPosY(ob);if(isSmall)((CBrick*)ob)->isPush=(true);else ((CBrick*)ob)->SetEx(true) ;vy = 0;break;}//--brick
					
					//--va chạm với item
					else if(ob->id==12||ob->id==25||ob->id==26){SetPosY(ob);((CMushLife*)ob)->SetState(1);}
					else if(ob->id==13||ob->id==28||ob->id==27){SetPosY(ob);int type = 1; if(!isSmall) type = 2;((CMush*)ob)->SetType(type);}
					else if(ob->id==29){SetPosY(ob);((CStar*)ob)->SetState(1);}
					else if(ob->id==21||ob->id==22){SetPosY(ob);((CCoin*)ob)->SetState(1);}
					else if(ob->id==23||ob->id==24){SetPosY(ob);((CCoin1*)ob)->SetNumCoin();}

					//-------
					else if(-10<ob->id&&ob->id<0/* ==-6||ob->id==-7*/){ SetPosY(ob);break;}
				}
				else
					if(this->rectagle.bottom<=ob->rectagle.top)//collision bottom
					{
			 			 if(-10<ob->id&&ob->id<-2/*ob->id==-7*/){
							 if(isSitting&&((CPipeVer*)ob)->IsCreep(this,root)) SetCreep(ob,1);else SetPosY(ob);break;}
						//	else
						if(ob->id <0||ob->id>20){ SetPosY(ob);break;}
					#pragma region collision enemies
						if(ob->id == 1)
						{((CTurtle*)ob)->SetState(2);
						SetPosY(ob);
						isBounce = true;
						break;
						}
						else
							if(ob->id ==2)
							{
								{((CEnemy*)ob)->SetLife0(false);}
								SetPosY(ob);
								isBounce = true;
								break;
							}
#pragma endregion 
					}
					else//trường hợp nằm bên trong
					{
						if(ob->id<0&&ob->id>-3&&!isCreep){SetCreep(ob);}
						else if(-10<ob->id&&ob->id<-2/*ob->id == -7*/&&!isCreep){SetCreep(ob);}
					}
				

			}
		}
	}
	return false;
}

///---------------

void CMario::SetLarge( bool _isSmall )
{
	if(isSmall==_isSmall)
		return;
	timeStartConvert = GetTickCount();
	isConvert = true;
	isConvertLarge = true;
	isSmall = _isSmall;
	if(isSmall)
	{
		numberBullet = 2;
		powerJumb = 50;
		isGun = false;
		sprite = new CSprite(marioGame->spriteMarioSmall, 329, 60, 7, 1);
	}
	else
	{
		powerJumb = 55;
		sprite = new CSprite(marioGame->spriteMarioLarge, 329, 90,7, 1);
	}
	rectagle =  CusRect(pos.x, pos.y-30,sprite->widthOfSprite, sprite->heightOfSprite);//

}
void CMario::SetLife( bool _life )
{
	if(!this->life||isConvert||isSuper)
		return;
	if(!isSmall)
	{
		this->SetLarge(true);
	}
	else SetDie();
}
void CMario::SetGun()
{
	if(isSmall) SetLarge(false);
	else if(!isGun) {isGun = true;SetConvertGun();}
	else if(numberBullet<3)
		numberBullet = 3;
}
void CMario::SetSuper()
{
	timeStartSuper = GetTickCount();
	isSuper = true;

}
void CMario::SetDie()
{
	this->life = false;
	state = 5;
	//sprite->IndexOf(6);
	vx =0;
	vy = 0;
	vy -= 70;
	checked = true;
	marioGame->listAnimation.push_back(this);
}
//-----
void CMario::CreateBullet()
{
	int dir = 1;
	CusRect rectScreen= marioGame->rectScreen;
	if(lastvx<0)
		dir = -1;
	for(int i = 0; i<numberBullet;i++)
		if(!bullet[i]->life||bullet[i]->rectagle.top==0||bullet[i]->rectagle.left>= rectScreen.right||bullet[i]->rectagle.right<rectScreen.left||bullet[i]->rectagle.top>rectScreen.bottom)
		{
			bullet[i]->Set(rectagle.PosMidle(),dir);
			break;
		}
}
void CMario::Converting()
{
	if(GetTickCount()-timeStartConvert>1000)
	{
		isConvert = isConvertLarge=isConvertGun=false;
		return;
	}
	if(isConvertLarge)
		spriteCovert->NextAt(0,2);
	else if(isConvertGun)
		spriteCovert->NextAt(2,4);
}
void CMario::Flashing()
{
	if(GetTickCount()-timeStartSuper>timeSuper)
	{
		isSuper = false;
		return;
	}
}
void CMario::SetConvertGun()
{
	//if(isGun) return;
	timeStartConvert = GetTickCount();
	isConvert = true;
	isConvertGun = true;
	sprite = new CSprite(marioGame->spriteMarioGun, 282, 90, 6, 1);
}
void CMario::SetCreep(CStaticObject* ob,float _vyCreep)
{
	if(ob->id>-3)//pipe horizontal
	{
		//if(rectagle.left<ob->rectagle.left||rectagle.right>ob->rectagle.right)
		//{
			vxCreep = lastvx;
			vyCreep = 0;
			isCreep = true;
			distanceCreep = 0;
			if(lastvx>0) distance =(ob->rectagle.right- this->rectagle.right);
			else distance = (this->rectagle.left-ob->rectagle.left);
			timesCreep =1 ;
		//}
	}
	else
		if(ob->id <-2)
		{
			pos.x = ob->rectagle.left+25;
			vxCreep = 0;
			vyCreep = _vyCreep;
			isCreep = true;
			distanceCreep = 0;
			if(vyCreep>0) distance =(ob->rectagle.bottom- this->rectagle.bottom-1);
			else distance = (this->rectagle.top-ob->rectagle.top+1);
			timesCreep =1 ;
		}
		if(distance<0) isCreep = false;
}
void CMario::Creeping()
{
	checked = true;
	vy = 0;
#pragma region creep horizontal
	if(vyCreep==0){
	pos.x += (vxCreep/abs(vxCreep))*4;	
	pos.y -=3;
	state = 1;
	distanceCreep += 4;
	if(distanceCreep>(20+rectagle.width)||distanceCreep>distance+rectagle.width)
	{	
		timesCreep++;
		if(timesCreep==3)
		{
			isCreep=false;
			return;
		}
		if(vxCreep!=0)
		pos.x += ((vxCreep/abs(vxCreep))*(distance-40-rectagle.width));
		if(vyCreep!=0)
			pos.y += ((vyCreep/abs(vyCreep))*(distance-40-rectagle.height));
		distanceCreep = 0;
	}
	}
	else
#pragma endregion 
		if(vxCreep==0)
		{
			//pos.x += (vxCreep/abs(vxCreep))*4;	
			pos.y += (vyCreep/abs(vyCreep))*4;
			state = 0;
			distanceCreep += 4;
			if(distanceCreep>(50)||distanceCreep>distance+rectagle.height)
			{	
				timesCreep++;
				if(timesCreep==3)
				{
					isCreep=false;
					return;
				}
					pos.y += ((vyCreep/abs(vyCreep))*(distance-54 +rectagle.height));
				distanceCreep = 0;
			}
		}
}
void CMario::GoWin()
{
   	if(pos.y <(distance-rectagle.height-1))
	{
		state = 0;
		pos.y+=15;
	}
		
	else
	{
		state=1;
		pos.x+=6;
	}

}