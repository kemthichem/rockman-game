#ifndef _Bombomb_H_
#define _Bombomb_H_
#include "Enemy.h"
#include "BulletBombomb.h"


#define NUM_BULLET (4)

class CBombomb : public CEnemy
{
private:
	CBulletBombomb *m_ListBullet[NUM_BULLET];
	float m_TimeSpent;
	void Shot();
protected:
	virtual void Reset();
public:
	CBombomb(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide, bool _isLeft = true);
	~CBombomb(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera);
	void SetInjured(CEntity* _other);
};

#endif