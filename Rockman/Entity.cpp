#include "Entity.h"
#include <windows.h>
#include <stdio.h>


CEntity::CEntity(void)
{
	m_IsShowed = true;
	m_IsCheckCollision = true;
	m_isTurnLeft = false;
	m_velloc = D3DXVECTOR2(0,0);
	m_accel = D3DXVECTOR2(0,0);

	m_collision = NULL;
	m_Size = D3DXVECTOR2(0,0);
	m_directCollision = NONE;
}

void CEntity::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity*> _listObjectInViewPort) {
	//set is turn left
	if (m_velloc.x < 0) m_isTurnLeft = true;
	else if (m_velloc.x > 0) m_isTurnLeft = false;
	
	//set position
	UpdatePosition(_time);

	if (this->GetType() == BULLET)
	{
		int k = 0;
	}
	vector<CEntity*> listObjectCollision;
	for (int i = 0; i < _listObjectInViewPort.size(); i++)
	{
		if(_listObjectInViewPort[i]->GetId() != this->GetId())
		{
			if (_listObjectInViewPort[i]->IsCheckCollision() && m_collision->IsCollision(this, _listObjectInViewPort[i], _time)) {
				listObjectCollision.push_back(_listObjectInViewPort[i]);
			}
		}
	}

	for (int i = 0; i < listObjectCollision.size(); i++)
	{
		UpdateCollison(listObjectCollision[i],_time);
	}

	UpdateRect();

	if (m_Type==ROCKMAN)
	{
		_camera->Update(D3DXVECTOR2(m_pos.x, m_pos.y));
	}

}

void CEntity::Render(LPD3DXSPRITE _spriteHandler, CCamera* _camera) {
	RenderEachSprite(_spriteHandler, _camera,m_Sprite, m_pos);
}

void CEntity::RenderEachSprite(LPD3DXSPRITE _spriteHandler, CCamera* _camera,CSprite * _sprite, D3DXVECTOR3 _posRender)
{
	D3DXMATRIX Scale;
	D3DXMatrixIdentity(&Scale);
	D3DXMatrixTransformation2D(&Scale, &D3DXVECTOR2(_posRender.x, _posRender.y), 0.0f, &D3DXVECTOR2(1.f, -1.f),NULL, 0.f, NULL);
	D3DXMatrixMultiply(&Scale,&Scale, &_camera->GetMatrixCamera());

	//flip sprite when move left
	D3DXMATRIX matrixFlip;
	D3DXVECTOR2 trans(2*(_posRender.x - _camera->GetPosCamera().x ) + _sprite->GetWidthRectSprite(), 0);
	if (m_isTurnLeft) {
		D3DXMatrixTransformation2D(&matrixFlip
			,NULL//center of sprite
			,0.0f
			,new D3DXVECTOR2(-1,1)//flip Ox
			,NULL
			,0
			,&trans//distance transform
			);

		D3DXMatrixMultiply(&Scale, &Scale, &matrixFlip);
	}

	_spriteHandler->SetTransform(&Scale);

	_sprite->Render(_spriteHandler, _posRender);
}

void CEntity::UpdatePosition(float _time)
{
	m_velloc += m_accel * _time;
	m_pos.x += m_velloc.x * _time + 1.0f/2 * m_accel.x *_time * _time;
	m_pos.y += m_velloc.y * _time + 1.0f/2 * m_accel.y *_time * _time;
}

CEntity::~CEntity(void)
{
	delete m_Sprite;

	if (m_collision != NULL)
		delete m_collision;
}

D3DXVECTOR2 CEntity::GetVelocity()
{
	return m_velloc;
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
	m_Rect.left = m_pos.x;
	m_Rect.top = m_pos.y;
	m_Rect.right = m_Rect.left + m_Size.x;
	m_Rect.bottom = m_Rect.top - m_Size.y;
}

bool CEntity::IsShowed()
{
	return m_IsShowed;
}

bool CEntity::IsCheckCollision()
{
	return m_IsCheckCollision;
}
