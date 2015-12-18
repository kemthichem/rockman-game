#ifndef _CUTMAN_H_
#define _CUTMAN_H_
#include "ResourceManager.h"
#include "Entity.h"
#include "Blood.h"
#include "BulletCutman.h"

enum Status {
	StandNormal,
	StandHaveGun,
	MoveNormal,
	MoveHaveGun,
	JumpNormal,
	JumpHaveGun,
	Shotting
};

class CCutMan : public CEntity
{
private:
	Status m_Status;
	CBlood* m_Blood;
	CBulletCutman *m_Bullet;
	float m_TimeSpend;
	float m_TimeInjured;
	float m_TimeShot;
	int m_yInit;
	bool m_IsJustJump;
	bool m_IsShotting;

	//Method
	void UpdateSprite(float _time);
	void Shot();
	void Jump();
protected:
	virtual void UpdateCollison(CEntity* _other,float _time);
	void ExecuteCollision(CEntity* _other,DirectCollision m_directCollion,float _timeEntry);
public:
	CCutMan(int _id, D3DXVECTOR3 _pos);
	CCutMan(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide);
	~CCutMan(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	void Render(LPD3DXSPRITE _sp, CCamera* _cam);
	void SetInjured(CEntity* _other);

};

#endif