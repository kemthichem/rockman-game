﻿#include "Rockman.h"
#include "PLayingGameState.h"
#include "Define.h"

const D3DXVECTOR2 CRockman::mAccelOfRockman = D3DXVECTOR2(15.0f,-25.0f);

D3DXVECTOR2 CRockman::g_PosRockman = D3DXVECTOR2(0, 100);

float TIME_INJUNRED;
float TIME_SHOT;
float VY_JUMP;
//#define VY_JUMP 70.0f
float ACCEL_STOP;
float MAX_VX;
float VX_PREPARE;
char* pathConfig = "Resource//rockman_config.txt";

vector<string> vectorDataRockManConfig = CUtils::LoadDataFromFile(pathConfig);

CRockman::CRockman(void)
{
	m_action = Action_Start;
}
CRockman::CRockman(D3DXVECTOR3 _pos)
{
	m_Id = 0;
	m_Type = ROCKMAN;
	m_SpriteStart = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), D3DXVECTOR2(72, 32), 3, 1);
	m_SpriteJump = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), D3DXVECTOR2(58, 62), 2, 1 , D3DXVECTOR2(0, 33));
	m_SpriteStand = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), D3DXVECTOR2(63, 86), 3, 1 , D3DXVECTOR2(0, 62));
	m_SpriteStandGun = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), D3DXVECTOR2(32, 110), 1, 1, D3DXVECTOR2(0, 87));
	m_SpriteRun = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), D3DXVECTOR2(72, 134), 3, 1, D3DXVECTOR2(0, 111));
	m_SpriteRunGun = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), D3DXVECTOR2(96, 158), 3, 1, D3DXVECTOR2(0, 135));
	m_SpriteClimb = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), D3DXVECTOR2(32, 188), 2, 1, D3DXVECTOR2(0, 159));
	m_SpriteClimbGun = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), D3DXVECTOR2(24, 220), 1, 1, D3DXVECTOR2(0, 189));
	m_SpriteInjured = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), D3DXVECTOR2(52, 248), 2, 1, D3DXVECTOR2(0, 221));

	m_Sprite = m_SpriteStand;
	m_pos = _pos;
	m_pos.z = DEPTH_MOTION;
	//m_pos.y = CCamera::g_PosCamera.y;
	m_action = Action_Start;
	m_velloc.y = -50.0f;
	m_accel = mAccelOfRockman;

	m_Size = m_SizeInit = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_SizeClimb = D3DXVECTOR2(m_SpriteClimb->GetWidthRectSprite() - 2, m_SpriteClimb->GetHeightRectSprite());
	UpdateRect();
	m_PosXClimb = -1;
	m_IsClimbing = false;
	m_CanDown = false;
	m_Injuring = 0;
	m_TimeInjured = 0;
	m_TimeShot = 0;
	m_accel = mAccelOfRockman;
	m_KeyDown = 0;

	//create list bullet
	for (int i = 0; i < 5; i++)
	{		CBulletRockman *bullet = new CBulletRockman(D3DXVECTOR3(_pos.x + m_Size.x/2 - 10, _pos.y - m_Size.y/2 + 10, _pos.z));
		m_ListBullet[i] = bullet;
	}

	//create blood
	m_Blood = new CBlood(D3DXVECTOR2(30, 30), 200);


	// load config
	TIME_INJUNRED = atoi(vectorDataRockManConfig.at(1).c_str());	
	TIME_SHOT = atoi(vectorDataRockManConfig.at(2).c_str());	
	VY_JUMP = atoi(vectorDataRockManConfig.at(3).c_str());
	ACCEL_STOP = atoi(vectorDataRockManConfig.at(4).c_str());
	MAX_VX = atoi(vectorDataRockManConfig.at(5).c_str());
	VX_PREPARE = atoi(vectorDataRockManConfig.at(6).c_str());

}
CRockman::~CRockman()
{
	for (int i = 0; i < 5; i++)
	{
		delete m_ListBullet[i];
	}
	delete m_Blood;
	m_Blood = NULL;

	if (m_SpriteStart) {
		delete m_SpriteStart;
		m_SpriteStart = NULL;
	}
	if (m_SpriteJump) {
		delete m_SpriteJump;
		m_SpriteJump = NULL;
	}
	if (m_SpriteStand) {
		delete m_SpriteStand;
		m_SpriteStand = NULL;
	}
	if (m_SpriteStandGun) {
		delete m_SpriteStandGun;
		m_SpriteStandGun = NULL;
	}
	if (m_SpriteRun) {
		delete m_SpriteRun;
		m_SpriteRun = NULL;
	}
	if (m_SpriteRunGun) {
		delete m_SpriteRunGun;
		m_SpriteRunGun = NULL;
	}
	if (m_SpriteClimb) {
		delete m_SpriteClimb;
		m_SpriteClimb = NULL;
	}
	if (m_SpriteClimbGun) {
		delete m_SpriteClimbGun;
		m_SpriteClimbGun = NULL;
	}
	if (m_SpriteInjured) {
		delete m_SpriteInjured;
		m_SpriteInjured = NULL;
	}
	
	m_Sprite = NULL;
}

