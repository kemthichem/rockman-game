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
bool CAABBCollision::CheckCollision(RECT _nodeRect,RECT _ortherRect)
{
	if (_ortherRect.right < _nodeRect.left)
		return false;
	else if (_ortherRect.left > _nodeRect.right)
		return false;
	else if (_ortherRect.top < _nodeRect.bottom)
		return false;
	else if (_ortherRect.bottom > _nodeRect.top)
		return false;
	else
		return true;
}
float CAABBCollision::CheckAABBCollision(CEntity* _Ob1,CEntity* _Ob2,float _time)
{
	D3DXVECTOR2 v1 = _Ob1->GetVelocity() + _Ob1->GetAccleration()*_time;
	D3DXVECTOR2 v2 = _Ob2->GetVelocity();// + _Ob2->GetAccleration()*_time;
	/*---------------------------------------------------------*/
	//tinh so pixels di duoc trong 1 frame
	D3DXVECTOR2 vMove = (v1 - v2) * _time;
	//Loai bo truong hop hien nhien  khong va cham
	RECT bound;//hcn bao quanh 2 fram lien tiep
	if(vMove.x > 0)
	{
		bound.left = _Ob1->GetRect().left;
		bound.right = _Ob1->GetRect().right + vMove.x;
	}
	else
	{
		bound.right = _Ob1->GetRect().right;
		bound.left = _Ob1->GetRect().left + vMove.x;
	}

	if(vMove.y > 0)
	{
		bound.bottom = _Ob1->GetRect().bottom;
		bound.top =_Ob1->GetRect().top + vMove.y;
	}
	else
	{
		bound.top = _Ob1->GetRect().top;
		bound.bottom = _Ob1->GetRect().bottom + vMove.y;
	}
	//hinh chu nhat co va cham moi su dung Swept aabb
	if (CheckCollision(bound,_Ob2->GetRect()))
	{
		// _time truyen vao la thoi gian thay doi 1 frame
		D3DXVECTOR2 tEntry;// = D3DXVECTOR2(0,0);// thoi gian de 1 va cham 2
		D3DXVECTOR2 tExit ;//= D3DXVECTOR2(1,1);//thoi gian de 1 thoat khoai 2
		D3DXVECTOR2 dEntry;// khoang cach de 1 va cham 2
		D3DXVECTOR2 dExit;//khoang cach  de 1 thoat khoai 2
		float entryTime,exitTime;
		//Xet theo phuong X
		if(vMove.x >0)//dt 1 dang di chuyen qua ben phai
		{
			dEntry.x = _Ob2->GetRect().left - _Ob1->GetRect().right;
			dExit.x = _Ob2->GetRect().right - _Ob1->GetRect().left;
		}
		else if(vMove.x < 0)// di chuyen qua trai
		{
			dEntry.x =_Ob2->GetRect().right - _Ob1->GetRect().left;
			dExit.x = _Ob2->GetRect().left - _Ob1->GetRect().right;
		}
		//Xet theo phuong Y
		if(vMove.y >0)//dt 1 dang di chuyen len
		{	
			dEntry.y = _Ob2->GetRect().bottom - _Ob1->GetRect().top;
			dExit.y = _Ob2->GetRect().top - _Ob1->GetRect().bottom;
		}
		else if(vMove.y < 0)// di chuyen qua xuong
		{
			dEntry.y = _Ob2->GetRect().top - _Ob1->GetRect().bottom;
			dExit.y =  _Ob2->GetRect().bottom - _Ob1->GetRect().top;
		}
		//Tinh thoi gian va cham && di qua
		if(vMove.x == 0){
			tEntry.x = -std::numeric_limits<float>::infinity();
			tExit.x = std::numeric_limits<float>::infinity();
		}
		else
		{
			tEntry.x = dEntry.x / vMove.x;
			tExit.x = dExit.x /vMove.x;
		}
		if(vMove.y == 0){
			tEntry.y = -std::numeric_limits<float>::infinity();
			tExit.y = std::numeric_limits<float>::infinity();
		}
		else
		{
			tEntry.y = dEntry.y / vMove.y;
			tExit.y = dExit.y /vMove.y;
		}
		entryTime = max(tEntry.x,tEntry.y);
		exitTime = min(tExit.x,tExit.y);
		//if there are no collision
		if (entryTime > exitTime || tEntry.x < 0.0f && tEntry.y < 0.0f  || tEntry.x > 1.0f||tEntry.y > 1.0f )
		{			
			return 2.0f;
		}
		//there are collision
		else 
		{
			if (tEntry.x >= tEntry.y) 
			{
				if (vMove.x < 0.0f) 
				{
					//MessageBox(NULL,"LEFT","THONG BAO",MB_OK);
					m_directCollision = LEFT;
				}
				else 
				{
					m_directCollision = RIGHT;
					//MessageBox(NULL,"RIGHT","THONG BAO",MB_OK);
				}        
			}
			else 
			{
				if (vMove.y < 0.0f) 
				{
					m_directCollision = BOTTOM;
					//MessageBox(NULL,"BOTTOM","THONG BAO",MB_OK);
				} 
				else 
				{
					m_directCollision =TOP;
					//MessageBox(NULL,"TOP","THONG BAO",MB_OK);
				}
			}

			return entryTime;
		}
	}
	else
	{
		return 2.0f;
	}

}
float CAABBCollision::intersectX(CEntity* a,CEntity *b,float _time)
{
	//a->SetBound();
	//b->SetBound();
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
	return true;
	/*
	if (a->m_TimeCollision!= b->m_TimeCollision)
	{
	return a->m_TimeCollision < b->m_TimeCollision;

	}
	else
	{
	return a->m_intetsect > b->m_intetsect;
	}*/
}
RECT CAABBCollision::CLip(CEntity * a,CEntity * b)
{
	//a->SetBound();
	//b->SetBound();

	RECT Object ;
	RECT Node ;
	Object.left = a->GetRect().left;
	Object.right = a->GetRect().right;
	Object.top= a->GetRect().bottom;
	Object.bottom = a->GetRect().top;
	Node.left = b->GetRect().left;
	Node.right = b->GetRect().right;
	Node.top= b->GetRect().bottom;
	Node.bottom = b->GetRect().top;
	RECT rect ;
	rect.top = rect.bottom = rect.right = rect.left = 0;
	if (CheckCollision(Object, Node) == true)
	{

		if (Object.left <= Node.left && Object.right >= Node.left && Object.right <= Node.right)
		{
			rect.left = Node.left;
			rect.right = Object.right;

		}
		else if (Object.left >= Node.left && Object.left <= Node.right && Object.right >= Node.left && Object.right <= Node.right)
		{
			rect.left = Object.left;
			rect.right = Object.right;
		}
		else if (Object.left >= Node.left && Object.left <= Node.right && Object.right >= Node.right)
		{
			rect.left = Object.left;
			rect.right = Node.right;
		}
		else // (Object.left <= Node.left && Object.right >= Object.right)
		{
			rect.left = Node.left;
			rect.right = Node.right;
		}
		// xet theo truc y

		if (Object.bottom <= Node.bottom && Object.top >= Node.bottom && Object.top <= Node.top)
		{
			rect.bottom = Node.bottom;
			rect.top = Object.top;

		}
		else if (Object.bottom >= Node.bottom && Object.bottom <= Node.top && Object.top >= Node.bottom && Object.top <= Node.top)
		{
			rect.bottom = Object.bottom;
			rect.top = Object.top;
		}
		else if (Object.bottom >= Node.bottom && Object.bottom <= Node.top && Object.top >= Node.top)
		{
			rect.bottom = Object.bottom;
			rect.top = Node.top;
		}
		else 
		{
			rect.bottom = Node.bottom;
			rect.top = Node.top;
		}

		return rect;
	}
	return rect;//co huong =0
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

bool CAABBCollision::IsCollision(CEntity* _ob1, CEntity* _ob2, float _time)
{
	D3DXVECTOR2 v1 = _ob1->GetVelocity() + _ob1->GetAccleration()*_time;
	D3DXVECTOR2 v2 = _ob2->GetVelocity()+ _ob2->GetAccleration()*_time;

	D3DXVECTOR2 s1 = v1 * _time + 1.0f/2 *_ob1->GetAccleration()*_time*_time;
	D3DXVECTOR2 s2 = v2 * _time + 1.0f/2 *_ob2->GetAccleration()*_time*_time;

	D3DXVECTOR2 sMove = (s1 - s2);


	//Loai bo truong hop hien nhien  khong va cham
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


//