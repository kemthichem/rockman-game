#include "BulletCutman.h"
#include "ResourceManager.h"
#include "ScrewBomber.h"
#include "Rockman.h"
#include "CutMan.h"

#define TIME_CHANGE_DES (30.0f)
#define TIME_CHANGE_DIRECT (2.0f)

#define VELLOC_X (20.0f)
#define VELLOC_Y (10.0f)

CBulletCutman::CBulletCutman(D3DXVECTOR3 _pos)
{
	m_Type = BULLET;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MASTER)
		, D3DXVECTOR2(490,120), 2, 1
		, D3DXVECTOR2(430,90));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();
	m_IsActive = false;

	//**Bullet cutman*/
	m_TimeChange = m_TimeChangeDirect = 0;
	m_DesIsCutman = false;
	m_PosCutman = D3DXVECTOR3(0,0,0);
}


CBulletCutman::~CBulletCutman(void)
{
}

void CBulletCutman::UpdateCollison(CEntity* _other,float _time)
{
	if (m_IsActive) {
		switch (_other->GetType())
		{
		case ROCKMAN:
			(dynamic_cast<CRockman*>(_other))->SetInjured(this, -15);
			m_IsActive = false;
			break;
		case CUTMAN:
			if (m_DesIsCutman)
				m_IsActive = false;
			break;
		default:
			break;
		}
	}
}


void CBulletCutman::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity*> _listObjectInViewport)
{
	if (m_IsActive) {
		D3DXVECTOR3 posDes = CRockman::g_PosRockman;

		if (m_TimeChange < TIME_CHANGE_DES) {
			m_TimeChange += _time;
		} else {
			posDes = m_PosCutman;
			m_DesIsCutman = true;
		}

		if (m_TimeChangeDirect < TIME_CHANGE_DIRECT) {
			m_TimeChangeDirect += _time;
		} else {
			m_velloc.x = m_pos.x > posDes.x ? -VELLOC_X : VELLOC_X;
			m_velloc.y = m_pos.y > posDes.y ? -VELLOC_Y : VELLOC_Y;
			m_TimeChangeDirect = 0;
		}
		m_Sprite->NextOf(_time, 0,1 );
		CEntity::Update(_time,_camera,_input,_listObjectInViewport);
	} 
}

void CBulletCutman::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	if (m_IsActive) {
		CEntity::Render(_spriteHandle, _camera);
	}
}

void CBulletCutman::SetPos(D3DXVECTOR3 _pos)
{
	m_TimeChangeDirect = m_TimeChange = 0;
	m_DesIsCutman = false;
	m_pos = _pos;
	UpdateRect();
}

void CBulletCutman::SetPosCutman(D3DXVECTOR3 _posCutman)
{
	m_PosCutman = _posCutman;
}
