#ifndef _Land3_H_
#define _Land3_H_
#include "ResourceManager.h"
#include "Entity.h"
class CLand3 : public CEntity
{
private:
protected:

public:
	CLand3(int _id, D3DXVECTOR3 _pos, bool _isCheckCollison = true);
	~CLand3(void);

	//method
	virtual void Update(float , CCamera *, CInput *);
	virtual void Render(LPD3DXSPRITE, CCamera*);
};

#endif