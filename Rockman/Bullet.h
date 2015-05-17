#ifndef	_BULLET_H
#define  _BULLET_H

#include "Entity.h"

class CBullet : public CEntity
{
private:

public:
	CBullet(D3DXVECTOR3 _pos);
	~CBullet(void);
	virtual void Update(float , CCamera *, CInput *, vector<CEntity*>);
	void UpdateCollison(CEntity* ,float);
	void SetVelloc(D3DXVECTOR2 _velloc);
};

#endif
