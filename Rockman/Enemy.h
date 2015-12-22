#ifndef ENEMY_H_
#define  ENEMY_H_
#include "Entity.h"

class CEnemy : public CEntity
{
private:
	long m_timeExplosive;
protected:
	bool m_IsLife;
	D3DXVECTOR3 m_posOrg;
	CSprite *m_spriteExplosive;
public:
	virtual void Reset();
	CEnemy(void);
	virtual ~CEnemy(void);

	virtual void Update(float _time, CCamera * _camare, CInput* _input, vector<CEntity*> _listOb);
	virtual void Render(LPD3DXSPRITE _spHandle, CCamera* _camera);
};
#endif // !ENEMY_H_
