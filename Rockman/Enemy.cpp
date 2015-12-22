#include "Enemy.h"
#include "ResourceManager.h"
#include "Config.h"

CEnemy::CEnemy(void)
{
	m_posOrg = D3DXVECTOR3(0,0,0);
	m_timeExplosive = CConfig::ValueOf(KEY_EN_TIMEEXPLOSIVE);
	m_spriteExplosive = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_EXPLOSIVE), D3DXVECTOR2(112, 40), 7, 1, D3DXVECTOR2(0,24));
	m_IsLife = m_IsCheckCollision = true;
}


CEnemy::~CEnemy(void)
{
	if (m_spriteExplosive) {
		delete m_spriteExplosive;
		m_spriteExplosive = NULL;
	}
}

void CEnemy::Reset()
{
	m_timeExplosive = CConfig::ValueOf(KEY_EN_TIMEEXPLOSIVE);
	m_pos = m_posOrg;
	m_IsLife = m_IsCheckCollision = m_IsShowed = true;
}

void CEnemy::Update(float _time, CCamera * _camare, CInput* _input, vector<CEntity*> _listOb)
{
	if (m_timeExplosive > 0) {
		m_spriteExplosive->Next(_time);
		m_timeExplosive -= _time;
	} else
	{
		m_IsShowed = false;
	}
}

void CEnemy::Render(LPD3DXSPRITE _spHandle, CCamera* _camera)
{
	if (m_timeExplosive > 0) {
		CEntity::RenderEachSprite(_spHandle, _camera, m_spriteExplosive, m_pos);
	}
}
