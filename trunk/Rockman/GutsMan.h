#ifndef _GUT_H_
#define _GUT_H_
#include "ResourceManager.h"
#include "Entity.h"
#include "Blood.h"
#include "BulletGutsman.h"

enum GutsStatus {
	GStand,
	GCatchGun,
	GShot,
	GJump
};

class CGutsMan : public CEntity
{
private:
	GutsStatus m_Status;
	CBlood* m_Blood;
	float m_TimeInjured;
	float m_TimeChange;
	CBulletGutsman* m_Bullet;
	int m_yInit;

	/*Method*/
	void UpdateSprite(float _time);
	void Shot();
	void Jump();
protected:
public:
	CGutsMan(int _id, D3DXVECTOR3 _pos);
	~CGutsMan(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE, CCamera*);

	void SetInjured(CEntity* _other);
};

#endif