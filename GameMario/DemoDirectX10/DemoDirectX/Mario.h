#include "MarioGame.h"
#ifndef	_MARIO_H
#define  _MARIO_H
#define  ACCLE 0.000005f
#define  GRAVITY 0.15f;
class CBullet;
class CMario: public CMotionObject
{
private:
	
	CSprite* sprite;
	CSprite* spriteCovert;
	float lastvx;
	float lastvy;
	float maxSpeedvx;
	int numberBullet;	
	int powerJumb;
	int state;//0-stand; 1-turn; 2-jumb; 3-brake; 4-sitting; 5-die
	float vxCreep, vyCreep;
	int distanceCreep;
	int distance;
	int timesCreep;
	//-----
	bool isShooted;
	bool isBounce;	
	bool isSmall;	
	bool isConvert;
	bool isGun;
	bool isConvertGun;
	bool isConvertLarge;
	bool isSitting;
	bool isCreep;
	bool isWin;
	//-----
	CBullet* bullet[3];
	DWORD timeStartConvert;
	DWORD timeStartSuper;
	DWORD timeSuper;

	//---function
	bool CheckCollision(CQuadTreeNode* root);
	void Bounce();
	void CreateBullet();
	void Converting();
	void Flashing();
	void Creeping();
	void GoWin();
	void SetConvertGun();
	void SetCreep(CStaticObject* ob,float _vyCreep=-1);
public:
	CMario(void);
	CMario(D3DXVECTOR3 _pos);
	~CMario(void);
	//----
	bool isSuper;
	//--
	void TurnRight(int time);
	void TurnLeft(int time);
	void Sitting(int time);
	void Stop(int time);
	void Jump();
	void Shoot();
	void NoShoot();
	//---
	bool IsTurn();
	void _Update(CQuadTreeNode* root,DWORD deltaTime);
	void Render();
	//----------
	void SetLife(bool life);
	void SetLarge(bool _isSmall);
	void SetGun();
	void SetSuper();
	void SetDie();
};
#endif