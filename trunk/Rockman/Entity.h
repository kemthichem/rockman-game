#ifndef ENTITY_H_
#define ENTITY_H_
#include <vector>
#include<algorithm>

#include "Sprite.h"
#include "Camera.h"
#include "Input.h"
#include "AABBCollisionDetected.h"

using std::vector;

enum ObjectType
{
	OBJECTTYPE,
	ROCKMANTYPE,
	LANDTYPE,
	BIGEYE
};


class CEntity
{
private:
	bool m_isTurnLeft;
	void UpdatePosition(float);	
	 
protected:
	int m_Id;
	CAABBCollision *m_collision;
	ObjectType m_Type;
	D3DXVECTOR2 m_veloc;
	D3DXVECTOR2 m_accel;
	D3DXVECTOR3 m_pos;
	RECT m_Rect;
	CSprite *m_sprite;

	virtual void UpdateCollison(CEntity* _orther,float _time);
public:

	float m_TimeCollision;
	int GetId(){
		return m_Id;//ID
	}
	int GetType(){
		return m_Type;//ID
	}
	D3DXVECTOR2 GetVelocity();
	D3DXVECTOR2 GetAccleration();
	RECT GetRect();

	virtual void Update(float , CCamera *, CInput *, vector<CEntity*>);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	CEntity(void);
	~CEntity(void);
};

#endif