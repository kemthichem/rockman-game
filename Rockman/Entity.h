#ifndef ENTITY_H_
#define ENTITY_H_

#include "Sprite.h"
#include "Camera.h"
#include "Input.h"

class CEntity
{
private:
	bool mIsTurnLeft;
protected:
	D3DXVECTOR2 mVeloc;
	D3DXVECTOR2 mAccel;
	D3DXVECTOR3 mPos;
	RECT mRect;
	CSprite *mSprite;
public:
	virtual void Update(DWORD , CCamera *, CInput *);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	CEntity(void);
	~CEntity(void);
};

#endif