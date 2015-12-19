#ifndef  _SCREW_BOMBER_H
#define  _SCREW_BOMBER_H
#include "Entity.h"
#include "Bullet.h"
#include "Item.h"

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
	CItem *m_Item;
	float  m_TimeSpend;
	bool m_IsLife;

	void Shot(int _n);
public:
	CScrewBomber(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide, bool _isUp = true);

	CScrewBomber(int _id, D3DXVECTOR3 _pos, bool _isUp = true);
	~CScrewBomber(void);

	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	void SetInjured(CEntity* _other);
};
#endif
