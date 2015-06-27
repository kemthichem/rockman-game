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
	void UpdateCollison(CEntity* _other,float _time);
	void ExecuteCollision(CEntity* _other,DirectCollision m_directCollion,float _timeEntry);
};

#endif