#ifndef	_ROCKMAN_H
#define  _ROCKMAN_H
#include "ResourceManager.h"
#include "Entity.h"
enum ActionRockman
{
	Action_Stand = 0,
	Action_Stand_Gun,
	Action_Go,
	Action_Go_Gun,
	Action_Jump,
	Action_Jump_Gun,
	Action_Climb,
	Action_Climb_Gun,
	Action_Start,
	Action_Injured,
	Action_Fainting	
};

class CRockman: public CEntity
{
private:
	static const D3DXVECTOR2 mAccelOfRockman;

	bool m_isCollisionBottom;

	ActionRockman m_action;
	void UpdateSprite();

	void Stand();
	void TurnLeft();
	void TurnRight();
	void Jump();

	//collision
	void CollisionBottom();
public:
	static D3DXVECTOR2 posInMap;

	CRockman();
	CRockman(D3DXVECTOR3 _pos);
	~CRockman();
	void Update(float , CCamera *, CInput *);
};
#endif