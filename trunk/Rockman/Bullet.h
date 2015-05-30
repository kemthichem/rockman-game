#ifndef	_BULLET_H
#define  _BULLET_H

#include "Entity.h"

class CBullet : public CEntity
{
private:
	bool m_IsActive;
	D3DXVECTOR3 m_posInit;

public:
	CBullet(D3DXVECTOR3 _pos);
	~CBullet(void);
	virtual void Update(float , CCamera *, CInput *, vector<CEntity*>);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	void UpdateCollison(CEntity* ,float);
	void SetVelloc(D3DXVECTOR2 _velloc);
	void SetActive(bool _isActive);
};

#endif