void CRockman::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity*> _listObjectInViewPort) {
	//Always impact gravity
	m_accel.y = mAccelOfRockman.y;
	m_Size = m_SizeInit;
	m_CanDown = false;

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

	//Climb
	if (m_IsClimbing) {	
		m_velloc.x = 0;
		m_accel.x = 0;
		m_Size = m_SizeClimb;
		m_pos.x = m_PosXClimb - m_Size.x/2;
		if (m_accel.y != 0) {
			m_velloc.y = 0;
			m_accel.y = 0;
			m_action = Action_Climb_Stand;
		}
	}
	if (m_Injuring != 0)
		Injunred(m_Injuring > 0, _time);

	//reset before update
	m_PosXClimb = -1;
	m_IsClimbing = false;
	m_isCollisionBottom = false;
	m_IsLadderBottom = false;
	CEntity::Update(_time, _camera, _input, _listObjectInViewPort);

	/*m_pos.y = 50 + m_Size.y + 1;
	m_velloc.y = m_accel.y = 0;
	m_isCollisionBottom = true;
	m_IsClimbing = !m_isCollisionBottom;*/

	//Check keydown
	m_KeyDown = _input ->GetKeyDown();
	switch (m_KeyDown)
	{
	case DIK_SPACE:
		Jump();
		break;
	case DIK_A:
		Shot();
	default:
		break;
	}
	//When stop after update vellocx 
	if (abs(m_accel.x) == ACCEL_STOP) {
		if (m_accel.x < 0 && m_velloc.x < 0) {
			m_velloc.x =  0;
		}
		if (m_accel.x > 0 && m_velloc.x > 0) {
			m_velloc.x =  0;
		}
	}
	
	//Update action when Jump
	if (m_accel.y != 0 && m_action != Action_Start && !m_IsClimbing)
		m_action = Action_Jump;

	//Update action when shot
	if (m_TimeShot > 0) {
		if (m_TimeShot < TIME_SHOT) {
			m_TimeShot += _time;
			UpdateActionShot();
		} else {
			m_TimeShot = 0;
		}
	}

	//Not Edit
	//Update pos global
	g_PosRockman = D3DXVECTOR2(m_pos.x, m_pos.y);
	if (m_Blood->IsOver() /*|| m_pos.y < CCamera::g_PosCamera.y - HEIGHT_SCREEN - 200*/)
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
		m_Sprite = m_SpriteStand;
		m_Sprite->NextOf(_time, 1, 2);
		break;
	case Action_Stand_Gun:
		m_Sprite = m_SpriteStandGun;
		m_Sprite->IndexOf(0);		
		break;
	case Action_Go_Prepare:
		m_Sprite = m_SpriteStand;
		m_Sprite->IndexOf(0);
		break;
	case Action_Go:
		m_Sprite = m_SpriteRun;
		m_Sprite->NextOf(_time, 0,2);
		break;
	case Action_Go_Gun:
		m_Sprite = m_SpriteRunGun;
		m_Sprite->NextOf(_time, 0,2);
		OutputDebugString("Go gun \n");
		break;
	case Action_Jump:
		m_Sprite = m_SpriteJump;
		m_Sprite->IndexOf(0);
		OutputDebugString("jump\n");
		break;
	case Action_Jump_Gun:
		m_Sprite = m_SpriteJump;
		m_Sprite->IndexOf(1);
		OutputDebugString("jump gun\n");
		break;
	case Action_Climb_Stand:
		m_Sprite = m_SpriteClimb;
		m_Sprite->IndexOf(0);
		break;
	case Action_Climb_Stand_Gun:
		m_Sprite = m_SpriteClimbGun;
		m_Sprite->IndexOf(0);
		break;
	case Action_Climb:
		m_Sprite = m_SpriteClimb;
		m_Sprite->NextOf(_time,0,1);
		break;
	case Action_Climb_Gun:
		m_Sprite = m_SpriteClimbGun;
		m_Sprite->IndexOf(0);
		break;
	case Action_Start:
		m_Sprite = m_SpriteStart;
		m_Sprite->NextOf(_time,0,2);
		break;
	case Action_Injured:
		m_Sprite = m_SpriteInjured;
		m_Sprite->NextOf(_time, 0, 1);
		break;
	case Action_Fainting:
		break;
	default:
		m_Sprite->NextOf(_time, 12,15);
		break;
	}
}

void CRockman::UpdateActionShot()
{
	switch (m_action)
	{
	case Action_Stand:
		m_action = Action_Stand_Gun;
		break;
	case Action_Go_Prepare:
		m_action = Action_Stand_Gun;
		break;
	case Action_Go:
		m_action = Action_Go_Gun;
		break;
	case Action_Jump:
		m_action = Action_Jump_Gun;
		break;
	case Action_Climb_Stand:
		m_action = Action_Climb_Gun;
		break;
	case Action_Climb:
		m_action = Action_Climb_Gun;
		break;
	default:
		break;
	}
}

