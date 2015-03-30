#include "StaticObject.h"


CStaticObject::CStaticObject(void)
{
	checked = false;
	visible = true;
}




CStaticObject::~CStaticObject(void)
{
}

//------------
CMotionObject ::CMotionObject()
{
	life = true;
	vx = vy = 0;
	lastx = 0;
	lasty = 0;
}

CMotionObject::~CMotionObject()
{

}

void CMotionObject::Gravity(int deltaTime, int _floor)
{
	if(pos.y >= 1440)
		int k = 0;
	int floor = _floor- rectagle.height;
	if(pos.y<floor)
	{
		vy+=deltaTime * GRAVITY;
	}
	if(pos.y +vy > floor)
	{   
		pos.y = (float)floor;
		vy = 0;
	}
}

void CMotionObject::Update( CQuadTreeNode* root,DWORD t )
{
	Gravity(t, 0);//rockmanGame->quadTree->GetHeight());
	_Update(root,t);
}

void CMotionObject::SetPosX( CStaticObject* obIntersect )
{
	float _xRight =  obIntersect->rectagle.right + 1;
	float _xLeft =  obIntersect->rectagle.left - rectagle.width-1;

	if(vx<0)//&& lastx<_xRight)
	{
		pos.x = _xRight;
		lastx = pos.x;
	}
	else
		if(vx>0)// &&lastx > _xLeft){
		{
			pos.x = _xLeft;
			lastx = pos.x;
		}	
    		rectagle.UpdateRect(pos.x, pos.y);
}

void CMotionObject::SetPosY( CStaticObject* obIntersect )
{

	float _yTop =  obIntersect->rectagle.top - rectagle.height-0.1;
	float _yBottom =  obIntersect->rectagle.bottom+1;// - rectagle.height;
	if(this->rectagle.top>=obIntersect->rectagle.bottom)
		pos.y = _yBottom;
	else pos.y = _yTop;
	vy = 0;
	rectagle.UpdateRect(pos.x, pos.y);
}


