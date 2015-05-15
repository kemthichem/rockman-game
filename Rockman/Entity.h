#ifndef ENTITY_H_
#define ENTITY_H_

#include "Sprite.h"
#include "Camera.h"
#include "Input.h"

enum ObjectType
{
	OBJECTTYPE,
	ROCKMANTYPE,
	LANDTYPE,
	BRICKTYPE,
	PIPETYPE,
	COINTYPE,
	FLOWERTYPE,
	MUSHROOMBIGTYPE,
	MUSHROOMLIFETYPE,
	MUSHROOMTYPE,
	TURTLETYPE,
	STARTYPE,
	COINQUESTIONTYPE,
	HOUSETYPE,
	BOSSTYPE,
	BOSSFIRETYPE,
	FLAGTYPE
};


class CEntity
{
private:
	bool m_isTurnLeft;
	void UpdatePosition(float);	
	 
protected:
	int m_Id;
	ObjectType m_Type;
	D3DXVECTOR2 m_veloc;
	D3DXVECTOR2 m_accel;
	D3DXVECTOR3 m_pos;
	RECT mRect;
	CSprite *m_sprite;
public:
	int GetId(){
		return m_Id;//ID
	}
	int GetType(){
		return m_Type;//ID
	}
	virtual void Update(float , CCamera *, CInput *);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	CEntity(void);
	~CEntity(void);
};

#endif