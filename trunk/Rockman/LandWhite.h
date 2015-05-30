#ifndef _LAND_WHITE_H_
#define _LAND_WHITE_H_
#include "ResourceManager.h"
#include "Entity.h"
class CLandWhite : public CEntity
{
private:
protected:

public:
	CLandWhite(int _id, D3DXVECTOR3 _pos);
	~CLandWhite(void);

	//method
	virtual void Update(float , CCamera *, CInput *);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	virtual void Collision();
};

#endif