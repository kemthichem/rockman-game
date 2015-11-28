#ifndef _LAND_H_
#define _LAND_H_
#include "ResourceManager.h"
#include "Entity.h"
class CBlock : public CEntity
{
private:
protected:

public:
	CBlock(int _id, D3DXVECTOR3 _pos, bool _isCheckCollison = true);
	~CBlock(void);

	//method
	virtual void Update(float , CCamera *, CInput *);
	void Render(LPD3DXSPRITE _sp, CCamera* _camera);
};

#endif