#include "Rockman.h"
#include "MoveMap.h"

const D3DXVECTOR2 CRockman::mAccelOfRockman = D3DXVECTOR2(0.0f,-30.0f);

CRockman::CRockman(void)
{
	m_action = Action_Start;
}
CRockman::CRockman(D3DXVECTOR3 _pos)
{
	m_Type = ROCKMANTYPE;
	m_sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), 960, 320, 12, 4);
	m_pos = _pos;
	m_pos.y = 1000;
	m_action = Action_Start;
	m_veloc.y = -250.0f;
	m_accel = mAccelOfRockman;

	m_collision = new CAABBCollision();
}
CRockman::~CRockman()
{
	for(int i = 0; i < m_listBullet.size(); ++i)
		delete m_listBullet[i];

	m_listBullet.clear();
}

void CRockman::Update(float _deltaTime, CCamera *_camera, CInput *_input, vector<CEntity*> _listObjectInViewPort){
	CEntity::Update(_deltaTime, _camera, _input, _listObjectInViewPort);

	//if (m_pos.y < 80) {
	//	m_pos.y = 80;
	//	m_veloc.y = 0;
	//}

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
			Shot();
		}
	}

	int keyUp = _input->GetKeyUp();
	if (keyUp == DIK_A) {
		m_action = (ActionRockman)((int)m_action - 1);
		
	}

	//Update sprite	
	UpdateSprite();

	//Update bullet
	for(vector<CBullet*>::const_iterator it = m_listBullet.begin(); it != m_listBullet.end(); it++)
	{
		(*it)->Update(_deltaTime, _camera, _input, _listObjectInViewPort);
		if((*it)->GetRect().left<0 || (*it)->GetRect().right>800||(*it)->GetRect().top>600||(*it)->GetRect().bottom<0)
		{
			//m_listBullet.erase(it);
		}
	} 
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
	if (1)//m_isCollisionBottom) {
	{
		m_veloc.x = 0;
		m_action = Action_Stand;
	}
}

void CRockman::TurnLeft()
{
	if (1)//m_isCollisionBottom) {
	{
		m_veloc.x = -30;
		m_action = Action_Go;
	}
}

void CRockman::TurnRight()
{
	if (1)//m_isCollisionBottom) 
	{
		m_veloc.x = 30;
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
	m_action = Action_Stand;
	m_isCollisionBottom = true;
}

void CRockman::UpdateCollison(CEntity* _orther, float _time) {
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
					m_pos.y = _orther->GetRect().top + m_sprite->heightOfSprite + 1;
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
					m_pos.x = _orther->GetRect().left - m_sprite->widthOfSprite;
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
				CMoveMap::g_DistanceMoveCameraY = 600;
			}
			if( m_directCollion == BOTTOM)
			{
				CMoveMap::g_DistanceMoveCameraY = -600;
			}
			break;
		default:
			break;
		}
}

void CRockman::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	CEntity::Render(_spriteHandle, _camera);

	//Update bullet
	for (int i = 0; i < m_listBullet.size(); i++)
	{
		m_listBullet[i]->Render(_spriteHandle, _camera);
	}
}

void CRockman::Shot()
{
	CBullet *bullet = new CBullet(D3DXVECTOR3(m_pos.x, m_pos.y - 20, 0));
	if (m_isTurnLeft)
		bullet->SetVelloc(D3DXVECTOR2(-60,0));
	else
		bullet->SetVelloc(D3DXVECTOR2(60,0));

	m_listBullet.push_back(bullet);
}
