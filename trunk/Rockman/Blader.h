#ifndef _BLADER_H_
#define _BLADER_H_
#include "ResourceManager.h"
#include "Entity.h"
class CBlader : public CEntity
{
private:
protected:
public:
	CBlader(int _id, D3DXVECTOR3 _pos);
	~CBlader(void);
	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	void UpdateCollison(CEntity* _other, float _time);
};

#endif