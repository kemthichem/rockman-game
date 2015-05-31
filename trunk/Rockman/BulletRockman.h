#ifndef	_BULLET_ROCKMAN_H
#define  _BULLET_ROCKMAN_H

#include "Bullet.h"

class CBulletRockman : public CBullet
{
protected:
	virtual void UpdateCollison(CEntity* ,float);

public:
	CBulletRockman(D3DXVECTOR3 _pos);
	~CBulletRockman(void);

	virtual void Update(float , CCamera *, CInput *, vector<CEntity*>);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	void SetPos(D3DXVECTOR3 _pos);
	//BulletRockman
};

#endif
