#include "IceMan.h"
#include "Rockman.h"
#include "PLayingGameState.h"

#define WAITING_TIME (50.0f)

#define VELLOC_X (10.0f)

CIceMan::CIceMan(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = ICEMAN;
	m_Status = HELLO;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MASTER), D3DXVECTOR2(870, 480) , 8, 1, D3DXVECTOR2(420, 420));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());

	UpdateRect();

	/*Iceman*/
	m_Status = HELLO;
	m_TimeSpend = 0;
	//create list bullet
	for (int i = 0; i < 5; i++)
	{
		CBulletIceman *bullet = new CBulletIceman(D3DXVECTOR3(_pos.x + m_Size.x/2 - 10, _pos.y - m_Size.y/2 + 10, _pos.z));
		m_ListBullet[i] = bullet;
	}

	//create blood
	m_Blood = new CBlood(D3DXVECTOR2(740, 30), 100);
}


CIceMan::~CIceMan(void)
{
	for (int i = 0; i < 5; i++)
	{
		delete m_ListBullet[i];
	}

	if (m_Blood)
		delete m_Blood;
}

void CIceMan::Update(float _time, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	if (m_TimeSpend < WAITING_TIME) {
			m_TimeSpend += _time;
			m_velloc.x = m_pos.x > CRockman::g_PosRockman.x ? -VELLOC_X : VELLOC_X;
	} else
	{
		m_TimeSpend = 0;
		Shot();
	}
	CEntity::Update(_time, _camera, _input, _listObjectInViewPort);
	UpdateSprite(_time);

	if (m_Blood->IsOver())
		CPLayingGameState::g_ChangeState = ChangeState::CHANGE_NEXT;
	//Update bullet
	for (int i = 0; i < 5; i++)
	{
		m_ListBullet[i]->Update(_time, _camera, _input, _listObjectInViewPort);
	}
}

void CIceMan::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	CEntity::RenderEachSprite(_spriteHandle, _camera, m_Sprite, m_pos);

	//Render bullet
	for (int i = 0; i < 5; i++)
	{
		m_ListBullet[i]->Render(_spriteHandle, _camera);
	}
	//Render blood
	m_Blood->Render(_spriteHandle, _camera);
}

void CIceMan::UpdateSprite(float _time)
{
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

void CIceMan::Shot()
{
		for (int i = 0; i < 5; i++)
		{
			if (!m_ListBullet[i]->GetActive()) {
				m_ListBullet[i]->SetActive(true);
				m_ListBullet[i]->SetPos(D3DXVECTOR3(m_pos.x + m_Size.x/2 - 10 + i * 80, m_pos.y - m_Size.y/2 + i * 50, m_pos.z));
				m_ListBullet[i]->SetVelloc(D3DXVECTOR2(m_isTurnLeft ? -15 : 15, 0));
			}
		}
}

void CIceMan::SetInjured(CEntity* _other)
{
	//if (m_Injuring != 0) return;
	//m_Injuring = _other->GetVelocity().x > 0 ? 1 : -1;
	m_Blood->ChangeBlood(-10);
}
