#include "BulletBombomb.h"
#include "ResourceManager.h"
#include "Config.h"
#include "Rockman.h"

CBulletBombomb::CBulletBombomb(D3DXVECTOR3 _pos)
{
	m_Type = BULLET;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES),D3DXVECTOR2(207, 402), 1, 1, D3DXVECTOR2(200,396));
	m_spriteExplosive = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_EXPLOSIVE), D3DXVECTOR2(112, 40), 7, 1, D3DXVECTOR2(0,25));
	m_pos = _pos;

	m_accel = D3DXVECTOR2(0,0);
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());

	m_IsActive = false;

	m_timeExplosive = CConfig::ValueOf(KEY_EN_TIMEEXPLOSIVE);
}


CBulletBombomb::~CBulletBombomb(void)
{
	delete m_spriteExplosive;
}

void CBulletBombomb::UpdateCollison(CEntity* _other,float _time)
{
	if (m_IsActive) {
		bool isIntersect = false;
		switch (_other->GetType())
		{		
		case BLOCK:
			m_IsActive = false;
			break;
		case ROCKMAN:
			(dynamic_cast<CRockman*>(_other))->SetInjured(this, -15);
			//m_IsActive = false;
			break;
		default:
			break;
		}
		
	}
}

void CBulletBombomb::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity*> _listObjectInViewport)
{
	if (m_IsActive) {
		CEntity::Update(_time,_camera,_input,_listObjectInViewport);

		if(m_Rect.left < _camera->m_viewPort.left || m_Rect.right > _camera->m_viewPort.right 
			|| m_Rect.top > _camera->m_viewPort.top || m_Rect.bottom < _camera->m_viewPort.bottom)
		{
			m_IsActive = false;
		}
	} else {
		if (m_timeExplosive > 0) {
			m_spriteExplosive->Next(_time);
			m_timeExplosive -= _time;
		}
	} 
}

void CBulletBombomb::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	if (m_IsActive) {
		CEntity::Render(_spriteHandle, _camera);
	} else
	{
		if (m_timeExplosive > 0) {
			CEntity::RenderEachSprite(_spriteHandle, _camera, m_spriteExplosive, m_pos);
		}
	}
}

void CBulletBombomb::SetPos(D3DXVECTOR3 _pos)
{
	m_pos = _pos;

	m_timeExplosive = CConfig::ValueOf(KEY_EN_TIMEEXPLOSIVE);
	m_velloc = m_vellocInit;
}
bool CBulletBombomb::IsObtainCollision(CEntity* _other)
{
	if (_other->GetType() == ROCKMAN || _other->GetType() == BLOCK) {
		return true;
	}
	return false;
}

void CBulletBombomb::SetVellocInit( D3DXVECTOR2 _v)
{
	m_vellocInit = _v;
}
