#include "BulletGutsman.h"
#include "ResourceManager.h"
#include "ScrewBomber.h"
#include "Rockman.h"
#include "GutsMan.h"

#define VELLOC (35.0f)

CBulletGutsman::CBulletGutsman(D3DXVECTOR3 _pos)
{
	m_Type = BULLET;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MASTER), D3DXVECTOR2(880, 210) , 9, 1, D3DXVECTOR2(250,140), D3DXVECTOR2(0,0), D3DXVECTOR2(0,0));
	m_pos = _pos;

	m_accel = D3DXVECTOR2(0,0);
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());

	m_IsActive = false;
}


CBulletGutsman::~CBulletGutsman(void)
{
}

void CBulletGutsman::UpdateCollison(CEntity* _other,float _time)
{
	if (m_IsActive) {
		switch (_other->GetType())
		{
		case ROCKMAN:
			(dynamic_cast<CRockman*>(_other))->SetInjured(this, -25);
			m_velloc.x = m_velloc.y = 0;
			m_IsActive = false;
			break;
		case GUTSMAN:
			Throw(_other);
			break;
		default:
			break;
		}
	}
}


void CBulletGutsman::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity*> _listObjectInViewport)
{
	if (m_IsActive) {
		
		
		CEntity::Update(_time,_camera,_input,_listObjectInViewport);
		m_Sprite->IndexOf(1);
	} 

	if(m_Rect.left < _camera->m_viewPort.left || m_Rect.right > _camera->m_viewPort.right 
		|| m_Rect.top > _camera->m_viewPort.top || m_Rect.bottom < _camera->m_viewPort.bottom)
	{
		m_IsActive = false;
		m_velloc.x = m_velloc.y = 0;
	}
}

void CBulletGutsman::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	if (m_IsActive) {
		CEntity::Render(_spriteHandle, _camera);
	}
}

void CBulletGutsman::SetPos(D3DXVECTOR3 _pos)
{
	m_accel.y = -20.0f;
	m_pos = _pos;
	UpdateRect();
}

void CBulletGutsman::Throw(CEntity* _other)
{
	if (m_velloc.x != 0) return;
	D3DXVECTOR3 posDes = CRockman::g_PosRockman;
	int disX = posDes.x - m_pos.x;
	int disY = posDes.y - m_pos.y;
	float rate = abs(((float)disY/disX));

	m_velloc.x = disX > 0 ? VELLOC : -VELLOC;
	m_velloc.y = disY > 0 ? VELLOC * rate: -VELLOC * rate;
	m_accel.y = 0;

	(dynamic_cast<CGutsMan*>(_other))->SetThrow(true);
}
