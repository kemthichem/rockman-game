#ifndef _ICEMAN_H_
#define _ICEMAN_H_
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

class CIceMan : public CEntity
{
private:
	Status m_Status;
	float m_timeSpend;
protected:
public:
	CIceMan(int _id, D3DXVECTOR3 _pos);
	~CIceMan(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Draw();
	virtual void Collision();

};

#endif