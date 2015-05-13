#ifndef ENTITY_H_
#define ENTITY_H_

#include "Sprite.h"
#include "Camera.h"
#include "Input.h"

class CEntity
{
private:
	bool m_isTurnLeft;
	void UpdatePosition(float);
	 
protected:
	D3DXVECTOR2 m_veloc;
	D3DXVECTOR2 m_accel;
	D3DXVECTOR3 m_pos;
	RECT mRect;
	CSprite *m_sprite;
public:
	virtual void Update(float , CCamera *, CInput *);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	CEntity(void);
	~CEntity(void);
};

#endif