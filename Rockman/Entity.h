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
	SCENERY = -10,
	LAND,
	LAND1,
	LANDWHITE,
	LANDICEBERG,
	ROCKMAN = 0,
	LADDER,
	BIGEYE,
	BLADER,
	CUTMAN,
	ICEMAN,
	SCREW_BOMBER,
	OCTOPUS,
	BEAK,
	FLEA,
	MOVEMAP,
	BULLET,
	ITEM
};

class CEntity
{
private:	
	void UpdatePosition(float);		
	
protected:
	bool m_isTurnLeft;
	int m_Id;
	CAABBCollision *m_collision;
	DirectCollision m_directCollision;
	ObjectType m_Type;
	D3DXVECTOR2 m_velloc;
	D3DXVECTOR2 m_accel;
	D3DXVECTOR3 m_pos;
	RECT m_Rect;
	D3DXVECTOR2 m_Size;
	CSprite *m_Sprite;
	bool m_IsShowed;
	bool m_IsCheckCollision;

	virtual void UpdateCollison(CEntity* _other,float _time);
	void RenderEachSprite(LPD3DXSPRITE, CCamera*, D3DXVECTOR3 _posRender);
	void UpdateRect();
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
	bool IsShowed();
	bool IsCheckCollision();
	virtual void Update(float , CCamera *, CInput *, vector<CEntity*>);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	CEntity(void);
	virtual ~CEntity(void);
};

#endif