#ifndef _GUT_H_
#define _GUT_H_
#include "Entity.h"
#include "Blood.h"
#include "BulletGutsman.h"
#include "ExplosiveBoss.h"

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
	float m_TimeShot;
	CBulletGutsman* m_Bullet;
	int m_yInit;

	CExplosiveBoss* m_Explosive;
	bool m_isExplosive;

	/*Method*/
	void UpdateSprite(float _time);
	void Shot();
	void Jump();
protected:
public:
	CGutsMan(int _id, D3DXVECTOR3 _pos);
	CGutsMan(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide);
	~CGutsMan(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	void SetInjured(CEntity* _other);
	void SetThrow(bool _isThrow);
	void UpdateCollison(CEntity* _other,float _time);
	void ExecuteCollision(CEntity* _other,DirectCollision m_directCollion,float _timeEntry);
};

#endif