#include "ResourceManager.h"
#include "BoomMan.h"
#include "Rockman.h"
#include "PLayingGameState.h"
#include "Define.h"

#define TIME_INJURED (10.0f)
#define TIME_WAIT (20.0f)

#define VELLOC_X (10.0f)

CBoomMan::CBoomMan(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = ICEMAN;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MASTER), D3DXVECTOR2(870, 480) , 8, 1, D3DXVECTOR2(420, 420));
	m_pos = _pos;	
	m_accel = D3DXVECTOR2(0,0.0f);	

	/*Iceman*/
	m_IsJustJump = false;
	m_Status = STAND;
	m_TimeSpend = 0;
	m_TimeInjured = 0;
	m_isTurnLeft = true;
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_pos.x = CMap::g_widthMap - m_Size.x - 64;
	UpdateRect();
	

	//create blood
	m_Blood = new CBlood(D3DXVECTOR2(740, 30), 100);
}

CBoomMan::CBoomMan(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide)
{

	m_Id = objID;
	m_Type = ICEMAN;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MASTER), D3DXVECTOR2(210, 197) , 7, 1, D3DXVECTOR2(0, 167));

	/*Iceman*/
	m_IsJustJump = false;
	m_Status = STAND;
	m_TimeSpend = 0;
	m_TimeInjured = 0;
	m_isTurnLeft = true;
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_pos = D3DXVECTOR3(posX - m_Size.x / 2, posY + m_Size.y / 2, 0);
	m_accel = D3DXVECTOR2(0, -12.0f);
	//m_pos.x = CMap::g_widthMap - m_Size.x - 64;
	UpdateRect();
	//create list bullet
	
	m_bullet = new CBulletIceman(D3DXVECTOR3(m_pos.x + m_Size.x/2 - 10, m_pos.y - m_Size.y/2 + 10, m_pos.z));

	m_Explosive = new CExplosiveBoss(new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_EXPLOSIVE), D3DXVECTOR2(112, 40), 7, 1, D3DXVECTOR2(0,25)));
	m_isExplosive = false;

	//create blood
	m_Blood = new CBlood(D3DXVECTOR2(WIDTH_SCREEN - 35, 20), 100);
}

CBoomMan::~CBoomMan(void)
{
	if (m_bullet)
	{
		delete m_bullet;
	}

	if (m_Blood)
		delete m_Blood;

	if (m_Explosive) {
		delete m_Explosive;
		m_Explosive = NULL;
	}
}

void CBoomMan::Update(float _time, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	if (m_isExplosive) {m_Explosive->Update(_time, _camera);return;}

	if (m_TimeSpend < TIME_WAIT) {
			m_TimeSpend += _time;
	} else
	{
		Jump();
		m_TimeSpend = 0;
		Shot();
	}
	
	CEntity::Update(_time, _camera, _input, _listObjectInViewPort);

	UpdateSprite(_time);

	if (m_Blood->IsOver()) {
		m_isExplosive = true;
		m_Explosive->Explosive(m_pos, ChangeState::CHANGE_NEXT);
	}

	//Update bullet
	m_bullet->Update(_time, _camera, _input, _listObjectInViewPort);

}

void CBoomMan::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	if (m_isExplosive) {m_Explosive->Render(_spriteHandle, _camera);return;}
	CEntity::RenderEachSprite(_spriteHandle, _camera, m_Sprite, m_pos);

	//Render bullet
	
	m_bullet->Render(_spriteHandle, _camera);
	
	//Render blood
	m_Blood->Render(_spriteHandle, _camera);
}

void CBoomMan::UpdateSprite(float _time)
{
	switch (m_Status)
	{
	case STAND:
		// move normal
		m_Sprite->NextOf(_time, 5, 6);
		break;
	case MOVE:
		// Stand have cut
		m_Sprite->NextOf(_time, 2, 3);
		break;
	case JUMP:
		// Stand have cut
		m_Sprite->IndexOf(1);
		break;
	default:
		break;
	}
}

void CBoomMan::Shot()
{
		for (int i = 0; i < 5; i++)
		{
			if (!m_bullet->GetActive()) {
				m_bullet->SetActive(true);
				int xBullet = m_isTurnLeft ? m_pos.x - m_Size.x / 2: m_pos.x + m_Size.x / 2;
				m_bullet->SetPos(D3DXVECTOR3(xBullet,  m_pos.y - m_Size.y/3 , m_pos.z));
				D3DXVECTOR3 posRockman = CRockman::g_PosRockman;
				float vx = posRockman.x - m_pos.x;

				m_bullet->SetVelloc(D3DXVECTOR2(vx / 9, 40));
				break;
			}
		}
}

void CBoomMan::SetInjured(CEntity* _other)
{
	if (m_TimeInjured == 0) {
		m_Blood->ChangeBlood(-10);
		m_TimeInjured = 0.0000001;
	}
}

void CBoomMan::Jump()
{
	if (m_Status == JUMP) return;
	m_velloc.y = 90.0f;
	m_velloc.x = (m_pos.x - CRockman::g_PosRockman.x) > 0 ? -20 : 20;
	m_Status = JUMP;
}

void CBoomMan::UpdateCollison(CEntity* _other,float _time)
{
	switch (_other->GetType())
	{
	case ROCKMAN:
		(dynamic_cast<CRockman*>(_other))->SetInjured(this, -20);
		break;
	case BLOCK:
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

void CBoomMan::ExecuteCollision(CEntity* _other,DirectCollision m_directCollion,float _timeEntry)
{
	if( m_directCollion == BOTTOM)
	{
		m_pos.y = _other->GetRect().top + m_Size.y + 1;
		m_velloc.y = 0;
		m_Status = STAND;
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
