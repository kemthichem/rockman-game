#ifndef _STATICOBJECT_H
#define _STATICOBJECT_H

#include "CusRect.h"
#include "Sprite.h"

#define  ACCLE 0.000005f
#define  GRAVITY 0.15f;

class CStaticObject
{
protected:


	//pos.
public:
	D3DXVECTOR3 pos;
	bool checked;
	bool visible;
	int id;
	bool life;
	virtual void Render(){};
	CusRect rectagle;
	CStaticObject(void);
	~CStaticObject(void);
	virtual void Update(DWORD t){};

};

class CMotionObject:public CStaticObject
{
private :
	float lastx, lasty;
protected:
	void Update(DWORD t);
	virtual void _Update(DWORD t){};
	void Gravity(int deltime, int floor);
	float vx, vy;
	void SetPosX(CStaticObject* obIntersect);
	void SetPosY(CStaticObject* obIntersect);
public:
	CMotionObject();	
	~CMotionObject();
	virtual void SetLife( bool _life ){};
};

#endif
