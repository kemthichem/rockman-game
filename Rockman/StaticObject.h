#include "RockmanGame.h"
#ifndef _STATICOBJECT_H
#define _STATICOBJECT_H
class CQuadTreeNode;
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
	virtual void Update(CQuadTreeNode* root,DWORD t){};

};

class CMotionObject:public CStaticObject
{
private :
	float lastx, lasty;
protected:
	void Update(CQuadTreeNode* root,DWORD t);
	virtual void _Update(CQuadTreeNode* root,DWORD t){};
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
