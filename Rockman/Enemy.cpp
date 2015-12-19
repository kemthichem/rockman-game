#include "Enemy.h"


CEnemy::CEnemy(void)
{
	m_posOrg = D3DXVECTOR3(0,0,0);
}


CEnemy::~CEnemy(void)
{
}

void CEnemy::Reset()
{
	m_pos = m_posOrg;
	m_IsLife = m_IsCheckCollision = true;
}
