#include "Item.h"
#include "ResourceManager.h"
#include "Rockman.h"

CItem::CItem(D3DXVECTOR3 _pos)
{
	m_Type = ITEM;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES)
		,D3DXVECTOR2(428,901), 1, 2
		,D3DXVECTOR2(390,741)
		,D3DXVECTOR2(0,0), D3DXVECTOR2(0,48));
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
	case LAND:
	case LAND1:
	case LANDWHITE:
	case LANDICEBERG:
		break;
		m_velloc = m_accel = D3DXVECTOR2(0,0);
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
	case LAND:
	case LAND1:
	case LANDWHITE:
	case LANDICEBERG:
		{
			if( m_directCollision == BOTTOM)
			{
				m_pos.y = _other->GetRect().top + m_Size.y + 1;
				m_velloc.y = 0;
			}

			if( m_directCollision == LEFT)
			{
				m_velloc.x = 0;
				m_accel.x = 0;
				m_pos.x = _other->GetRect().right ;
			}

			if( m_directCollision == RIGHT)
			{
				m_velloc.x = 0;
				m_accel.x = 0;
				m_pos.x = _other->GetRect().left - m_Size.x;
			}

			if (m_directCollision == TOP)
			{
				m_pos.y = _other->GetRect().bottom;
				m_velloc.y = 0;
			}
			m_velloc.x = 0;
		}
		break;
	default:
		break;
	}
}
