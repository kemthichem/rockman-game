#include <iostream>

#include"AABBCollisionDetected.h"
#include "Entity.h"
using namespace std;

CAABBCollision::CAABBCollision()
{

}
CAABBCollision::~CAABBCollision()
{
}
bool CAABBCollision::CheckCollision(RECT _nodeRect,RECT _otherRect)
{
	if (_otherRect.right < _nodeRect.left)
		return false;
	else if (_otherRect.left > _nodeRect.right)
		return false;
	else if (_otherRect.top < _nodeRect.bottom)
		return false;
	else if (_otherRect.bottom > _nodeRect.top)
		return false;
	else
		return true;
}
float CAABBCollision::SweptAABB(CEntity* _ob1, CEntity* _ob2, float _time)
{
	D3DXVECTOR2 v1 = _ob1->GetVelocity() + _ob1->GetAccleration()*_time;
	D3DXVECTOR2 v2 = _ob2->GetVelocity()+ _ob2->GetAccleration()*_time;

	D3DXVECTOR2 s1 = v1 * _time + 1.0f/2 *_ob1->GetAccleration()*_time*_time;
	D3DXVECTOR2 s2 = v2 * _time + 1.0f/2 *_ob2->GetAccleration()*_time*_time;

	D3DXVECTOR2 sMove = (s1 - s2);


	// _time truyen vao la thoi gian thay doi 1 frame
	D3DXVECTOR2 tEntry;// = D3DXVECTOR2(0,0);// thoi gian de 1 va cham 2
	D3DXVECTOR2 tExit ;//= D3DXVECTOR2(1,1);//thoi gian de 1 thoat khoai 2
	D3DXVECTOR2 dEntry;// khoang cach de 1 va cham 2
	D3DXVECTOR2 dExit;//khoang cach  de 1 thoat khoai 2
	float entryTime, exitTime;

	//Xet theo phuong X
	if(sMove.x >0)//dt 1 dang di chuyen qua ben phai
	{
		dEntry.x = _ob2->GetRect().left - _ob1->GetRect().right;
		dExit.x = _ob2->GetRect().right - _ob1->GetRect().left;
	}
	else if(sMove.x < 0)// di chuyen qua trai
	{
		dEntry.x =_ob2->GetRect().right - _ob1->GetRect().left;
		dExit.x = _ob2->GetRect().left - _ob1->GetRect().right;
	}

	if(sMove.y >0)//dt 1 dang di chuyen len
	{	
		dEntry.y = _ob2->GetRect().bottom - _ob1->GetRect().top;
		dExit.y = _ob2->GetRect().top - _ob1->GetRect().bottom;
	}
	else if(sMove.y < 0)// di chuyen qua xuong
	{
		dEntry.y = _ob2->GetRect().top - _ob1->GetRect().bottom;
		dExit.y =  _ob2->GetRect().bottom - _ob1->GetRect().top;
	}

	if(sMove.x == 0){
		tEntry.x = -std::numeric_limits<float>::infinity();
		tExit.x = std::numeric_limits<float>::infinity();
	}
	else
	{
		tEntry.x = dEntry.x / sMove.x;
		tExit.x = dExit.x /sMove.x;
	}
	if(sMove.y == 0){
		tEntry.y = -std::numeric_limits<float>::infinity();
		tExit.y = std::numeric_limits<float>::infinity();
	}
	else
	{
		tEntry.y = dEntry.y / sMove.y;
		tExit.y = dExit.y /sMove.y;
	}
	entryTime = max(tEntry.x,tEntry.y);
	exitTime = min(tExit.x,tExit.y);
	//if there are no collision
	if (entryTime > exitTime || tEntry.x < 0.0f && tEntry.y < 0.0f  || tEntry.x > 1.0f||tEntry.y > 1.0f )
	{		
		m_directCollision = NONE;
		return 1.0f;

	}
	//there are collision
	else 
	{
		if (tEntry.x >= tEntry.y) 
		{
			if (sMove.x < 0.0f) 
			{
				m_directCollision = LEFT;
			}
			else 
			{
				m_directCollision = RIGHT;
			}        
		}
		else 
		{
			if (sMove.y < 0.0f) 
			{
				m_directCollision = BOTTOM;
			} 
			else 
			{
				m_directCollision =TOP;
			}
		}

		return entryTime;
	}
}

float CAABBCollision::intersectX(CEntity* a,CEntity *b,float _time)
{
	//a->SetRect();
	//b->SetRect();
	if (a->GetRect().left >= b->GetRect().left && a->GetRect().left <= b->GetRect().right && a->GetRect().right >= b->GetRect().right)
	{
		return b->GetRect().right - a->GetRect().left;
	}
	else if (a->GetRect().left >= b->GetRect().left && a->GetRect().left <= b->GetRect().right && a->GetRect().right <= b->GetRect().right)
	{
		return a->GetRect().right - a->GetRect().left;
	}
	else if (a->GetRect().left <= b->GetRect().left && a->GetRect().right >= b->GetRect().left && a->GetRect().right <= b->GetRect().right)
	{
		return a->GetRect().right - b->GetRect().left;
	}
	else if (a->GetRect().left <= b->GetRect().left && a->GetRect().right >= b->GetRect().right)
	{
		return b->GetRect().right - b->GetRect().left;
	}
}


bool CAABBCollision::SortObject(CEntity * a, CEntity*b)
{

	if (a->m_TimeCollision!= b->m_TimeCollision)
	{
		return a->m_TimeCollision < b->m_TimeCollision;

	}
	else
	{
		return a->GetIntersect() > b->GetIntersect();
	}


}

bool CAABBCollision::IsCollision(CEntity* _ob1, CEntity* _ob2, float _time)
{
	D3DXVECTOR2 v1 = _ob1->GetVelocity() + _ob1->GetAccleration()*_time;
	D3DXVECTOR2 v2 = _ob2->GetVelocity()+ _ob2->GetAccleration()*_time;

	D3DXVECTOR2 s1 = v1 * _time + 1.0f/2 *_ob1->GetAccleration()*_time*_time;
	D3DXVECTOR2 s2 = v2 * _time + 1.0f/2 *_ob2->GetAccleration()*_time*_time;

	D3DXVECTOR2 sMove = (s1 - s2);

	RECT bound;//hcn bao quanh 2 fram lien tiep
	if(sMove.x > 0)
	{
		bound.left = _ob1->GetRect().left;
		bound.right = _ob1->GetRect().right + sMove.x;
	}
	else
	{
		bound.right = _ob1->GetRect().right;
		bound.left = _ob1->GetRect().left + sMove.x;
	}

	if(sMove.y > 0)
	{
		bound.bottom = _ob1->GetRect().bottom;
		bound.top =_ob1->GetRect().top + sMove.y;
	}
	else
	{
		bound.top = _ob1->GetRect().top;
		bound.bottom = _ob1->GetRect().bottom + sMove.y;
	}

	return CheckCollision(bound, _ob2->GetRect());
}