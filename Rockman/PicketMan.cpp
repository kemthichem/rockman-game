#include "PicketMan.h"
#include "ResourceManager.h"
#include "BulletRockman.h"
#include "Define.h"
#define TIME_CONVERT (10.0f)



CPicketMan::~CPicketMan(void)
{
}

CPicketMan::CPicketMan(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide, bool _isTurnHor)
{
	m_Id = objID;

	m_Type = PICKETMAN;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES),
		D3DXVECTOR2(450, 71), 3, 1,
		D3DXVECTOR2(335, 46),
		D3DXVECTOR2(0, 0),
		D3DXVECTOR2(10, 0));

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

void CPicketMan::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity* >_listObjectInViewPort)
{
	if (m_IsLife) {
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

	} else {
		//Update item
		CEnemy::Update(_time,_camera,_input,_listObjectInViewPort);
	}
}

void CPicketMan::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	if (m_IsLife) {
		CEntity::Render(_spriteHandle, _camera);

	} else {
		//Render item
		CEnemy::Render(_spriteHandle, _camera);
	}
}


void CPicketMan::SetInjured(CEntity* _other)
{
	m_IsCheckCollision = false;
	CreateItem();
	m_IsLife = false;
}

void CPicketMan::UpdateCollison(CEntity* _other,float _time)
{
	float timeEntry = m_collision->SweptAABB(this,_other,_time);
	m_directCollision = m_collision->GetDirectCollision();
	if (timeEntry < 1.0f)
	{
		ExecuteCollision(_other,m_directCollision,timeEntry);
	}
}

void CPicketMan::ExecuteCollision(CEntity* _other, DirectCollision m_directCollision, float timeEntry)
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
