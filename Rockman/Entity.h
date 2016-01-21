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
	BLOCK = -10,
	LADDER,
	ROCKMAN = 0,
	DOOR1_CUTMAN,
	RAMIE,
	ITEM,
	SUPER_CUTTER,
	FLYING_SHELL,
	BIGEYE,
	BLADER,
	MET,
	SPINE,
	SCREW_BOMBER,
	OCTOPUS,
	BEAK,
	BOMBOMB,
	FLEA,
	PICKETMAN,
	CUTMAN = 100,
	GUTSMAN,
	ICEMAN = 110,
	BULLET,
	
};

enum TypeID{
	ID_ENEMY_BALL = 1,
	ID_ENEMY_BOOM_BLUE = 2,
	ID_ENEMY_EYE_RED_UP = 3,
	ID_ENEMY_EYE_RED_RIGHT = 501,
	ID_ENEMY_FISH_ORANGE = 4,
	ID_ENEMY_INK_RED = 5,
	ID_ENEMY_MACHINE_AUTO_BLUE_TOP = 6,
	ID_ENEMY_MACHINE_ORANGE = 7,
	ID_ENEMY_NINJA_GREEN = 8,

	ID_ENEMY_BUBBLE_BLUE = 9,
	ID_ENEMY_CUT = 10,
	ID_ENEMY_INK_BLUE = 12,
	ID_ENEMY_MACHINE_AUTO_ORGANGE_TOP = 13,
	ID_ENEMY_ROBOT_RED = 14,
	ID_ENEMY_TANK_RED = 500,

	ID_ENEMY_BUBBLE_GREEN = 15,
	ID_ENEMY_HAT = 19,
	ID_ENEMY_ROBOT_BLUE = 20,
	ID_ENEMY_WORKER = 21,
	ID_BLOCK_TROUBLE_OF_ELEVATOR = 36,
	ID_ELEVATOR = 38,
	ID_ROCKGUSTMAN = 60,

	ID_BLOCK = 22,
	ID_CLAMPER = 23,
	ID_ITEM_LIFE = 24,
	ID_ITEM_BLOOD_BIG = 25,
	ID_ITEM_BLOOD_SMALL = 26,
	ID_ITEM_MANA = 27,
	ID_ITEM_MANA_SMALL = 28,
	ID_ROCK = 29,
	ID_DIEAARROW = 30,
	ID_BOSSCUT = 5000,
	ID_BOSSBOOM = 5002,
	ID_BOSSRUT = 5001,
	ID_ENEMY_MACHINE_AUTO_BLUE_BOTTOM = 34,
	ID_ENEMY_MACHINE_AUTO_ORGANGE_BOTT = 35,
	ID_CAMERA_PATH_POINT = 340,
	ID_FALLING_POINT = 341,
	ID_DOOR1_CUTMAN = 541,
	ID_DOOR1_GUTSMAN = 542,
	ID_DOOR1_BOOMMAN = 543,
	ID_DOOR2_BOOMMAN = 544,
	ID_DOOR2_CUTMAN = 545,
	ID_DOOR2_GUTSMAN = 546,
	ID_ENEMY_SNAPPER = 344,
	ID_ENEMY_WALL_SHOOTER_LEFT = 40,
	ID_ENEMY_WALL_SHOOTER_RIGHT = 41
};

class CEntity
{
private:	
	void UpdatePosition(float);	
	float m_Intersect;
	D3DXVECTOR2 m_lastVelloc;
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
	void RenderEachSprite(LPD3DXSPRITE, CCamera*,CSprite*, D3DXVECTOR3 _posRender);
	void UpdateRect();

	virtual bool IsObtainCollision(CEntity* _other);
public:
	float m_TimeCollision;
	int GetId(){
		return m_Id;//ID
	}
	int GetType(){
		return m_Type;//ID
	}
	D3DXVECTOR2 GetSize() {
		return m_Size;
	}

	D3DXVECTOR2 GetVelocity();
	D3DXVECTOR2 GetAccleration();
	RECT GetRect();
	bool IsShowed();
	bool IsCheckCollision();
	float GetIntersect()  {
		return m_Intersect;
	}
	virtual void Update(float , CCamera *, CInput *, vector<CEntity*>);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	virtual void SetInjured(CEntity* _other);
	CEntity(void);
	virtual ~CEntity(void);
};

#endif