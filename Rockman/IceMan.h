#ifndef _ICEMAN_H_
#define _ICEMAN_H_
#include "ResourceManager.h"
#include "Entity.h"
#include "Blood.h"

enum IceManStatus {
	HELLO,
	STAND,
	MOVE,
	JUMP
};

class CIceMan : public CEntity
{
private:
	IceManStatus m_Status;
	float m_TimeSpend;
	CBlood* m_Blood;
protected:
public:
	CIceMan(int _id, D3DXVECTOR3 _pos);
	~CIceMan(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE _sp, CCamera* _cam);
};

#endif