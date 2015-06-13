#ifndef _MET_H_
#define _MET_H_
#include "ResourceManager.h"
#include "Entity.h"
class CMet : public CEntity
{
private:
protected:
public:
	CMet(int _id, D3DXVECTOR3 _pos);
	~CMet(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Draw();
};

#endif