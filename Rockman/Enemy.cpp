#include "Enemy.h"
#include "ResourceManager.h"
#include "Config.h"


#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


CEnemy::CEnemy(void)
{
	m_posOrg = D3DXVECTOR3(0,0,0);
	m_timeExplosive = CConfig::ValueOf(KEY_EN_TIMEEXPLOSIVE);
	m_spriteExplosive = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_EXPLOSIVE), D3DXVECTOR2(112, 40), 7, 1, D3DXVECTOR2(0,25));
	m_spriteExplosive->IndexOf(3);
	m_IsLife = m_IsCheckCollision = true;

	m_rangeItem = 1;
}


CEnemy::~CEnemy(void)
{
	if (m_spriteExplosive) {
		delete m_spriteExplosive;
		m_spriteExplosive = NULL;
	}

	if (m_item) {
		delete m_item;
		m_item = NULL;
	}
}

void CEnemy::Reset()
{
	m_spriteExplosive->IndexOf(3);
	m_timeExplosive = CConfig::ValueOf(KEY_EN_TIMEEXPLOSIVE);
	m_pos = m_posOrg;
	m_IsLife = m_IsCheckCollision = m_IsShowed = true;

	if (m_item) {
		delete m_item;
		m_item = NULL;
	}
}

void CEnemy::Update(float _time, CCamera * _camera, CInput* _input, vector<CEntity*> _listOb)
{
	if (m_timeExplosive > 0) {
		m_spriteExplosive->Next(_time);
		m_timeExplosive -= _time;
	}

	if (m_item) {
		m_item->Update(_time,_camera,_input,_listOb);

		if (!m_item->GetActive()) {
			m_timeExplosive = 0;
			m_IsShowed = false;
		}
	}
}

void CEnemy::Render(LPD3DXSPRITE _spHandle, CCamera* _camera)
{
	if (m_IsLife) {
		CEntity::Render(_spHandle, _camera);
	} else
	{
		if (m_timeExplosive > 0) {
			CEntity::RenderEachSprite(_spHandle, _camera, m_spriteExplosive, m_pos);
		}

		if (m_item) {
			m_item->Render(_spHandle,_camera);
		}

	}
}

void CEnemy::CreateItem()
{
	if (m_item) {
		delete m_item;
		m_item = NULL;
	}

	srand (time(NULL));
	int iType = (rand() % m_rangeItem + 1);
	if (iType != 0) {
		m_item = new CItem(m_pos, Type(iType));
	} else
	{
		m_item = NULL;
	}
}

void CEnemy::SetInjured(CEntity* _other)
{
	m_IsCheckCollision = false;
	m_IsLife = false;

	CreateItem();
}

void CEnemy::GetRectInit(RECT &r)
{
	r.left = m_posOrg.x;
	r.top = m_posOrg.y;
	r.right = m_posOrg.x + m_Size.x;
	r.bottom = m_posOrg.y - m_Size.y;
}
