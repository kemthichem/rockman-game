#ifndef _LAND_ICEBERG_H_
#define _LAND_ICEBERG_H_
#include "ResourceManager.h"
#include "Entity.h"
class CLandIceberg : public CEntity
{
private:
protected:

public:
	CLandIceberg(int _id, D3DXVECTOR3 _pos, bool _isCheckCollison = true);
	~CLandIceberg(void);

	//method
	virtual void Update(float , CCamera *, CInput *);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	virtual void Collision();
};

#endif