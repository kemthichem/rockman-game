﻿#include "Rockman.h"
#include "MoveMap.h"
#include "PLayingGameState.h"

const D3DXVECTOR2 CRockman::mAccelOfRockman = D3DXVECTOR2(0.0f,-30.0f);

D3DXVECTOR2 CRockman::g_PosRockman = D3DXVECTOR2(0, 100);

#define TIME_INJUNRED 3.0f
#define TIME_SHOT (3.0f)
#define VY_JUMP 100.0f

CRockman::CRockman(void)
{
	m_action = Action_Start;
}
CRockman::CRockman(D3DXVECTOR3 _pos)
{
	m_Id = 0;
	m_Type = ROCKMAN;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), 
	D3DXVECTOR2(960,320), 12, 4, 
	D3DXVECTOR2(0,0), D3DXVECTOR2(11,8), D3DXVECTOR2(28,14));
	m_pos = _pos;
	m_pos.z = DEPTH_MOTION;
	m_pos.y = CCamera::g_PosCamera.y;
	m_action = Action_Start;
	m_velloc.y = -50.0f;
	m_accel = mAccelOfRockman;

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();
	m_PosXClimb = -1;
	m_IsClimbing = false;
	m_CanClimbUp = false;
	m_Injuring = 0;
	m_TimeInjured = 0;
	m_TimeShot = 0;
	m_accel = mAccelOfRockman;
	m_KeyDown = 0;

	//create list bullet
	for (int i = 0; i < 5; i++)
	{
		CBulletRockman *bullet = new CBulletRockman(D3DXVECTOR3(_pos.x + m_Size.x/2 - 10, _pos.y - m_Size.y/2 + 10, _pos.z));
		m_ListBullet[i] = bullet;
	}

	//create blood
	m_Blood = new CBlood(D3DXVECTOR2(30, 30), 200);
}
CRockman::~CRockman()
{
	for (int i = 0; i < 5; i++)
	{
		delete m_ListBullet[i];
	}

	if (m_Blood)
		delete m_Blood;
}

void CRockman::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity*> _listObjectInViewPort) {
	m_accel.y = m_IsClimbing ? 0 : mAccelOfRockman.y;

	//if (m_pos.y < 80) {
	//	m_pos.y = 80;
	//	m_isCollisionBottom = true;
	//	m_velloc.y = 0;
	//}

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
	
	if (m_velloc.y != 0 && m_action != Action_Start && m_PosXClimb == -1)
		m_action = Action_Jump;
	if (m_Injuring != 0)
		Injunred(m_Injuring > 0, _time);

	m_KeyDown = _input ->GetKeyDown();
	switch (m_KeyDown)
	{
	case DIK_SPACE:
		Jump();
		break;
	default:
		break;
	}
	

	//reset	
	m_PosXClimb = -1;
	m_isCollisionBottom = false;
	m_IsClimbing = false;
	CEntity::Update(_time, _camera, _input, _listObjectInViewPort);

	m_isTurnLeft = m_Injuring !=0 ? !m_isTurnLeft: m_isTurnLeft;

	//Climb
	if (m_IsClimbing && m_velloc.y == 0) {
		m_action = Action_Climb_Stand;
	}
	switch (m_KeyDown)
	{
	case DIK_A:
		//m_action = (ActionRockman)((int)m_action + 1);
		Shot();
		break;
	default:
		break;
	}
	//When shot
	if (m_TimeShot > 0) {
		if (m_TimeShot < TIME_SHOT) {
			m_TimeShot += _time;
			m_action = (ActionRockman)((int)m_action + 1);
		} else {
			m_TimeShot = 0;
		}
	}

	//Update pos global
	g_PosRockman = D3DXVECTOR2(m_pos.x, m_pos.y);
	if (m_Blood->IsOver() || m_pos.y < CCamera::g_PosCamera.y - HEIGHT_SCREEN - 200)
		CPLayingGameState::g_ChangeState = ChangeState::CHANGE_FAIL;

	//Update sprite	
	UpdateSprite(_time);

	//Update bullet
	for (int i = 0; i < 5; i++)
	{
		m_ListBullet[i]->Update(_time, _camera, _input, _listObjectInViewPort);
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
		OutputDebugString("jump\n");
		break;
	case Action_Jump_Gun:
		m_Sprite->IndexOf(37);
		OutputDebugString("jump gun\n");
		break;
	case Action_Climb_Stand:
		m_Sprite->OneOf(48,51);
		break;
	case Action_Climb_Stand_Gun:
		m_Sprite->OneOf(52,53);
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
		m_velloc.y = 0;
		m_accel.y = 0;
	}
	if (m_isCollisionBottom) 
	{
		m_velloc.x = 0;
		m_action = Action_Stand;
	}
}

void CRockman::TurnLeft()
{
	//if (m_isCollisionBottom /*&& m_action != */) 
	{
		m_velloc.x = m_IsClimbing ? -0.000001f : -30;
		m_action = Action_Go;
	}
}

void CRockman::TurnRight()
{
	//if (m_isCollisionBottom) 
	{
		m_velloc.x = m_IsClimbing ? 0.000001f : 30;
		m_action = Action_Go;
	}
}

void CRockman::Jump()
{
	if (m_velloc.y == 0) {
		m_accel = mAccelOfRockman;
		m_velloc.y = VY_JUMP;
		m_action = Action_Jump;
	}
}

