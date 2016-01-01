#ifndef	_ROCKMAN_H
#define  _ROCKMAN_H
#include "Entity.h"
#include "AABBCollisionDetected.h"
#include "BulletRockman.h"
#include "Blood.h"
#include "ExplosiveBoss.h"

enum ActionRockman
{
	Action_Stand = 0,
	Action_Stand_Gun,
	Action_Go_Prepare,
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
	//Sprite
	CSprite *m_SpriteStart;
	CSprite *m_SpriteJump;
	CSprite *m_SpriteStand;
	CSprite *m_SpriteStandGun;
	CSprite *m_SpriteRun;
	CSprite *m_SpriteRunGun;
	CSprite *m_SpriteClimb;
	CSprite *m_SpriteClimbGun;
	CSprite *m_SpriteInjured;
	ActionRockman m_action;

	D3DXVECTOR2 m_SizeClimb;
	D3DXVECTOR2 m_SizeInit;

	//Other
	CBulletRockman* m_ListBullet[5];
	CBlood* m_Blood;
	CExplosiveBoss* explosive;

	float m_PosXClimb;
	bool m_isCanClimb;
	bool m_isCollisionBottom;
	bool m_IsLadderBottom;
	bool m_isExplosive;

	//bool m_CanDown;
	void Injunred(bool _isDirectX, float _time);
	
	float m_TimeInjured;
	float m_TimeShot;
	char m_Injuring;//0: not Injuring - 1:right - -1:left
	int m_KeyDown;
	void UpdateSprite(float _time);
	void Stand();
	void TurnLeft();
	void TurnRight();
	void Jump();
	void Shot();
	bool Climb(bool _isTurnUp);
public:
	CRockman();
	CRockman(D3DXVECTOR3 _pos);
	~CRockman();
	virtual void Update(float , CCamera *, CInput *, vector<CEntity*> );
	virtual void Render(LPD3DXSPRITE, CCamera*);
	virtual void UpdateCollison(CEntity* _other, float _time);
	void ExecuteCollision(CEntity* _other,DirectCollision m_directCollion,float _timeEntry);

	/*rockman*/
	void SetInjured(CEntity* _other, int _dam = -10);
	void SetKeyDown(int _key);
	void MoveRightWhenMoveMap();
	void UpdateActionShot();
	void SetPos(D3DXVECTOR3 _pos);
	static D3DXVECTOR2 g_PosRockman;
	static bool m_IsClimbing;


	/***Cheat***/
	void CheatBlood();
};
#endif