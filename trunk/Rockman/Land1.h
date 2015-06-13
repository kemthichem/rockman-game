#ifndef _LAND1_H_
#define _LAND1_H_
#include "ResourceManager.h"
#include "Entity.h"
class CLand1 : public CEntity
{
private:
protected:

public:
	CLand1(int _id, D3DXVECTOR3 _pos, bool _isCheckCollison = true);
	~CLand1(void);

	//method
	virtual void Update(float , CCamera *, CInput *);
	virtual void Render(LPD3DXSPRITE, CCamera*);
};

#endif