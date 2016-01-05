#ifndef	_BULLET_GUT_H
#define  _BULLET_GUT_H

#include "Bullet.h"

class CBulletGutsman : public CBullet
{
private:
	void Throw(CEntity* _other);
protected:
	virtual void UpdateCollison(CEntity* ,float);
	virtual bool IsObtainCollision(CEntity* _other);
public:
	CBulletGutsman(D3DXVECTOR3 _pos);
	~CBulletGutsman(void);

	virtual void Update(float , CCamera *, CInput *, vector<CEntity*>);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	void SetPos(D3DXVECTOR3 _pos);
	//BulletGustman
};

#endif
