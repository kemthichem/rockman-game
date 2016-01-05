#include "BulletIceman.h"
#include "ResourceManager.h"
#include "ScrewBomber.h"
#include "Rockman.h"

CBulletIceman::CBulletIceman(D3DXVECTOR3 _pos)
{
	m_Type = BULLET;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MASTER)
		, D3DXVECTOR2(15,213), 1, 1
		, D3DXVECTOR2(0,200));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,-8);
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_Sprite->IndexOf(0);
	m_IsActive = false;
}


CBulletIceman::~CBulletIceman(void)
{
}

void CBulletIceman::UpdateCollison(CEntity* _other,float _time)
{
	if (m_IsActive) {
		switch (_other->GetType())
		{
		case ROCKMAN:
		 	(dynamic_cast<CRockman*>(_other))->SetInjured(this, -15);
			m_IsActive = false;
			break;
		default:
			break;
		}
	}
}


void CBulletIceman::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity*> _listObjectInViewport)
{
	if (m_IsActive) {
		CEntity::Update(_time,_camera,_input,_listObjectInViewport);	

		if(m_Rect.left < _camera->m_viewPort.left || m_Rect.right > _camera->m_viewPort.right 
			|| m_Rect.top > _camera->m_viewPort.top || m_Rect.bottom < _camera->m_viewPort.bottom)
		{
			m_IsActive = false;
		}

	} 
}

void CBulletIceman::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	if (m_IsActive) {
		CEntity::Render(_spriteHandle, _camera);
	}
}

void CBulletIceman::SetPos(D3DXVECTOR3 _pos)
{
	m_pos = _pos;
	UpdateRect();
}
