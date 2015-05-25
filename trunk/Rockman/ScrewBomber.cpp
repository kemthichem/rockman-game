#include "ScrewBomber.h"
#define TIME_CONVERT (30.0f)
#define V_BULLET (50.0f)

CScrewBomber::CScrewBomber(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = SCREW_BOMBER;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES),
		D3DXVECTOR2(350,215), 4, 1,
		D3DXVECTOR2(30,180),
		D3DXVECTOR2(0,0),
		D3DXVECTOR2(45,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());

	/**Attribute ScrewBomber**/
	m_Status = Wait;
	m_TimeSpend = 0;

	//Create list bullet
	int vx = -V_BULLET;
	int vy = 0;
	for (int i = 0; i < 10; i++)
	{
		CBullet *bullet = new CBullet(D3DXVECTOR3(_pos.x + m_Size.x/2 - 10, _pos.y - m_Size.y/2 + 10, _pos.z));
		switch (i%5)
		{
		case 0:
			vx = -V_BULLET;
			vy = 0;
			break;
		case 1:
			vx = -V_BULLET;
			vy = -V_BULLET;
			break;
		case 2:
			vx = -0;
			vy = -V_BULLET;
			break;
		case 3:
			vx = V_BULLET;
			vy = -V_BULLET;
			break;
		case 4:
			vx = V_BULLET;
			vy = 0;
			break;
		default:
			break;
		}
		bullet->SetVelloc(D3DXVECTOR2(vx, vy));

		m_ListBullet[i] = bullet;
	}
}


CScrewBomber::~CScrewBomber(void)
{
	for(int i = 0; i < 10; ++i)
		delete m_ListBullet[i];
	//delete []m_ListBullet;
}


void CScrewBomber::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity* >_listObjectInViewPort)
{
	if (m_TimeSpend < TIME_CONVERT) {
		m_TimeSpend += _time;
	} else {

		m_TimeSpend = 0;
		if (m_Status == Wait) {
			m_Status = Rotate;
			for(int i = 0; i < 5; ++i) {
				m_ListBullet[i]->SetActive(true);
			}
		} else
		{
			for(int i = 5; i < 10; ++i) {
				m_ListBullet[i]->SetActive(true);
			}
			m_Status = Wait;
		}

		
	}

	switch (m_Status)
	{
	case Wait:
		m_Sprite->IndexOf(0);	
		break;
	case Rotate:
		m_Sprite->NextOf(_time, 1, 3);	
		break;
	default:
		break;
	}

	if (m_Status == Rotate) {
	//	CBullet *bullet = new CBullet(m_pos);
		//m_ListBullet.push_back(bullet);
	}


	//Update bullet
	for(int i = 0; i < 10; ++i) {
		m_ListBullet[i]->Update(_time,_camera,_input,_listObjectInViewPort);
	}		
}

void CScrewBomber::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	CEntity::Render(_spriteHandle, _camera);

	//Render bullet
	for (int i = 0; i < 10; ++i)
	{
		m_ListBullet[i]->Render(_spriteHandle, _camera);
	}
}
