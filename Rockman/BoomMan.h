#ifndef _BOOMMAN_H_
#define _BOOMMAN_H_
#include "Entity.h"
#include "Blood.h"
#include "BulletIceman.h"
#include "ExplosiveBoss.h"

enum IceManStatus {
	HELLO,
	STAND,
	MOVE,
	JUMP
};

class CBoomMan : public CEntity
{
private:
	IceManStatus m_Status;
	float m_TimeSpend;
	float m_TimeInjured;
	CBlood* m_Blood;
	CBulletIceman* m_ListBullet[5];
	int m_yInit;
	bool m_IsJustJump;
	int m_yShot;
	bool m_IsHello;

	CExplosiveBoss* m_Explosive;
	bool m_isExplosive;

	/*Method*/
	void UpdateSprite(float _time);
	void Shot();
	void Jump();
protected:
	virtual void UpdateCollison(CEntity* _other,float _time);
public:
	CBoomMan(int _id, D3DXVECTOR3 _pos);
	CBoomMan(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide);
	~CBoomMan(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE _sp, CCamera* _cam);
	void SetInjured(CEntity* _other);
	void ExecuteCollision(CEntity* _other,DirectCollision m_directCollion,float _timeEntry);
};

#endif