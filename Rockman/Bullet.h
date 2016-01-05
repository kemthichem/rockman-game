#ifndef	_BULLET_H
#define  _BULLET_H

#include "Entity.h"

//Bullet for enemies
class CBullet : public CEntity
{
private:	
	D3DXVECTOR3 m_posInit;

protected:
	bool m_IsActive;
	virtual void UpdateCollison(CEntity* ,float);
	virtual bool IsObtainCollision(CEntity* _other);
public:
	CBullet();
	CBullet(D3DXVECTOR3 _pos);
	~CBullet(void);

	virtual void Update(float , CCamera *, CInput *, vector<CEntity*>);
	virtual void Render(LPD3DXSPRITE, CCamera*);

	//Bullet
	void SetVelloc(D3DXVECTOR2 _velloc);
	void SetActive(bool _isActive);
	bool GetActive() {
		return m_IsActive;
	}
	void SetPos(D3DXVECTOR2 _pos);
};

#endif
