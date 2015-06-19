#include "IceMan.h"
#include "Rockman.h"
#include "PLayingGameState.h"

#define TIME_INJURED (10.0f)
#define TIME_WAIT (30.0f)

#define VELLOC_X (10.0f)

CIceMan::CIceMan(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = ICEMAN;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MASTER), D3DXVECTOR2(870, 480) , 8, 1, D3DXVECTOR2(420, 420));
	m_pos = _pos;
	m_yInit = m_yShot = m_pos.y;
	m_accel = D3DXVECTOR2(0,0.0f);
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_IsJustJump = false;

	UpdateRect();

	/*Iceman*/
	m_Status = HELLO;
	m_TimeSpend = 0;
	m_TimeInjured = 0;
	m_IsHello = true;
	m_isTurnLeft = true;
	m_pos.x = CCamera::g_PosCamera.x + WIDTH_SCREEN - m_Size.x * 1.5;
	//create list bullet
	for (int i = 0; i < 5; i++)
	{
		CBulletIceman *bullet = new CBulletIceman(D3DXVECTOR3(_pos.x + m_Size.x/2 - 10, _pos.y - m_Size.y/2 + 10, _pos.z));
		m_ListBullet[i] = bullet;
	}

	//create blood
	m_Blood = new CBlood(D3DXVECTOR2(740, 30), 100);
}


CIceMan::~CIceMan(void)
{
	for (int i = 0; i < 5; i++)
	{
		delete m_ListBullet[i];
	}

	if (m_Blood)
		delete m_Blood;
}

void CIceMan::Update(float _time, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	if (m_TimeSpend < TIME_WAIT) {
			m_TimeSpend += _time;
	} else
	{
		if (m_IsHello) {
			m_Status =  STAND;
			m_IsHello = false;
		}
		if (m_Status == MOVE) {
			Jump();
		}
		if (m_Status ==  STAND && m_pos.y <= m_yInit && m_IsJustJump) {
			m_velloc.x = m_pos.x > CRockman::g_PosRockman.x ? -VELLOC_X : VELLOC_X;
			m_Status = MOVE;
			m_IsJustJump = false;
		} else
		{
			if (m_Status == STAND && !m_IsJustJump) {
				Jump();
				m_IsJustJump = true;
			} 
		}
		m_TimeSpend = 0;
		//Shot();
	}

	if (m_Status == JUMP && m_velloc.y < 0) {
		
		if (m_pos.y < m_yShot - 40 || (m_yShot == m_yInit && ((int)m_pos.y - m_yInit < 200))) {
			Shot();
			m_velloc.y = -6.0f;
			m_accel.y = 0.0f;
		}
	}

	CEntity::Update(_time, _camera, _input, _listObjectInViewPort);

	if (m_pos.x <= CCamera::g_PosCamera.x + 20) {
		m_velloc.x *= -1;
	} else 
		if (m_pos.x >= CCamera::g_PosCamera.x + WIDTH_SCREEN - m_Size.x * 1.5 && m_pos.y <= m_yInit) {
			m_isTurnLeft = true;			
			m_velloc.x = 0;
			if (m_Status != HELLO)
				m_Status = STAND;
		}
	if (m_pos.y <= m_yInit) {
		m_pos.y = m_yInit;
		m_velloc.y = 0;
		m_yShot = m_yInit;
	}
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
	for (int i = 0; i < 5; i++)
	{
		m_ListBullet[i]->Update(_time, _camera, _input, _listObjectInViewPort);
	}
}

void CIceMan::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	CEntity::RenderEachSprite(_spriteHandle, _camera, m_Sprite, m_pos);

	//Render bullet
	for (int i = 0; i < 5; i++)
	{
		m_ListBullet[i]->Render(_spriteHandle, _camera);
	}
	//Render blood
	m_Blood->Render(_spriteHandle, _camera);
}

void CIceMan::UpdateSprite(float _time)
{
	switch (m_Status)
	{
	case HELLO:
		// stand normal
		m_Sprite->NextOf(_time, 4, 5);
		break;
	case STAND:
		// move normal
		m_Sprite->IndexOf(7);
		break;
	case MOVE:
		// Stand have cut
		m_Sprite->NextOf(_time, 2, 3);
		break;
	case JUMP:
		// Stand have cut
		m_Sprite->IndexOf(6);
		break;
	default:
		break;
	}
}

void CIceMan::Shot()
{
		for (int i = 0; i < 5; i++)
		{
			if (!m_ListBullet[i]->GetActive()) {
				m_ListBullet[i]->SetActive(true);
				int xBullet = m_isTurnLeft ? m_pos.x : m_pos.x + m_Size.x;
				m_ListBullet[i]->SetPos(D3DXVECTOR3(xBullet,  m_pos.y - m_Size.y/3 , m_pos.z));
				m_ListBullet[i]->SetVelloc(D3DXVECTOR2(m_isTurnLeft ? -15 : 15, 0));
				m_yShot = m_pos.y;
				break;
			}
		}
}

void CIceMan::SetInjured(CEntity* _other)
{
	if (m_TimeInjured == 0) {
		m_Blood->ChangeBlood(-10);
		m_TimeInjured = 0.0000001;
	}
}

void CIceMan::Jump()
{
	if (m_Status == JUMP) return;
	m_velloc.y = 100.0f;
	m_accel.y = -20.0f;
	m_Status = JUMP;
}

void CIceMan::UpdateCollison(CEntity* _other,float _time) {
	switch (_other->GetType())
	{
	case ROCKMAN:
		(dynamic_cast<CRockman*>(_other))->SetInjured(this, -20);
		break;
	default:
		break;
	}
}