#include "CutMan.h"
#include "Rockman.h"
#include "PLayingGameState.h"

#define TIME_INJURED (10.0f)
#define TIME_WAIT (30.0f)
#define TIME_SHOT (2.0f)

#define VELLOC_X (10.0f)

CCutMan::CCutMan(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = CUTMAN;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MASTER), D3DXVECTOR2(870, 140) , 9, 2, D3DXVECTOR2(430, 10));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_velloc.x = 0;
	m_accel.y = -20.0f;


	//m_yInit = m_pos.y;
	m_IsJustJump = false;
	m_Status = StandHaveGun;
	m_TimeSpend = 0;
	m_TimeInjured = 0;
	m_TimeShot = 0;
	m_IsShotting = false;

	m_isTurnLeft = true;
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	//m_pos.x = CMap::g_widthMap - m_Size.x * 1.5;
	UpdateRect();
	//create list bullet
	m_Bullet = new CBulletCutman(D3DXVECTOR3(_pos.x + m_Size.x/2 - 10, _pos.y - m_Size.y/2 + 10, _pos.z));
	//create blood
	m_Blood = new CBlood(D3DXVECTOR2(740, 30), 100);
}


CCutMan::~CCutMan(void)
{
	if (m_Blood)
		delete m_Blood;
}

void CCutMan::Update(float _time, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	if (m_TimeSpend < TIME_WAIT) {
		m_TimeSpend += _time;
	} else
	{
		if (m_Status == MoveNormal || m_Status == MoveHaveGun) {
			Jump();
		}
		if ((m_Status ==  StandNormal || m_Status == StandHaveGun) && m_velloc.y == 0 && m_IsJustJump) {
			m_velloc.x = m_pos.x > CRockman::g_PosRockman.x ? -VELLOC_X : VELLOC_X;
			m_Status = m_IsShotting ? MoveNormal : MoveHaveGun;
			m_IsJustJump = false;
		} else
		{
			if ((m_Status ==  StandNormal || m_Status == StandHaveGun) && !m_IsJustJump) {
				Jump();
				m_IsJustJump = true;
			} 
		}
		m_TimeSpend = 0;
		Shot();
	}

	CEntity::Update(_time, _camera, _input, _listObjectInViewPort);

	if ((m_Status ==  JumpHaveGun || m_Status == JumpNormal || m_Status == Shotting)  && m_pos.y <= m_yInit) {
		m_Status =  m_IsShotting ? MoveNormal : MoveHaveGun;
	}
	
		if (m_velloc.y == 0 ) {
			if (m_velloc.x == 0) {		
			m_velloc.x = 0;
			m_Status = m_IsShotting ? StandNormal : StandHaveGun;
			} else {
				m_Status = m_IsShotting ? MoveNormal : MoveHaveGun;
			}
		}
		/*if (m_pos.y <= m_yInit) {
			m_pos.y = m_yInit;
			m_velloc.y = 0;
		}*/

		//When shot
		if (m_IsShotting) {
			if (m_TimeShot < TIME_SHOT) {
				m_TimeShot += _time;
				m_Status = Shotting;
			}
		}
		//When injured
		if (m_TimeInjured > 0) {
			if (m_TimeInjured < TIME_INJURED) {
				m_TimeInjured += _time;
			} else
			{
				m_TimeInjured = 0;
			}
		}
	if (!m_IsShotting) {
		if (m_Status == StandNormal) m_Status = StandHaveGun; else
		if (m_Status == MoveNormal) m_Status = MoveHaveGun; else
		if (m_Status == JumpNormal) m_Status = JumpHaveGun;
	}

	UpdateSprite(_time);
	if (m_Blood->IsOver())
		CPLayingGameState::g_ChangeState = ChangeState::CHANGE_NEXT;

	//Update bullet
	m_Bullet->SetPosCutman(m_pos);
	m_Bullet->Update(_time, _camera, _input, _listObjectInViewPort);
	m_IsShotting = m_Bullet->GetActive();
}

