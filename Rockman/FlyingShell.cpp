#include "FlyingShell.h"
#include "ResourceManager.h"
#include "Define.h"

#define TIME_CHANGE (20.0f)
#define TIME_SHOT (15.0f)
#define V_BULLET (14.0f)



CFlyingShell::CFlyingShell(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = MET;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(830, 50) , 2, 1, D3DXVECTOR2(670,20), D3DXVECTOR2(0,0), D3DXVECTOR2(40,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();
}

CFlyingShell::CFlyingShell(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide)
{
	m_Id = objID;

	m_Type = FLYING_SHELL;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(335, 110) , 2, 1, D3DXVECTOR2(255, 90), D3DXVECTOR2(0, 0), D3DXVECTOR2(20, 0));
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_pos = D3DXVECTOR3(posX - m_Size.x/2, posY + m_Size.y/2, DEPTH_MOTION);
	m_posOrg = m_pos;

	m_IsLife = true;
	m_TimeSpent = m_TimeShot = 0;
	m_CurrentBullet = 0;
	m_isTurnLeft = true;

	m_Status = FlyShellWait;

	UpdateRect();

#pragma region create list bullet

	int vx = -V_BULLET;
	int vy = 0;
	for (int i = 0; i < NUM_BULLET; i++)
	{
		CBullet *bullet = new CBullet(D3DXVECTOR3(m_pos.x + m_Size.x/2, m_pos.y, m_pos.z));
		switch (i)
		{
		case 0:
			vx = 0;
			vy = V_BULLET;
			break;
		case 1:
			vx = -V_BULLET;
			vy =  V_BULLET;
			break;
		case 2:
			vx = -V_BULLET;
			vy = 0;
			break;
		case 3:
			vx = -V_BULLET;
			vy = -V_BULLET;
			break;
		case 4:
			vx = 0;
			vy = -V_BULLET;
			break;
		case 5:
			vx = V_BULLET; 
			vy =  -V_BULLET;
			break;
		case 6:
			vx = V_BULLET;
			vy = 0;
			break;
		case 7:
			vx = V_BULLET ;
			vy = V_BULLET;
			break;
		default:
			break;
		}
		bullet->SetVelloc(D3DXVECTOR2(vx, vy));
		m_ListBullet[i] = bullet;
	}

#pragma endregion

}


CFlyingShell::~CFlyingShell(void)
{
}

void CFlyingShell::Update(float _time, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	float timeChange = m_Status == FlyShellWait ? TIME_CHANGE/2 : TIME_CHANGE;

	if (m_IsLife) {
		if (m_TimeSpent < timeChange) {
			m_TimeSpent += _time;
		} else {
			m_TimeSpent = 0;
			//Change status
			m_Status = m_Status == FlyShellWait ? FlyShellShot : FlyShellWait;
		}

		if (m_Status == FlyShellShot) {
			m_velloc.x = 0;
			if (m_TimeShot < TIME_SHOT) {
				m_TimeShot += _time;
			} else {
				m_TimeShot = 0;
				Shot();
			}
		} else
		{
			m_velloc.x = -6;
		}

		CEntity::Update(_time, _camera, NULL, _listObjectInViewPort);

		switch (m_Status)
		{
		case FlyShellWait:
			m_Sprite->IndexOf(0);	
			break;
		case FlyShellShot:
			m_Sprite->NextOf(_time, 0, 1);	
			break;
		default:
			break;
		}
		//Update bullet
		for(int i = 0; i < NUM_BULLET; ++i) {
			m_ListBullet[i]->Update(_time,_camera,_input,_listObjectInViewPort);
		}		
	} else {
		CEnemy::Update(_time, _camera, _input, _listObjectInViewPort);
		//m_Item->Update(_time,_camera,_input,_listObjectInViewPort);
	}
}

void CFlyingShell::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	if (m_IsLife) {
		CEntity::Render(_spriteHandle, _camera);

		//Render bullet
		for (int i = 0; i < NUM_BULLET; ++i)
		{
			m_ListBullet[i]->Render(_spriteHandle, _camera);
		}
	} else {
		//Render item
		CEnemy::Render(_spriteHandle, _camera);
		//m_Item->Render(_spriteHandle, _camera);
		//if (!m_Item->GetActive())
		//	m_IsShowed = false;
	}
}

void CFlyingShell::Shot()
{
	/*if (!m_ListBullet[m_CurrentBullet]->GetActive())
		m_ListBullet[m_CurrentBullet]->SetActive(true);
	m_CurrentBullet++;
	if (m_CurrentBullet == NUM_BULLET) m_CurrentBullet = 0;*/

	for (int i = 0; i < NUM_BULLET; i++)
	{
		if (!m_ListBullet[i]->GetActive()) {
			m_ListBullet[i]->SetActive(true);
			m_ListBullet[i]->SetPos(D3DXVECTOR2(m_pos.x + m_Size.x / 2, m_pos.y - m_Size.y /2));
		}
	}
}

void CFlyingShell::SetInjured(CEntity* _other)
{
	if (m_Status == FlyShellShot) {
		m_IsCheckCollision = false;
		m_IsLife = false;

		CreateItem();
	}
}

void CFlyingShell::Reset()
{
	CEnemy::Reset();
	for (int i = 0; i < NUM_BULLET; i++)
	{
		m_ListBullet[i]->SetActive(false);
	}

	UpdateRect();
}


