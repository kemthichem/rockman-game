﻿#include "Rockman.h"
#include "MoveMap.h"

const D3DXVECTOR2 CRockman::mAccelOfRockman = D3DXVECTOR2(0.0f,-30.0f);
#define TIME_INJUNRED 3.0f;

CRockman::CRockman(void)
{
	m_action = Action_Start;
}
CRockman::CRockman(D3DXVECTOR3 _pos)
{
	m_Type = ROCKMANTYPE;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), D3DXVECTOR2(960,320), 12, 4, 
		D3DXVECTOR2(0,0), D3DXVECTOR2(11,8), D3DXVECTOR2(28,14));
	m_pos = _pos;
	m_pos.z = DEPTH_MOTION;
	m_pos.y = 1000;
	m_action = Action_Start;
	m_veloc.y = -250.0f;
	m_accel = mAccelOfRockman;

	m_collision = new CAABBCollision();
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_PosXClimb = -1;
	m_IsInjuring = false;
	m_TimeInjured = 0;
	m_accel = mAccelOfRockman;
}
CRockman::~CRockman()
{
	for(int i = 0; i < m_ListBullet.size(); ++i)
		delete m_ListBullet[i];

	m_ListBullet.clear();
}

void CRockman::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity*> _listObjectInViewPort) {
	m_accel.y = mAccelOfRockman.y;

	if (m_pos.y < 80) {
		m_pos.y = 80;
		m_isCollisionBottom = true;
		m_veloc.y = 0;
	}

	//turn left and right
	if (_input->KeyDown(DIK_RIGHT)) {		
		TurnRight();
	} else if (_input->KeyDown(DIK_LEFT)) {
		TurnLeft();
	} else if (_input->KeyDown(DIK_UP)) {
		Climb(true);
	} else if (_input->KeyDown(DIK_DOWN)) {
		Climb(false);
	} else {
		Stand();
	}
	
	if (m_veloc.y != 0 && m_action != Action_Start && m_PosXClimb == -1)
		m_action = Action_Jump;
	if (m_IsInjuring != 0)
		Injunred(m_IsInjuring > 0, _time);

	int keyDown = _input ->GetKeyDown();
	switch (keyDown)
	{
	case DIK_SPACE:
		Jump();
		break;
	case DIK_A:
		m_action = (ActionRockman)((int)m_action + 1);
		Shot();
		break;
	default:
		break;
	}

	int keyUp = _input->GetKeyUp();
	if (keyUp == DIK_A) {
		m_action = (ActionRockman)((int)m_action - 1);		
	}

	//reset	
	m_PosXClimb = -1;
	m_isCollisionBottom = false;
	CEntity::Update(_time, _camera, _input, _listObjectInViewPort);

	m_isTurnLeft = m_IsInjuring !=0 ? !m_isTurnLeft: m_isTurnLeft;

	//Update sprite	
	UpdateSprite(_time);

	//Update bullet
	for(vector<CBullet*>::const_iterator it = m_ListBullet.begin(); it != m_ListBullet.end(); it++)
	{
		(*it)->Update(_time, _camera, _input, _listObjectInViewPort);
		if((*it)->GetRect().left<0 || (*it)->GetRect().right>800||(*it)->GetRect().top>600||(*it)->GetRect().bottom<0)
		{
			//m_ListBullet.erase(it);
		}
	} 
}

void CRockman::UpdateSprite(float _time)
{
	switch (m_action)
	{
	case Action_Stand:
		m_Sprite->NextOf(_time, 12,15);
		break;
	case Action_Stand_Gun:
		m_Sprite->IndexOf(16);
		OutputDebugString("Stand gun \n");
		break;
	case Action_Go:
		m_Sprite->NextOf(_time, 24,28);
		break;
	case Action_Go_Gun:
		m_Sprite->NextOf(_time, 30,35);
		OutputDebugString("Go gun \n");
		break;
	case Action_Jump:
		m_Sprite->IndexOf(36);
		break;
	case Action_Jump_Gun:
		m_Sprite->IndexOf(37);
		break;
	case Action_Climb_Stand:
		m_Sprite->OneOf(48,51);
		break;
	case Action_Climb:
		m_Sprite->NextOf(_time,48,51);
		break;
	case Action_Climb_Gun:
		break;
	case Action_Start:
		m_Sprite->NextOf(_time,0,7);
		break;
	case Action_Injured:
		m_Sprite->NextOf(_time, 60, 61);
		break;
	case Action_Fainting:
		break;
	default:
		m_Sprite->NextOf(_time, 12,15);
		break;
	}
}

