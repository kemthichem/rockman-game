#ifndef _FLEA_H_
#define _FLEA_H_
#include "ResourceManager.h"
#include "Entity.h"
class CFlea : public CEntity
{
private:
protected:
public:
	CFlea(int _id, D3DXVECTOR3 _pos);
	~CFlea(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
};

#endif