void CCutMan::Render(LPD3DXSPRITE _sp, CCamera* _cam)
{
	CEntity::RenderEachSprite(_sp, _cam, m_Sprite, m_pos);

	m_Bullet->Render(_sp, _cam);
	m_Blood->Render(_sp, _cam);
}

void CCutMan::UpdateSprite(float _time)
{
	switch (m_Status)
	{
	case StandNormal:
		// stand normal
		m_Sprite->NextOf(_time, 16, 17);
		break;
	case MoveNormal:
		// move normal
		m_Sprite->NextOf(_time, 11, 14);
		break;
	case StandHaveGun:
		// Stand have cut
		m_Sprite->NextOf(_time, 7, 8);
		break;
	case MoveHaveGun:
		// Stand have cut
		m_Sprite->NextOf(_time, 2, 5);
		break;
	case JumpNormal:
		// Stand have cut
		m_Sprite->IndexOf(15);
		break;
	case JumpHaveGun:
		// Stand have cut
		m_Sprite->IndexOf(6);
		break;
	case Shotting:
		// Stand have cut
		m_Sprite->NextAt(_time, 0, 1);
		break;
	default:
		break;
	}	
}

void CCutMan::Shot()
{
		if (!m_Bullet->GetActive()) {
			m_Bullet->SetActive(true);
			int xBullet = m_isTurnLeft ? m_pos.x : m_pos.x + m_Size.x;
			m_Bullet->SetPos(D3DXVECTOR3(xBullet,  m_pos.y - m_Size.y/3 , m_pos.z));
			m_Bullet->SetVelloc(D3DXVECTOR2(m_isTurnLeft ? -15 : 15, 0));
			m_IsShotting = true;
			m_TimeShot = 0;
		}
}

void CCutMan::Jump()
{
	if (m_Status == JumpHaveGun || m_Status == JumpNormal) return;
	m_velloc.y = 100.0f;
	m_accel.y = -20.0f;
	m_Status = m_IsShotting ? JumpNormal : JumpHaveGun;
}

void CCutMan::SetInjured(CEntity* _other)
{
	if (m_TimeInjured == 0) {
		m_Blood->ChangeBlood(-10);
		m_TimeInjured = 0.0000001;
	}
}

void CCutMan::UpdateCollison(CEntity* _other,float _time)
{
	switch (_other->GetType())
	{
	case ROCKMAN:
		(dynamic_cast<CRockman*>(_other))->SetInjured(this, -20);
		break;
	case LAND:
	case LAND1:
	case LAND3:
	case LAND2:
	case LANDWHITE:
	case LANDICEBERG:
		{		
			float timeEntry = m_collision->SweptAABB(this,_other,_time);
			m_directCollision = m_collision->GetDirectCollision();
			if (timeEntry < 1.0f)
			{
				ExecuteCollision(_other,m_directCollision,timeEntry);
			}
		}
		break;
	default:
		break;
	}
}

void CCutMan::ExecuteCollision(CEntity* _other,DirectCollision m_directCollion,float _timeEntry)
{
	if( m_directCollion == BOTTOM)
	{
		m_pos.y = _other->GetRect().top + m_Size.y + 1;
		m_velloc.y = 0;
	}

	if( m_directCollion == LEFT)
	{
		m_velloc.x = 0;
		m_accel.x = 0;
		m_pos.x = _other->GetRect().right + 1 ;
		m_isTurnLeft = m_pos.x > CRockman::g_PosRockman.x;
	}

	if( m_directCollion == RIGHT)
	{
		m_velloc.x = 0;
		m_accel.x = 0;
		m_pos.x = _other->GetRect().left - m_Size.x -1;
		m_isTurnLeft = m_pos.x > CRockman::g_PosRockman.x;
	}

	if (m_directCollion == TOP)
	{
		m_pos.y = _other->GetRect().bottom;
		m_velloc.y = 0;
	}
}
