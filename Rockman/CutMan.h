#ifndef _CUTMAN_H_
#define _CUTMAN_H_
#include "ResourceManager.h"
#include "Entity.h"
#include "Blood.h"

enum Status {
	StandNormal,
	StandHaveCut,
	MoveNormal,
	MoveHaveCut,
	JumpNormal,
	JumpHaveCut
};

class CCutMan : public CEntity
{
private:
	Status m_Status;
	CBlood* m_Blood;
	float m_timeSpend;
protected:
public:
	CCutMan(int _id, D3DXVECTOR3 _pos);
	~CCutMan(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	void Render(LPD3DXSPRITE _sp, CCamera* _cam);

};

#endif