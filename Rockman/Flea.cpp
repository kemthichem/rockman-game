#include "ResourceManager.h"
#include "Flea.h"
#include "Define.h"

CFlea::CFlea(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = FLEA;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(663, 296) , 2, 1, D3DXVECTOR2(513,258), D3DXVECTOR2(0,0), D3DXVECTOR2(43,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_velloc.x = -10;
	m_accel.y = -5.0f;

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();
}

CFlea::CFlea(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide)
{
	m_Id = objID;
	m_Type = FLEA;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(335, 190) , 2, 1, D3DXVECTOR2(255, 170), D3DXVECTOR2(0,0), D3DXVECTOR2(20,0));
	m_pos = D3DXVECTOR3(posX - m_Size.x/2, posY + m_Size.y/2, DEPTH_MOTION);
	m_accel = D3DXVECTOR2(0,0);
	m_velloc.x = -10;
	m_accel.y = -5.0f;

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();

}

CFlea::~CFlea(void)
{
}

void CFlea::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	CEntity::Update(_deltaTime, _camera, _input, _listObjectInViewPort);

	if(m_velloc.y > 14.0f){
		m_Sprite ->IndexOf(1);
	}else{
		m_Sprite ->IndexOf(0);
	}
}
void CFlea::UpdateCollison(CEntity* _other,float _time)
{
	switch (_other->GetType())
	{
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

void CFlea::ExecuteCollision(CEntity* _other,DirectCollision m_directCollion,float _timeEntry)
{
	if( m_directCollion == BOTTOM)
	{
		m_pos.y = _other->GetRect().top + m_Size.y + 1;
		m_velloc.y = 25.0f;
	}

	if( m_directCollion == LEFT)
	{
		m_velloc.x *= -1;
		m_accel.x = 0;
		m_pos.x = _other->GetRect().right + 1 ;
	}

	if( m_directCollion == RIGHT)
	{
		m_velloc.x *= -1;
		m_accel.x = 0;
		m_pos.x = _other->GetRect().left - m_Size.x -1;
	}

	if (m_directCollion == TOP)
	{
		m_pos.y = _other->GetRect().bottom;
		m_velloc.y = 0;
	}
}
