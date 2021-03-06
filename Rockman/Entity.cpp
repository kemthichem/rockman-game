#include "Entity.h"
#include <windows.h>
#include <stdio.h>

CEntity::CEntity(void)
{
	m_IsShowed = true;
	m_IsCheckCollision = true;
	m_isTurnLeft = false;
	m_lastVelloc = m_velloc = D3DXVECTOR2(0,0);
	m_accel = D3DXVECTOR2(0,0);
	m_Intersect = 0;
	m_Sprite = NULL;
	m_collision = new CAABBCollision();

	m_Size = D3DXVECTOR2(0,0);
	m_directCollision = NONE;
}

void CEntity::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity*> _listObjectInViewPort) {
	if ((int)m_Type < 0) return;
	//set is turn left
	if (m_velloc.x < 0) m_isTurnLeft = true;
	else if (m_velloc.x > 0) m_isTurnLeft = false;
	
	//set position
	UpdatePosition(_time);

	if (m_Type==ROCKMAN && m_isTurnLeft && m_velloc.x > 0) {
		int k  = 0;
	}

	vector<CEntity*> listObjectCollision;
	for (int i = 0; i < _listObjectInViewPort.size(); i++)
	{
		/*if(_listObjectInViewPort[i]->GetId() != this->GetId() 
			&& _listObjectInViewPort[i]->GetType() != this->GetType())*/
		if (IsObtainCollision(_listObjectInViewPort[i]) 
			&& _listObjectInViewPort[i]->IsCheckCollision())
		{
			if (m_collision->IsCollision(this, _listObjectInViewPort[i], _time)) {
				//_listObjectInViewPort[i]->m_Intersect = m_collision->intersectX(this,_listObjectInViewPort[i],_time);
				listObjectCollision.push_back(_listObjectInViewPort[i]);
			}
		}
	}

	////sort 
	if (m_velloc.x > 0)
		std::sort(listObjectCollision.begin(),listObjectCollision.end(),m_collision->compSortObjectLeft);
	else
		if (m_velloc.x < 0)
		std::sort(listObjectCollision.begin(),listObjectCollision.end(),m_collision->compSortObjectRight);

		else {
			std::sort(listObjectCollision.begin(),listObjectCollision.end(),m_collision->compSortObjectTop);
			std::sort(listObjectCollision.begin(),listObjectCollision.end(),m_collision->compSortObjectForType);
		}
	//std::sort(listObjectCollision.begin(),listObjectCollision.end(),m_collision->SortObject);

	for (int i = 0; i < listObjectCollision.size(); i++)
	{
		//Recheck collision after change velloc
		if (m_collision->IsCollision(this, listObjectCollision[i], _time)) {
			UpdateCollison(listObjectCollision[i],_time);
		}
	}

	UpdateRect();
	if (m_Type == ROCKMAN)
	{
		_camera->Update(D3DXVECTOR2(m_pos.x, m_pos.y), m_velloc);
	}

}

void CEntity::Render(LPD3DXSPRITE _spriteHandler, CCamera* _camera) {
	RenderEachSprite(_spriteHandler, _camera,m_Sprite, m_pos);
}

void CEntity::RenderEachSprite(LPD3DXSPRITE _spriteHandler, CCamera* _camera,CSprite * _sprite, D3DXVECTOR3 _posRender)
{
	_sprite->Render(_spriteHandler, _camera, _posRender, m_isTurnLeft);
}

void CEntity::UpdatePosition(float _time)
{
	m_lastVelloc = m_velloc;
	m_velloc += m_accel * _time;
	m_pos.x += m_velloc.x * _time + 1.0f/2 * m_accel.x *_time * _time;
	m_pos.y += m_velloc.y * _time + 1.0f/2 * m_accel.y *_time * _time;

	if ((m_accel.x < 0 && m_velloc.x > 0) || (m_accel.x > 0 && m_velloc.x < 0))  
		m_velloc.x = 0;
}

CEntity::~CEntity(void)
{
	if (m_Sprite)
		delete m_Sprite;

	if (m_collision != NULL)
		delete m_collision;
}

D3DXVECTOR2 CEntity::GetVelocity()
{
	return m_lastVelloc;
}

RECT CEntity::GetRect()
{
	return m_Rect;
}

D3DXVECTOR2 CEntity::GetAccleration()
{
	return m_accel;
}

void CEntity::UpdateCollison(CEntity* _other , float _time)
{

}

void CEntity::UpdateRect()
{
	m_Rect.left = (long)(m_pos.x + 0.5);
	m_Rect.top = (long)(m_pos.y+ 0.5);
	m_Rect.right = (long)(m_Rect.left + m_Size.x );
	m_Rect.bottom = (long)(m_Rect.top - m_Size.y );
}

bool CEntity::IsShowed()
{
	return m_IsShowed;
}

bool CEntity::IsCheckCollision()
{
	return m_IsCheckCollision;
}

void CEntity::SetInjured(CEntity* _other)
{

}

bool CEntity::IsObtainCollision(CEntity* _other)
{
	if (this->GetId() != _other->GetId())
		return true;

	return false;
}