void CRockman::Stand()
{
	m_action = Action_Stand;
	m_accel.x = m_velloc.x < 0 ? ACCEL_STOP : -ACCEL_STOP;
	if (m_velloc.x == 0) {
		m_accel.x = 0;
	}
}

void CRockman::TurnLeft()
{
	if (m_IsClimbing) {
		m_isTurnLeft = true;
		return;
	}

	m_accel.x = -mAccelOfRockman.x;
	m_velloc.x = m_velloc.x < -MAX_VX ? -MAX_VX :m_velloc.x ;

	//Update action
	if (m_velloc.x > 0)
		m_action = Action_Stand;
	else 
		if (m_velloc.x > -VX_PREPARE)
			m_action = Action_Go_Prepare;
		else 
			m_action = Action_Go;
}

void CRockman::TurnRight()
{
	if (m_IsClimbing) {
		m_isTurnLeft = false;
		return;
	}

	m_accel.x = mAccelOfRockman.x;
	m_velloc.x = m_velloc.x > MAX_VX ? MAX_VX : m_velloc.x;

	//Update action
	if (m_velloc.x < 0)
		m_action = Action_Stand;
	else 
		if (m_velloc.x < VX_PREPARE)
			m_action = Action_Go_Prepare;
		else 
			m_action = Action_Go;
}

void CRockman::Climb(bool _isTurnUp)
{
	if (!_isTurnUp) {
		m_CanDown = true;
	} else {
		if (m_IsLadderBottom) {
			m_velloc.y = 0;
			return;
		}
	}
	if (m_PosXClimb > -1) {		
		m_velloc.y = _isTurnUp ? 10: -10;
		m_velloc.x = 0;
		m_accel.y = 0;
		m_action = Action_Climb;
		m_IsClimbing = true;
	}
	
}

void CRockman::Jump()
{
	if (m_accel.y == 0) {
		m_accel.y = mAccelOfRockman.y;
		m_velloc.y = VY_JUMP;
		m_action = Action_Jump;
	}
}

void CRockman::UpdateCollison(CEntity* _other, float _time) {

	float timeEntry = m_collision->SweptAABB(this,_other,_time);
	m_directCollision = m_collision->GetDirectCollision();

	switch (_other->GetType())
	{
	case LADDER:
		m_PosXClimb = _other->GetRect().left + (LONG)(_other->GetSize().x) / 2;
		m_IsClimbing = !m_isCollisionBottom;
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
	case BLOCK:
		{
			bool isIntersect = CAABBCollision::IntersectRectX(m_Rect, _other->GetRect());
			if (!m_IsClimbing && isIntersect && m_velloc.y == 0) {
				if (m_Rect.left < _other->GetRect().left && m_Rect.right > _other->GetRect().left) {
					m_velloc.x = 0;
					m_accel.x = 0;
					m_pos.x = _other->GetRect().left - m_Size.x -1;
				}
				else 
				if (m_Rect.left > _other->GetRect().left && m_Rect.left < _other->GetRect().right) {
					m_velloc.x = 0;
					m_accel.x = 0;
					m_pos.x = _other->GetRect().right + 1 ;
				}
			}
		}
	break;

	default:
		break;
	}
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
		case BLOCK:
			{ 
				//Not check collison with block when climbing
				//if (m_IsClimbing) 
				//break;
				if( m_directCollion == BOTTOM)
				{
					m_pos.y = _other->GetRect().top + m_Size.y + 1;
					m_velloc.y = m_accel.y = 0;
					m_isCollisionBottom = true;
					m_IsClimbing = false;
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
			if( m_directCollion == BOTTOM)
			{
				if (!m_CanDown) {
					m_pos.y = _other->GetRect().top + m_Size.y + 1;
					//m_PosXClimb = -1;
				}
				m_velloc.y = m_accel.y = 0;
				m_isCollisionBottom = true;
				m_IsLadderBottom = true;
				m_IsClimbing = false;
			}
			//if( m_directCollion == LEFT)
			//{
			//	m_velloc.x = 0;
			//	m_accel.x = 0;
			//	m_pos.x = _other->GetRect().right + 1 ;
			//	//m_CanClimbUp = false;
			//	m_IsClimbing = false;
			//	m_PosXClimb = -1;
			//}

			//if( m_directCollion == RIGHT)
			//{
			//	m_velloc.x = 0;
			//	m_accel.x = 0;
			//	m_pos.x = _other->GetRect().left - m_Size.x -1;
			//	//m_CanClimbUp = false;
			//	m_IsClimbing = false;
			//	m_PosXClimb = -1;
			//}
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

void CRockman::SetPos(D3DXVECTOR3 _pos)
{
	m_pos = _pos;
}
