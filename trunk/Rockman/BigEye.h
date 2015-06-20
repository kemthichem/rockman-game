#ifndef _BIGEYE_H_
#define _BIGEYE_H_
#include "ResourceManager.h"
#include "Entity.h"
class CBigEye : public CEntity
{
private:
	D3DXVECTOR3 m_PosInit;
protected:
public:
	CBigEye(int _id, D3DXVECTOR3 _pos);
	~CBigEye(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Draw();
	virtual void Collision();
};

#endif