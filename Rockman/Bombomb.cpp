#include "Bombomb.h"
#include "ResourceManager.h"
#include "Define.h"

#define TIME_CHANGE (20.0f)
#define TIME_SHOT (4.0f)
#define V_BULLET (13.0f)

CBombomb::CBombomb(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide, bool _isLeft)
{
	m_Id = objID;
	m_Type = BOMBOMB;
	m_IsLife = true;
	m_TimeSpent = 0;
	m_isTurnLeft = _isLeft;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(212, 385) , 1, 1, D3DXVECTOR2(195, 372));
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_pos = D3DXVECTOR3(posX - m_Size.x/2, posY + m_Size.y, DEPTH_MOTION);
	m_posOrg = m_pos;
	m_rangeItem = 3;

	UpdateRect();

#pragma region create list bullet

	int vx = -V_BULLET;
	int vy = 0;
	int dir = _isLeft ? 1 : -1;
	for (int i = 0; i < NUM_BULLET; i++)
	{
		CBulletBombomb *bullet = new CBulletBombomb(D3DXVECTOR3(m_pos.x + m_Size.x/2 - dir * m_Size.x/2, m_pos.y - m_Size.y/2, m_pos.z));
		switch (i)
		{
		case 0:
			vx = -V_BULLET * 0.6 * dir;
			vy = V_BULLET * dir;
			break;
		case 1:
			vx = -V_BULLET * 1.4 * dir;
			vy =  V_BULLET * dir;
			break;
		case 2:
			vx = V_BULLET * 0.6 *dir;
			vy = V_BULLET *dir;
			break;
		case 3:
			vx = V_BULLET * 1.4 *dir;
			vy = V_BULLET *dir;
			break;
		default:
			break;
		}
		bullet->SetVelloc(D3DXVECTOR2(vx, vy));
		bullet->SetVellocInit(D3DXVECTOR2(vx, vy));
		bullet->SetAccel(D3DXVECTOR2(0, -10.0));
		m_ListBullet[i] = bullet;
	}

#pragma endregion
}

CBombomb::~CBombomb(void)
{

}

void CBombomb::Update(float _time, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{	
	if (m_IsLife) {
		m_pos.y += 5;
		UpdateRect();

		if (m_pos.y - m_posOrg.y > 150) {
			Shot();
			m_TimeSpent = 15;
			m_IsLife = false;
		}
	} else {
		CEnemy::Update(_time, _camera, _input, _listObjectInViewPort);
		//m_Item->Update(_time,_camera,_input,_listObjectInViewPort);
		if (m_TimeSpent > 0) {
			m_TimeSpent -= _time;
		} else {
			Reset();
		}

		//Render bullet
		for (int i = 0; i < NUM_BULLET; ++i)
		{
			if (m_ListBullet[i]->GetActive())
				m_ListBullet[i]->Update(_time, _camera, _input, _listObjectInViewPort);
		}
	}

	
}

void CBombomb::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	if (m_IsLife) {
		CEntity::Render(_spriteHandle, _camera);
	} else {
		//Render item
		CEnemy::Render(_spriteHandle, _camera);

		//Render bullet
		for (int i = 0; i < NUM_BULLET; ++i)
		{
			if (m_ListBullet[i]->GetActive())
				m_ListBullet[i]->Render(_spriteHandle, _camera);
		}
	}
}

void CBombomb::Shot()
{
	D3DXVECTOR3 pos(0,0,0);
	for (int i = 0; i < NUM_BULLET; i++)
	{
		pos.x = m_pos.x + m_Size.x /2;
		pos.y = m_pos.y;
		m_ListBullet[i]->SetPos(pos);
		m_ListBullet[i]->SetActive(true);
	}
}

void CBombomb::SetInjured(CEntity* _other)
{
}

void CBombomb::Reset()
{
	CEnemy::Reset();
	for (int i = 0; i < NUM_BULLET; i++)
	{
		m_ListBullet[i]->SetActive(false);
	}

	m_TimeSpent = 0;
}

