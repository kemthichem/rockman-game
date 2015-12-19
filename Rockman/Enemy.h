#ifndef ENEMY_H_
#define  ENEMY_H_
#include "Entity.h"

class CEnemy : public CEntity
{
protected:
	bool m_IsLife;
	D3DXVECTOR3 m_posOrg;
public:
	virtual void Reset();
	CEnemy(void);
	virtual ~CEnemy(void);
};
#endif // !ENEMY_H_
