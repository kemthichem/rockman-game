#ifndef _LADDER_H_
#define _LADDER_H_
#include "ResourceManager.h"
#include "Entity.h"
class CLadder : public CEntity
{
private:
protected:
	void UpdateCollison(CEntity* _other, float _time);
public:
	CLadder(int _id, D3DXVECTOR3 _pos);
	~CLadder(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	
};

#endif