#include "BulletRockman.h"
#include "ResourceManager.h"
#include "ScrewBomber.h"
#include "Rockman.h"
#include "CutMan.h"
#include "GutsMan.h"
#include "BoomMan.h"

CBulletRockman::CBulletRockman(D3DXVECTOR3 _pos)
{
	m_Type = BULLET;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES)
		, D3DXVECTOR2(170, 105), 1, 1
		, D3DXVECTOR2(155, 95));
	m_pos = _pos;

	m_accel = D3DXVECTOR2(0,0);
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());

	m_IsActive = false;
}


CBulletRockman::~CBulletRockman(void)
{
}

void CBulletRockman::UpdateCollison(CEntity* _other,float _time)
{
	if (m_IsActive) {
		bool isIntersect = false;
		switch (_other->GetType())
		{		
		case SCREW_BOMBER:
		case OCTOPUS:
		case BEAK:
		case FLEA:
		case BLADER:
		case MET:
		case BIGEYE:
		case ICEMAN:
		case CUTMAN:
		case GUTSMAN:
			isIntersect = CAABBCollision::IntersectRect(m_Rect, _other->GetRect());
			if (isIntersect) {
				_other->SetInjured(this);
			this->m_IsActive = false;
			}
			break;
		default:
			break;
		}
		
	}
}

void CBulletRockman::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity*> _listObjectInViewport)
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

void CBulletRockman::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	if (m_IsActive) {
		CEntity::Render(_spriteHandle, _camera);
	}
}

void CBulletRockman::SetPos(D3DXVECTOR3 _pos)
{
	m_pos = _pos;
}
bool CBulletRockman::IsObtainCollision(CEntity* _other)
{
	if (_other->GetType() > 1 && _other->GetType() < 110)
		return true;
	return false;
}