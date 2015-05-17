#include "Entity.h"
#include <windows.h>
#include <stdio.h>


CEntity::CEntity(void)
{
	m_isTurnLeft = false;
	m_veloc = D3DXVECTOR2(0,0);
	m_accel = D3DXVECTOR2(0,0);

	m_collision = NULL;
}

void CEntity::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity*> _listObjectInViewPort) {
	//set is turn left
	if (m_veloc.x < 0) m_isTurnLeft = true;
	else if (m_veloc.x > 0) m_isTurnLeft = false;

	
	//set position
	UpdatePosition(_time);



	vector<CEntity*> listObjectCollision;
	for (int i = 0; i < _listObjectInViewPort.size(); i++)
	{
		if(_listObjectInViewPort[i]->GetType() != OBJECTTYPE)
		{
			if (m_collision->IsCollision(this,_listObjectInViewPort[i],_time)) {
				listObjectCollision.push_back(_listObjectInViewPort[i]);
			}
		}
	}

	for (int i = 0; i < listObjectCollision.size(); i++)
	{
		UpdateCollison(listObjectCollision[i],_time);
	}

	UpdateRect();
	if (m_Type==ROCKMANTYPE)
	{
		_camera->Update(D3DXVECTOR2(m_pos.x, m_pos.y));
	}

}

void CEntity::Render(LPD3DXSPRITE _spriteHandler, CCamera* _camera){

	D3DXMATRIX Scale;
	D3DXMatrixIdentity(&Scale);
	D3DXMatrixTransformation2D(&Scale, &D3DXVECTOR2(m_pos.x, m_pos.y), 0.0f, &D3DXVECTOR2(1.f, -1.f),NULL, 0.f, NULL);
	D3DXMatrixMultiply(&Scale,&Scale, &_camera->GetMatrixCamera());

	//flip sprite when move left
	D3DXMATRIX matrixFlip;
	D3DXVECTOR2 trans(2*(m_pos.x - _camera->GetPosCamera().x ) + m_sprite->widthOfSprite, 0);
	if (m_isTurnLeft) {
		D3DXMatrixTransformation2D(&matrixFlip
			,NULL//center of sprite
			,0.0f
			,new D3DXVECTOR2(-1,1)//flip Ox
			,NULL
			,0
			,&trans//distance transform
			);

		D3DXMatrixMultiply(&Scale,&Scale,&matrixFlip);
	}

	_spriteHandler->SetTransform(&Scale);

	m_sprite->Render(_spriteHandler, D3DXVECTOR3(m_pos.x,m_pos.y,0), 1);
}

void CEntity::UpdatePosition(float _time)
{
	m_veloc += m_accel * _time;
	m_pos.x += m_veloc.x * _time + 1.0f/2 *m_accel.x*_time*_time;
	m_pos.y += m_veloc.y * _time + 1.0f/2 *m_accel.y*_time*_time;
}

CEntity::~CEntity(void)
{
	delete m_sprite;

	if (m_collision != NULL)
		delete m_collision;
}

D3DXVECTOR2 CEntity::GetVelocity()
{
	return m_veloc;
}

RECT CEntity::GetRect()
{
	return m_Rect;
}

D3DXVECTOR2 CEntity::GetAccleration()
{
	return m_accel;
}

void CEntity::UpdateCollison(CEntity* _orther , float _time)
{

}

void CEntity::UpdateRect()
{
	m_Rect.left = m_pos.x;
	m_Rect.top = m_pos.y;
	m_Rect.right = m_Rect.left + m_sprite->widthOfSprite;
	m_Rect.bottom = m_Rect.top - m_sprite->heightOfSprite;
}
