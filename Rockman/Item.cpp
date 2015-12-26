#include "Item.h"
#include "ResourceManager.h"
#include "Rockman.h"

CItem::CItem(D3DXVECTOR3 _pos)
{
	m_Type = ITEM;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES)
		,D3DXVECTOR2(40, 500), 2, 1
		,D3DXVECTOR2(10, 485)
		,D3DXVECTOR2(0,0), D3DXVECTOR2(0, 0));
	m_pos = _pos;
	m_posInit = _pos;

	m_accel = D3DXVECTOR2(0,-20.0f);
	m_velloc = D3DXVECTOR2(5, 10.0f);
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());

	//Item
	m_IsActive = false;
}

CItem::CItem()
{

}


CItem::~CItem(void)
{
;
}

void CItem::UpdateCollison(CEntity* _other,float _time)
{
	switch (_other->GetType())
	{
	case ROCKMAN:
		m_IsActive = false;
		m_IsShowed = false;
		//(dynamic_cast<CRockman*>(_other))->SetInjured(this);
		break;
	case BLOCK:
	
	default:
		break;
	}

	float timeEntry = m_collision->SweptAABB(this,_other,_time);
	m_directCollision = m_collision->GetDirectCollision();
	if (timeEntry < 1.0f)
	{
		ExecuteCollision(_other,m_directCollision,timeEntry);
	}
}

void CItem::SetVelloc(D3DXVECTOR2 _velloc)
{
	m_velloc = _velloc;
}

void CItem::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity*> _listObjectInViewport)
{
	if (m_IsActive) {

		m_Sprite->NextAt(_time, 0, 1);
		CEntity::Update(_time,_camera,_input,_listObjectInViewport);
	} else {
		m_pos = m_posInit;
	}

	if(m_Rect.left < _camera->m_viewPort.left || m_Rect.right > _camera->m_viewPort.right 
		|| m_Rect.top > _camera->m_viewPort.top || m_Rect.bottom < _camera->m_viewPort.bottom)
	{
		m_IsActive = false;
	}
}

void CItem::SetActive(bool _isActive)
{
	m_IsActive = _isActive;
}

void CItem::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	if (m_IsActive) {
		CEntity::Render(_spriteHandle, _camera);
	}
}

void CItem::ExecuteCollision(CEntity* _other, DirectCollision m_directCollision, float timeEntry)
{
	//ListObjectColision
	switch (_other->GetType())
	{
	case BLOCK:

	default:
		break;
	}
}
