#include "BulletCutman.h"
#include "ResourceManager.h"
#include "Config.h"
#include "Rockman.h"
#include "CutMan.h"

#define TIME_CHANGE_DIRECT (15.0f)

CBulletCutman::CBulletCutman(D3DXVECTOR3 _pos)
{
	m_Type = BULLET;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MASTER), D3DXVECTOR2(28,51), 2, 1, D3DXVECTOR2(0,37));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();
	m_IsActive = false;

	//**Bullet cutman*/
	m_TimeChangeDirect = 0;
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
			//m_IsActive = false;
			break;
		case CUTMAN:
			if (m_DesIsCutman) {
				m_IsActive = false;
				m_pos = m_PosCutman;
			}
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

		if (m_TimeChangeDirect < CConfig::ValueOf(KEY_CM_BULLET_TIME_CHANGE_DIRECT)) {
			m_TimeChangeDirect += _time;


			//change direct to back cutman
			if (m_DesIsCutman ) {
				ChangeDirection(D3DXVECTOR2(m_PosCutman.x, m_PosCutman.y));
			}

		} else {
			if (!m_DesIsCutman) {
				ChangeDirection(D3DXVECTOR2(m_PosCutman.x, m_PosCutman.y));
				m_TimeChangeDirect = 0;
				m_DesIsCutman = true;
			}
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
	m_TimeChangeDirect = 0;
	m_DesIsCutman = false;
	m_pos = _pos;
	m_posAttack.x = CRockman::g_PosRockman.x;
	m_posAttack.y = CRockman::g_PosRockman.y;

	ChangeDirection(m_posAttack);
	UpdateRect();
}

void CBulletCutman::SetPosCutman(D3DXVECTOR3 _posCutman)
{
	m_PosCutman = _posCutman;
}

void CBulletCutman::ChangeDirection(D3DXVECTOR2 _posDest)
{
	int disX = abs(_posDest.x - m_pos.x);
	int disY = abs(_posDest.y - m_pos.y);

	char dirY = _posDest.y - m_pos.y > 0 ? 1 : -1;
	m_velloc.y = (double)(dirY * CConfig::ValueOf(KEY_CM_VELLOC_Y));

	char dirX = _posDest.x - m_pos.x > 0 ? 1 : -1;
	m_velloc.x = dirX * abs(m_velloc.y) * disX / disY;
	if (abs(m_velloc.x) > abs(m_velloc.y)) {
		m_velloc.x = dirX * CConfig::ValueOf(KEY_CM_VELLOC_Y);
		m_velloc.y = dirY * abs(m_velloc.x * disY / disX);
	} else {
		m_velloc.y = dirY * CConfig::ValueOf(KEY_CM_VELLOC_Y);
		m_velloc.x = dirX * abs(m_velloc.y * disX / disY);
	}
}

bool CBulletCutman::IsObtainCollision(CEntity* _other)
{
	if (_other->GetType() == ROCKMAN || _other->GetType() == CUTMAN) {
		return true;
	}
	return false;
}