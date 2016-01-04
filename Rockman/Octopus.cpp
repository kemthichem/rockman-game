#include "ResourceManager.h"
#include "Octopus.h"
#include "BulletRockman.h"
#include "Rockman.h"
#include "Define.h"
#define TIME_CONVERT (10.0f)

COctopus::COctopus(int _id, D3DXVECTOR3 _pos, bool _isTurnHor)
{
	m_Id = _id;
	m_Type = OCTOPUS;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES),
		D3DXVECTOR2(910, 296), 3, 1,
		D3DXVECTOR2(670, 260),
		D3DXVECTOR2(0,0),
		D3DXVECTOR2(47,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_velloc.x = _isTurnHor ? -10 : 0;
	m_velloc.y = _isTurnHor ? 0 : 10;
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();

	/**Attribute Octopus**/
	m_TimeSpend = 0;
	m_IsLife = true;
	m_vellocTemp = D3DXVECTOR2(0,0);
}


COctopus::~COctopus(void)
{
}

COctopus::COctopus(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide, bool _isTurnHor)
{
	m_Id = objID;

	m_Type = OCTOPUS;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES),
		D3DXVECTOR2(445, 146), 3, 1,
		D3DXVECTOR2(325, 130),
		D3DXVECTOR2(10, 0),
		D3DXVECTOR2(10, 0));
	m_velloc.x = _isTurnHor ? -10 : 0;
	m_velloc.y = _isTurnHor ? 0 : 10;
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_pos = D3DXVECTOR3(posX - m_Size.x/2, posY + m_Size.y/2, DEPTH_MOTION);

	m_posOrg = m_pos;

	UpdateRect();

	/**Attribute Octopus**/
	m_TimeSpend = 0;
	m_IsLife = true;
	m_vellocTemp = D3DXVECTOR2(0,0);

	m_rangeItem = 3;
}

void COctopus::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity* >_listObjectInViewPort)
{
	if (m_IsLife) {
		bool isUpdate = false;
		D3DXVECTOR3 posRockMan = CRockman::g_PosRockman;
		isUpdate = abs(m_pos.x - posRockMan.x) < 50 || abs(m_pos.y - posRockMan.y) < 50;
		if (isUpdate) {
			if (m_velloc.x == 0 && m_velloc.y == 0) {
				if (m_TimeSpend < TIME_CONVERT) {
					m_TimeSpend += _time;				
				} else {
					m_velloc = m_vellocTemp * -1;
					m_TimeSpend = 0;
				}
			}

			m_Sprite->NextOf(_time, 0, 2);
			CEntity::Update(_time, _camera, _input,_listObjectInViewPort);
		}

	} else {
		//Update item
		CEnemy::Update(_time,_camera,_input,_listObjectInViewPort);
	}
}

void COctopus::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	if (m_IsLife) {
		CEntity::Render(_spriteHandle, _camera);

	} else {
		//Render item
		CEnemy::Render(_spriteHandle, _camera);
	}
}


void COctopus::SetInjured(CEntity* _other)
{
		m_IsCheckCollision = false;
		CreateItem();
		m_IsLife = false;
}

void COctopus::UpdateCollison(CEntity* _other,float _time)
{
	float timeEntry = m_collision->SweptAABB(this,_other,_time);
	m_directCollision = m_collision->GetDirectCollision();
	if (timeEntry < 1.0f)
	{
		ExecuteCollision(_other,m_directCollision,timeEntry);
	}
}

void COctopus::ExecuteCollision(CEntity* _other, DirectCollision m_directCollision, float timeEntry)
{
	//ListObjectColision
	switch (_other->GetType())
	{
	case BLOCK:
		{
			if( m_directCollision == BOTTOM)
			{
				m_pos.y = _other->GetRect().top + m_Size.y + 1;
				m_vellocTemp.y = m_velloc.y;
				m_velloc.y = 0;
			}

			if (m_directCollision == TOP)
			{
				m_pos.y = _other->GetRect().bottom;
				m_vellocTemp.y = m_velloc.y;
				m_velloc.y = 0;
			}

			if( m_directCollision == LEFT)
			{
				m_pos.x = _other->GetRect().right + 1;
				m_vellocTemp.x = m_velloc.x;
				m_velloc.x = 0;
			}

			if( m_directCollision == RIGHT)
			{
				m_pos.x = _other->GetRect().left - m_Size.x - 1;
				m_vellocTemp.x= m_velloc.x;
				m_velloc.x = 0;
			}

		}
		break;
	default:
		break;
	}
}