void CRockman::Stand()
{
	if (m_PosXClimb > -1) {
		m_veloc.y = 0;
		m_accel.y = 0;
	}
	if (m_isCollisionBottom) 
	{
		m_veloc.x = 0;
		m_action = Action_Stand;
	}
}

void CRockman::TurnLeft()
{
	if (m_isCollisionBottom) 
	{
		m_veloc.x = -30;
		m_action = Action_Go;
	}
}

void CRockman::TurnRight()
{
	if (m_isCollisionBottom) 
	{
		m_veloc.x = 30;
		m_action = Action_Go;
	}
}

void CRockman::Jump()
{
	if (m_veloc.y == 0) {
		m_accel = mAccelOfRockman;
		m_veloc.y = 120.0f;
		m_action = Action_Jump;
	}
}

void CRockman::CollisionBottom()
{
	m_veloc.y = 0;
	m_isCollisionBottom = true;
}

void CRockman::UpdateCollison(CEntity* _orther, float _time) {
	switch (_orther->GetType())
	{
	case LADDERTYPE:
		if (m_veloc.y == 0)
			m_action = Action_Climb_Stand;
		m_PosXClimb = _orther->GetRect().left + 16;
		m_isCollisionBottom = true;
		break;
	case BIGEYETYPE:
	case BLADER:
		m_IsInjuring = _orther->GetVelocity().x > 0 ? 1 : -1;
		
		break;
	default:
		break;
	}

	if (_orther->GetType()!= ROCKMANTYPE)
	{
		float timeEntry = m_collision->SweptAABB(this,_orther,_time);
		m_directCollision = m_collision->GetDirectCollision();
		if (timeEntry < 1.0f)
		{
			ExecuteCollision(_orther,m_directCollision,timeEntry);
		}
	}
}

void CRockman::ExecuteCollision(CEntity* _orther,DirectCollision m_directCollion,float _timeEntry)
{
		//ListObjectColision
		switch (_orther->GetType())
		{
		case LANDTYPE:
			{
				if( m_directCollion == BOTTOM)
				{
					m_pos.y = _orther->GetRect().top + m_Size.y + 1;
					CollisionBottom();
				}

				if( m_directCollion == LEFT)
				{
					m_veloc.x = 0;
					m_accel.x = 0;
					m_pos.x = _orther->GetRect().right ;
				}

				if( m_directCollion == RIGHT)
				{
					m_veloc.x = 0;
					m_accel.x = 0;
					m_pos.x = _orther->GetRect().left - m_Size.x;
				}

				if( m_directCollion == TOP)
				{
					m_pos.y = _orther->GetRect().bottom;
					m_veloc.y = 0;
				}
			}
			break;
		case MOVEMAPTYPE:
 			CMoveMap::g_IsMovingMap = true;
			if( m_directCollion == TOP)
			{
				CMoveMap::g_DistanceMoveCameraY = HEIGHT_SCREEN;
				m_pos.y += 1;
			}
			if( m_directCollion == BOTTOM)
			{
				CMoveMap::g_DistanceMoveCameraY = -HEIGHT_SCREEN;
				m_pos.y -= 1;
			}
			break;
		}
}

void CRockman::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	CEntity::Render(_spriteHandle, _camera);

	//Render bullet
	for (int i = 0; i < m_ListBullet.size(); i++)
	{
		m_ListBullet[i]->Render(_spriteHandle, _camera);
	}
}

void CRockman::Shot()
{
	CBullet *bullet = new CBullet(D3DXVECTOR3(m_pos.x, m_pos.y - 20, 0));
	if (m_isTurnLeft)
		bullet->SetVelloc(D3DXVECTOR2(-60,0));
	else
		bullet->SetVelloc(D3DXVECTOR2(60,0));

	m_ListBullet.push_back(bullet);
}

void CRockman::Climb(bool _isTurnUp)
{
	if (m_PosXClimb > -1) {
		m_veloc.y = _isTurnUp ? 10: -10;
		m_accel.y = 0;
		m_pos.x = m_PosXClimb - m_Size.x/2;
		m_action = Action_Climb;
	}
}

void CRockman::Injunred(bool _isImpactLeft, float _time)
{
	if (m_TimeInjured >= TIME_PER_ANIMATION * 2) {
		m_TimeInjured = 0;
		m_IsInjuring = 0;
		return;
	}

	m_TimeInjured += _time;
	m_veloc.x = _isImpactLeft ? 10: -10;
	m_action = Action_Injured;
}