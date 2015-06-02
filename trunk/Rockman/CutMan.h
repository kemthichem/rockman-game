#ifndef _CUTMAN_H_
#define _CUTMAN_H_
#include "ResourceManager.h"
#include "Entity.h"

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
	float m_timeSpend;
protected:
public:
	CCutMan(int _id, D3DXVECTOR3 _pos);
	~CCutMan(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Draw();
	virtual void Collision();
};

#endif