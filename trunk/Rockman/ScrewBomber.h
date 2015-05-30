#ifndef  _SCREW_BOMBER_H
#define  _SCREW_BOMBER_H
#include "ResourceManager.h"
#include "Entity.h"
#include "Bullet.h"

#define NUM_BULLET (10)

enum ScrewBomberStatus {
	Wait,
	Rotate
};

class CScrewBomber : public CEntity
{
private:
	ScrewBomberStatus m_Status;
	CBullet *m_ListBullet[NUM_BULLET];
	float  m_TimeSpend;

	void Shot(int _n);
public:
	CScrewBomber(int _id, D3DXVECTOR3 _pos);
	~CScrewBomber(void);

	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE, CCamera*);
};
#endif
