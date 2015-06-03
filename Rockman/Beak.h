#ifndef _BEAK_H_
#define _BEAK_H_
#include "ResourceManager.h"
#include "Entity.h"
class CBeak : public CEntity
{
private:
protected:
public:
	CBeak(int _id, D3DXVECTOR3 _pos);
	~CBeak(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Draw();
	virtual void Collision();
};

#endif