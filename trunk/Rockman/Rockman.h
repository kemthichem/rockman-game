#ifndef	_ROCKMAN_H
#define  _ROCKMAN_H
#include "ResourceManager.h"
#include "Entity.h"
#include "AABBCollisionDetected.h"
#include "BulletRockman.h"
#include "Blood.h"

enum ActionRockman
{
	Action_Stand = 0,
	Action_Stand_Gun,
	Action_Go,
	Action_Go_Gun,
	Action_Jump,
	Action_Jump_Gun,
	Action_Climb_Stand,
	Action_Climb_Stand_Gun,
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
	CBulletRockman* m_ListBullet[5];
	CBlood* m_Blood;
	float m_PosXClimb;
	void Injunred(bool _isDirectX, float _time);
	bool m_isCollisionBottom;
	float m_TimeInjured;
	int m_Injuring;//0: not Injuring - 1:right - -1:left
	int m_KeyDown;
	ActionRockman m_action;
	void UpdateSprite(float _time);
	void Stand();
	void TurnLeft();
	void TurnRight();
	void Jump();
	void Shot();
	void Climb(bool _isTurnUp);
	void UpdateState();
	//collision
	void CollisionBottom();
public:
	CRockman();
	CRockman(D3DXVECTOR3 _pos);
	~CRockman();
	virtual void Update(float , CCamera *, CInput *, vector<CEntity*> );
	virtual void Render(LPD3DXSPRITE, CCamera*);
	virtual void UpdateCollison(CEntity* _other, float _time);
	void ExecuteCollision(CEntity* _other,DirectCollision m_directCollion,float _timeEntry);

	/*rockman*/
	void SetInjured(CEntity* _other);
	int GetKeyDown();
	bool IsDie();
};
#endif