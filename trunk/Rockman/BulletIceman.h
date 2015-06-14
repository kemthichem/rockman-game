#ifndef	_BULLET_ICEMAN_H
#define  _BULLET_ICEMAN_H

#include "Bullet.h"

class CBulletIceman : public CBullet
{
private:
protected:
	virtual void UpdateCollison(CEntity* ,float);

public:
	CBulletIceman(D3DXVECTOR3 _pos);
	~CBulletIceman(void);

	virtual void Update(float , CCamera *, CInput *, vector<CEntity*>);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	void SetPos(D3DXVECTOR3 _pos);
	//BulletIceman
};

#endif
