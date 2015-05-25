#ifndef  _SCREW_BOMBER_H
#define  _SCREW_BOMBER_H
#include "ResourceManager.h"
#include "Entity.h"
#include "Bullet.h"

enum ScrewBomberStatus {
	Wait,
	Rotate
};

class CScrewBomber : public CEntity
{
private:
	ScrewBomberStatus m_Status;
	CBullet *m_ListBullet[10];
	float  m_TimeSpend;
public:
	CScrewBomber(int _id, D3DXVECTOR3 _pos);
	~CScrewBomber(void);

	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE, CCamera*);
};
#endif
