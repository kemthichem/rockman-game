#ifndef _BEAK_H_
#define _BEAK_H_
#include "Enemy.h"
#include "Bullet.h"


#define NUM_BULLET (10)

enum BeakrStatus {
	BeakWait,
	BeakShot
};

class CBeak : public CEnemy
{
private:
	CBullet *m_ListBullet[NUM_BULLET];
	BeakrStatus m_Status;
	float m_TimeSpent;
	float m_TimeShot;
	void Shot();
	int m_CurrentBullet;

protected:
	virtual void Reset();
public:
	CBeak(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide, bool _isLeft = true);

	CBeak(int _id, D3DXVECTOR3 _pos, bool _isLeft = true);
	~CBeak(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera);
	void SetInjured(CEntity* _other);
};

#endif