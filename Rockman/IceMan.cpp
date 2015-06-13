#include "IceMan.h"
#define WAITING_TIME (20.0f)



CIceMan::CIceMan(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = ICEMAN;
	m_Status = HELLO;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MASTER), D3DXVECTOR2(870, 480) , 8, 1, D3DXVECTOR2(420, 420));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_velloc.x = 0.0f;
	m_accel.y = 0.0f;
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());

	UpdateRect();
}


CIceMan::~CIceMan(void)
{
}

void CIceMan::Update(float _time, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	//CEntity::Update(_time, _camera, _input, _listObjectInViewPort);

	if (m_pos.x < 0 || m_pos.x > 800) {
		m_velloc.x *= -1;
	}

	//if( m_pos.y <= 135){
	//	m_veloc.y = 80.0f;
	//}

	if (m_TimeSpend < WAITING_TIME) {
			m_TimeSpend += _time;
			if ((int)m_TimeSpend == (int)WAITING_TIME && m_Status == HELLO) {
				m_Status = STAND;
			}
	}


	m_velloc.x = 0;
	m_velloc.y = 0;

	switch (m_Status)
	{
	case HELLO:
		// stand normal
		m_Sprite->NextOf(_time, 4, 5);
		break;
	case STAND:
		// move normal
		m_Sprite->IndexOf(7);
		break;
	case MOVE:
		// Stand have cut
		m_Sprite->NextOf(_time, 2, 3);
		break;
	case JUMP:
		// Stand have cut
		m_Sprite->IndexOf(6);
		break;
	default:
		break;
	}



	
}

void CIceMan::Draw()
{

}

void CIceMan::Collision()
{

}
