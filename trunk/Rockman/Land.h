#ifndef _LAND_H_
#define _LAND_H_
#include "ResourceManager.h"
#include "Entity.h"
class CLand : public CEntity
{
private:
protected:

public:
	CLand(int _id, D3DXVECTOR3 _pos, bool _isCheckCollison = true);
	~CLand(void);

	//method
	virtual void Update(float , CCamera *, CInput *);
	void Render(LPD3DXSPRITE _sp, CCamera* _camera);
};

#endif