void CRockman::CollisionBottom()
{
	m_velloc.y = 0;
	m_isCollisionBottom = true;
}

void CRockman::UpdateCollison(CEntity* _other, float _time) {
	switch (_other->GetType())
	{
	case LADDER:
		m_PosXClimb = _other->GetRect().left + 16;
		m_IsClimbing = true;
		m_CanClimbUp = true;
		if ((m_pos.y >= _other->GetRect().top + m_Size.y -5 && m_accel.y != 0))
		{
			m_CanClimbUp = false;
			m_IsClimbing = false;
		} else {
			if (m_pos.y <= _other->GetRect().bottom + m_Size.y + 5) {			
				m_IsClimbing = false;
			}
		}

		break;
	case BIGEYE:
	case BLADER:
	case SCREW_BOMBER:
	case OCTOPUS:
	case BEAK:
	case FLEA:
	case MET:
		SetInjured(_other);
		break;
	default:
		break;
	}

		float timeEntry = m_collision->SweptAABB(this,_other,_time);
		m_directCollision = m_collision->GetDirectCollision();
		if (timeEntry < 1.0f)
		{
			ExecuteCollision(_other,m_directCollision,timeEntry);
		}
}

void CRockman::ExecuteCollision(CEntity* _other,DirectCollision m_directCollion,float _timeEntry)
{
		//ListObjectColision
		switch (_other->GetType())
		{
		case LAND:
		case LAND1:
		case LAND3:
		case LAND2:
		case LANDWHITE:
		case LANDICEBERG:
			{ 
				if (m_IsClimbing) 
					break;
				if( m_directCollion == BOTTOM)
				{
					m_pos.y = _other->GetRect().top + m_Size.y + 1;
					CollisionBottom();
				}

				if( m_directCollion == LEFT)
				{
					m_velloc.x = 0;
					m_accel.x = 0;
					m_pos.x = _other->GetRect().right + 1 ;
				}

				if( m_directCollion == RIGHT)
				{
					m_velloc.x = 0;
					m_accel.x = 0;
					m_pos.x = _other->GetRect().left - m_Size.x -1;
				}

				if (m_directCollion == TOP)
				{
					m_pos.y = _other->GetRect().bottom;
					m_velloc.y = 0;
				}
			}
			break;
		case LADDER:
			if (m_directCollion == TOP)
			{/*
				m_action = Action_Stand;
				m_velloc.x = m_velloc.y = 0;*/
			}
			break;
		case MOVEMAP:
			CMoveMap *moveMap = dynamic_cast<CMoveMap*> (_other);
			if (m_directCollion == TOP)
			{
				if (moveMap->IsCanWithDirect(true)) {
					CMoveMap::g_DistanceMoveCameraY = HEIGHT_SCREEN;
					m_pos.y += 1;
					CMoveMap::g_TypeMove = TypeMove::MOVEY;
				}
			}
			if (m_directCollion == BOTTOM)
			{
				if (moveMap->IsCanWithDirect(false)) {
					CMoveMap::g_DistanceMoveCameraY = -HEIGHT_SCREEN;
					m_pos.y -= 1;
					CMoveMap::g_TypeMove = TypeMove::MOVEY;
				}
			}
			break;
		
		}
}

void CRockman::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	CEntity::Render(_spriteHandle, _camera);

	//Render bullet
	for (int i = 0; i < 5; i++)
	{
		m_ListBullet[i]->Render(_spriteHandle, _camera);
	}
	//Render blood
	m_Blood->Render(_spriteHandle, _camera);
}

void CRockman::Shot()
{
	for (int i = 0; i < 5; i++)
	{
		if (!m_ListBullet[i]->GetActive()) {
			m_ListBullet[i]->SetActive(true);
			m_ListBullet[i]->SetPos(D3DXVECTOR3(m_pos.x + m_Size.x/2 - 10, m_pos.y - m_Size.y/2 + 10, m_pos.z));
			m_ListBullet[i]->SetVelloc(D3DXVECTOR2(m_isTurnLeft ? -80 : 80, 0));
			m_TimeShot = 0.001f;
			break;
		}
	}
}

void CRockman::Climb(bool _isTurnUp)
{
	if (_isTurnUp) {
		if (!m_CanClimbUp)
			return;
	}
	if (m_PosXClimb > -1) {
		m_velloc.y = _isTurnUp ? 10: -10;
		m_accel.y = 0;
		m_pos.x = m_PosXClimb - m_Size.x/2;
		m_action = Action_Climb;
		m_IsClimbing = true;
	}
}

void CRockman::Injunred(bool _isImpactLeft, float _time)
{
	if (m_TimeInjured >= TIME_PER_ANIMATION * 2) {
		m_TimeInjured = 0;
		m_Injuring = 0;
		return;
	}
	m_TimeInjured += _time;
	m_velloc.x = _isImpactLeft ? 10: -10;
	
	m_action = Action_Injured;
}

void CRockman::SetInjured(CEntity* _other, int _dam)
{
	if (m_Injuring != 0) return;
	m_Injuring = _other->GetVelocity().x > 0 ? 1 : -1;
	m_Blood->ChangeBlood(_dam);
}

int CRockman::GetKeyDown()
{
	return m_KeyDown;
}
