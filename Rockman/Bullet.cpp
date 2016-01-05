#include "Bullet.h"
#include "ResourceManager.h"
#include "Rockman.h"

CBullet::CBullet(D3DXVECTOR3 _pos)
{
	m_Id = -10;
	m_Type = BULLET;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(167, 142), 1, 1, D3DXVECTOR2(160, 136));
	m_pos = _pos;
	m_posInit = _pos;

	m_velloc = D3DXVECTOR2(0,0);
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());

	//bullet
	m_IsActive = false;
}

CBullet::CBullet()
{

}


CBullet::~CBullet(void)
{
}

void CBullet::UpdateCollison(CEntity* _other,float _time)
{
	switch (_other->GetType())
	{
	case ROCKMAN:
		this->m_IsActive = false;
		m_pos = m_posInit;
		(dynamic_cast<CRockman*>(_other))->SetInjured(this);
		break;
	default:
		break;
	}
}

void CBullet::SetVelloc(D3DXVECTOR2 _velloc)
{
	m_velloc = _velloc;
}

void CBullet::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity*> _listObjectInViewport)
{
	if (m_IsActive) {
		CEntity::Update(_time,_camera,_input,_listObjectInViewport);
		/*} else {
		m_pos = m_posInit;
		}*/

		if(m_Rect.left < _camera->m_viewPort.left || m_Rect.right > _camera->m_viewPort.right 
			|| m_Rect.top > _camera->m_viewPort.top || m_Rect.bottom < _camera->m_viewPort.bottom)
		{
			m_IsActive = false;
			m_pos = m_posInit;
		}
	}
}

void CBullet::SetActive(bool _isActive)
{
	m_IsActive = _isActive;
}

void CBullet::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	if (m_IsActive) {
		CEntity::Render(_spriteHandle, _camera);
	}
}

bool CBullet::IsObtainCollision(CEntity* _other)
{
	if (_other->GetType() == ROCKMAN) {
		return true;
	}
	return false;
}

void CBullet::SetPos(D3DXVECTOR2 _pos)
{
	m_pos.x = _pos.x;
	m_pos.y = _pos.y;
}

void CBullet::SetAccel(D3DXVECTOR2 _accel)
{
	m_accel = _accel;
}
