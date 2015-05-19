#ifndef _LAND1_H_
#define _LAND1_H_
#include "ResourceManager.h"
#include "Entity.h"
class CLand1 : public CEntity
{
private:
protected:

public:
	CLand1(int _id, D3DXVECTOR3 _pos);
	~CLand1(void);

	//method
	virtual void Update(float , CCamera *, CInput *);
	virtual void Draw();
	virtual void Collision();
};

#endif