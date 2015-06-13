#ifndef _GUT_H_
#define _GUT_H_
#include "ResourceManager.h"
#include "Entity.h"
class CGutsMan : public CEntity
{
private:
protected:
public:
	CGutsMan(int _id, D3DXVECTOR3 _pos);
	~CGutsMan(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
};

#endif