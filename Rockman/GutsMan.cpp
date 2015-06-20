#include "GutsMan.h"
#include "PLayingGameState.h"

#define TIME_INJURED (10.0f)
#define TIME_WAIT (25.0f)
#define TIME_SHOT (4.0f)

#define VELLOC_X (10.0f)

CGutsMan::CGutsMan(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = GUTSMAN;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MASTER), D3DXVECTOR2(880, 210) , 9, 1, D3DXVECTOR2(250,140), D3DXVECTOR2(0,0), D3DXVECTOR2(0,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();

	/*Gustman*/	
	m_yInit =  m_pos.y;
	m_Status = GStand;
	m_TimeInjured = m_TimeChange = 0;
	m_TimeShot = 0;
	m_isTurnLeft = true;
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_pos.x = CMap::g_widthMap - m_Size.x * 1.5;
	UpdateRect();

	//create list bullet
	m_Bullet = new CBulletGutsman(D3DXVECTOR3(_pos.x + m_Size.x/2 - 10, _pos.y - m_Size.y/2 + 10, _pos.z));
	//create blood
	m_Blood = new CBlood(D3DXVECTOR2(740, 30), 100);
}


CGutsMan::~CGutsMan(void)
{
}

void CGutsMan::Update(float _time, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	if (m_TimeChange < TIME_WAIT) {
		m_TimeChange += _time;
	} else {
		m_TimeChange = 0;
		Jump();
	}

	CEntity::Update(_time, _camera, _input, _listObjectInViewPort);
	if (m_pos.y <= m_yInit) {
		m_pos.y = m_yInit;
		m_velloc.y = 0;
		m_velloc.x = 0;
		if (m_Status == GJump) {
			Shot();
			m_Status = GCatchGun;
		}
		if (m_TimeShot > 0 ) {
			if ( m_TimeShot < TIME_SHOT) {
				m_TimeShot += _time;
			} else {
				m_TimeShot = 0;
				m_Status = GStand;
			}
		}
	}
	//Shot

	//When injured
	if (m_TimeInjured > 0) {
		if (m_TimeInjured < TIME_INJURED) {
			m_TimeInjured += _time;
		} else
		{
			m_TimeInjured = 0;
		}
	}
	UpdateSprite(_time);
	if (m_Blood->IsOver())
		CPLayingGameState::g_ChangeState = ChangeState::CHANGE_NEXT;

	//Update bullet
	m_Bullet->Update(_time, _camera, _input, _listObjectInViewPort);
}

void CGutsMan::Render(LPD3DXSPRITE _sp, CCamera* _cam)
{
	CEntity::RenderEachSprite(_sp, _cam, m_Sprite, m_pos);

	m_Bullet->Render(_sp, _cam);
	m_Blood->Render(_sp, _cam);
}

void CGutsMan::SetInjured(CEntity* _other)
{
	if (m_TimeInjured == 0) {
		m_Blood->ChangeBlood(-10);
		m_TimeInjured = 0.0000001;
	}
}

void CGutsMan::Jump()
{
	if (m_Status == GJump) return;
	m_velloc.y = 100.0f;
	m_accel.y = -20.0f;
	m_Status = GJump;
}

void CGutsMan::Shot()
{
	if (!m_Bullet->GetActive()) {
		m_Bullet->SetActive(true);
		int xBullet = m_pos.x;
		m_Bullet->SetPos(D3DXVECTOR3(xBullet,  m_pos.y + 300 , m_pos.z));
	}
}

void CGutsMan::UpdateSprite(float _time)
{
	switch (m_Status)
	{
	case GStand:
		m_Sprite->NextOf(_time, 6, 8);
		break;
	case GCatchGun:
		m_Sprite->IndexOf(4);
		break;
	case GShot:
		m_Sprite->IndexOf(2);
		break;
	case GJump:
		m_Sprite->IndexOf(5);
		break;
	default:
		break;
	}
}

void CGutsMan::SetThrow(bool _isThrow)
{
	m_TimeShot = _isThrow;
	m_TimeShot = 0.0001f;
	m_Status = GShot;
}
