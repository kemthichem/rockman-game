#ifndef	_BULLET_CUT_H
#define  _BULLET_CUT_H
#include "Bullet.h"

class CBulletCutman : public CBullet
{
private:
	float m_TimeChange;
	float m_TimeChangeDirect;
	bool m_DesIsCutman;
	D3DXVECTOR3 m_PosCutman;
protected:
	virtual void UpdateCollison(CEntity* ,float);

public:
	CBulletCutman(D3DXVECTOR3 _pos);
	~CBulletCutman(void);

	virtual void Update(float , CCamera *, CInput *, vector<CEntity*>);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	void SetPos(D3DXVECTOR3 _pos);
	void SetPosCutman(D3DXVECTOR3 _posCutman);
	//BulletCutman
};

#endif