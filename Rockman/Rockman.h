#include "RockmanGame.h"
#ifndef	_MARIO_H
#define  _MARIO_H
#define  ACCLE 0.000005f
#define  GRAVITY 0.15f;
class CBullet;
class CRockman: public CMotionObject
{
private:
	
	CSprite* sprite;
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
	bool isSitting;
	//bool isWin;
	//-----
	CBullet* bullet[3];
	DWORD timeStartConvert;
	DWORD timeStartSuper;
	DWORD timeSuper;

	//---function
	void Bounce();
	void Converting();
	void Flashing();
	void SetConvertGun();
	void SetCreep(CStaticObject* ob,float _vyCreep=-1);
public:
	CRockman(void);
	CRockman(D3DXVECTOR3 _pos);
	~CRockman(void);
	//--
	void TurnRight(int time);
	void TurnLeft(int time);
	void Sitting(int time);
	void Stop(int time);
	void Jump();
	void Shoot();
	void NoShoot();
	//---
	void _Update(CQuadTreeNode* root,DWORD deltaTime);
	void Render();
};
#endif