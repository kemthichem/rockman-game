#ifndef _GUT_H_
#define _GUT_H_
#include "ResourceManager.h"
#include "Entity.h"
#include "Blood.h"

class CGutsMan : public CEntity
{
private:
	CBlood* m_Blood;
protected:
public:
	CGutsMan(int _id, D3DXVECTOR3 _pos);
	~CGutsMan(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE, CCamera*);
};

#endif