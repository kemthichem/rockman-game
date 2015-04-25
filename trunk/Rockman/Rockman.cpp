#include "Rockman.h"


D3DXVECTOR2 CRockman::posInMap;

const D3DXVECTOR2 CRockman::mAccelOfRockman = D3DXVECTOR2(0.0f,-30.0f);

CRockman::CRockman(void)
{
	mAction = Action_Start;
}
CRockman::CRockman(D3DXVECTOR3 _pos)
{
	mSprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), 960, 320, 12, 4);
	mPos = _pos;
	mPos.y = HEIGHT_SCREEN;
	mAction = Action_Start;
	mVeloc.y = -250.0f;
	mAccel = mAccelOfRockman;
}
CRockman::~CRockman()
{

}

void CRockman::Update(float deltaTime, CCamera *_camera, CInput *_input){
	CEntity::Update(deltaTime, _camera, _input);
	m_isCollisionBottom = false;
	if (mPos.y <= 100) {
		mPos.y = 100;
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
			mAction = (ActionRockman)((int)mAction + 1);
		}
	}

	int keyUp = _input->GetKeyUp();
	if (keyUp == DIK_A) {
		mAction = (ActionRockman)((int)mAction - 1);
	}

	/*if (mVeloc.y != 0 && mAction != Action_Start)  {
		mAction = Action_Jump;
	}*/

	//Update sprite	
	UpdateSprite();
}

void CRockman::UpdateSprite()
{
	switch (mAction)
	{
	case Action_Stand:
		mSprite->NextOf(12,15);
		break;
	case Action_Stand_Gun:
		mSprite->IndexOf(16);
		OutputDebugString("Stand gun \n");
		break;
	case Action_Go:
		mSprite->NextOf(24,28);
		break;
	case Action_Go_Gun:
		mSprite->NextOf(30,35);
		OutputDebugString("Go gun \n");
		break;
	case Action_Jump:
		mSprite->IndexOf(36);
		break;
	case Action_Jump_Gun:
		mSprite->IndexOf(37);
		break;
	case Action_Climb:
		break;
	case Action_Climb_Gun:
		break;
	case Action_Start:
		mSprite->NextOf(0,7);
		break;
	case Action_Injured:
		break;
	case Action_Fainting:
		break;
	default:
		mSprite->NextOf(12,15);
		break;
	}
}

void CRockman::Stand()
{
	if (m_isCollisionBottom) {
		mVeloc.x = 0;
		mAction = Action_Stand;
	}
}

void CRockman::TurnLeft()
{
	if (m_isCollisionBottom) {
		mVeloc.x = -50;
		mAction = Action_Go;
	}
}

void CRockman::TurnRight()
{
	if (m_isCollisionBottom) {
		mVeloc.x = 50;
		mAction = Action_Go;
	}
}

void CRockman::Jump()
{
	if (m_isCollisionBottom) {
		mAccel = mAccelOfRockman;
		mVeloc.y = 120.0f;
		mAction = Action_Jump;
	}
}

void CRockman::CollisionBottom()
{
	mVeloc.y = 0;
	mAccel.y = 0;
	mAction = Action_Stand;
	m_isCollisionBottom = true;
}

