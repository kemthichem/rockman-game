#ifndef	 _BULLET_BOMBOMB_H
#define  _BULLET_BOMBOMB_H

#include "Bullet.h"

class CBulletBombomb : public CBullet
{
private:
	long m_timeExplosive;
	bool m_isExplosive;
	D3DXVECTOR2 m_vellocInit;
protected:
	virtual void UpdateCollison(CEntity* ,float);
	virtual	bool IsObtainCollision(CEntity* _other);

	CSprite *m_spriteExplosive;
public:
	CBulletBombomb(D3DXVECTOR3 _pos);
	~CBulletBombomb(void);

	virtual void Update(float , CCamera *, CInput *, vector<CEntity*>);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	void SetPos(D3DXVECTOR3 _pos);
	void SetVellocInit(D3DXVECTOR2);
	//BulletBombomb
};

#endif
