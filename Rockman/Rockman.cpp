#include "Rockman.h"


D3DXVECTOR2 CRockman::posInMap;

const D3DXVECTOR2 CRockman::mAccelOfRockman = D3DXVECTOR2(0.0f,-30.0f);

CRockman::CRockman(void)
{
	m_action = Action_Start;
}
CRockman::CRockman(D3DXVECTOR3 _pos)
{
	m_sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), 960, 320, 12, 4);
	m_pos = _pos;
	m_pos.y = HEIGHT_SCREEN;
	m_action = Action_Start;
	m_veloc.y = -250.0f;
	m_accel = mAccelOfRockman;
}
CRockman::~CRockman()
{

}

void CRockman::Update(float _deltaTime, CCamera *_camera, CInput *_input){
	CEntity::Update(_deltaTime, _camera, _input);
	m_isCollisionBottom = false;
	if (m_pos.y <= 100) {
		m_pos.y = 100;
		CollisionBottom();
	}



	//turn left and right
	if (_input->KeyDown(DIK_RIGHT)) {		
		TurnRight();
	} else if(_input->KeyDown(DIK_LEFT)) {
		TurnLeft();
	} else {
		Stand();
	}


	int keyDown = _input ->GetKeyDown();
	if (keyDown == DIK_SPACE) {
		Jump();
	} else {
		if (keyDown == DIK_A) {
			m_action = (ActionRockman)((int)m_action + 1);
		}
	}

	int keyUp = _input->GetKeyUp();
	if (keyUp == DIK_A) {
		m_action = (ActionRockman)((int)m_action - 1);
	}

	/*if (mVeloc.y != 0 && mAction != Action_Start)  {
		mAction = Action_Jump;
	}*/

	//Update sprite	
	UpdateSprite();
}

void CRockman::UpdateSprite()
{
	switch (m_action)
	{
	case Action_Stand:
		m_sprite->NextOf(12,15);
		break;
	case Action_Stand_Gun:
		m_sprite->IndexOf(16);
		OutputDebugString("Stand gun \n");
		break;
	case Action_Go:
		m_sprite->NextOf(24,28);
		break;
	case Action_Go_Gun:
		m_sprite->NextOf(30,35);
		OutputDebugString("Go gun \n");
		break;
	case Action_Jump:
		m_sprite->IndexOf(36);
		break;
	case Action_Jump_Gun:
		m_sprite->IndexOf(37);
		break;
	case Action_Climb:
		break;
	case Action_Climb_Gun:
		break;
	case Action_Start:
		m_sprite->NextOf(0,7);
		break;
	case Action_Injured:
		break;
	case Action_Fainting:
		break;
	default:
		m_sprite->NextOf(12,15);
		break;
	}
}

void CRockman::Stand()
{
	if (m_isCollisionBottom) {
		m_veloc.x = 0;
		m_action = Action_Stand;
	}
}

void CRockman::TurnLeft()
{
	if (m_isCollisionBottom) {
		m_veloc.x = -50;
		m_action = Action_Go;
	}
}

void CRockman::TurnRight()
{
	if (m_isCollisionBottom) {
		m_veloc.x = 50;
		m_action = Action_Go;
	}
}

void CRockman::Jump()
{
	if (m_isCollisionBottom) {
		m_accel = mAccelOfRockman;
		m_veloc.y = 120.0f;
		m_action = Action_Jump;
	}
}

void CRockman::CollisionBottom()
{
	m_veloc.y = 0;
	m_accel.y = 0;
	m_action = Action_Stand;
	m_isCollisionBottom = true;
}

