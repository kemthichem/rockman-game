#ifndef _LAND_H_
#define _LAND_H_
#include "ResourceManager.h"
#include "Entity.h"
class CLand : public CEntity
{
private:
protected:

public:
	CLand(D3DXVECTOR3 _pos);
	~CLand(void);

	//method
	virtual void Update(float , CCamera *, CInput *);
	virtual void Draw();
	virtual void Collision();
};

#endif