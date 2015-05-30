#include "ScrewBomber.h"
#define TIME_CONVERT (20.0f)
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
	for (int i = 0; i < NUM_BULLET; i++)
	{
		CBullet *bullet = new CBullet(D3DXVECTOR3(_pos.x + m_Size.x/2 - 10, _pos.y - m_Size.y/2 + 10, _pos.z));
		switch (i % (NUM_BULLET/2))
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
	for(int i = 0; i < NUM_BULLET; ++i)
		delete m_ListBullet[i];
	//delete []m_ListBullet;
}


void CScrewBomber::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity* >_listObjectInViewPort)
{
	if (m_TimeSpend < TIME_CONVERT) {
		m_TimeSpend += _time;
		if ((int)m_TimeSpend == (int)TIME_CONVERT/2 && m_Status == Rotate) {
			Shot(2);
		}
	} else {
		m_TimeSpend = 0;
		if (m_Status == Wait) {
			m_Status = Rotate;			
			Shot(1);
		} else //ROTATE
		{			
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

	//Update bullet
	for(int i = 0; i < NUM_BULLET; ++i) {
		m_ListBullet[i]->Update(_time,_camera,_input,_listObjectInViewPort);
	}		
}

void CScrewBomber::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	CEntity::Render(_spriteHandle, _camera);

	//Render bullet
	for (int i = 0; i < NUM_BULLET; ++i)
	{
		m_ListBullet[i]->Render(_spriteHandle, _camera);
	}
}

void CScrewBomber::Shot(int _n)
{
	for(int i = (_n-1) * NUM_BULLET/2; i < _n * NUM_BULLET/2; ++i) {
		m_ListBullet[i]->SetActive(true);
	}
}