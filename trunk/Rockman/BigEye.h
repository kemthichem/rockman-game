#ifndef _BIGEYE_H_
#define _BIGEYE_H_
#include "ResourceManager.h"
#include "Entity.h"
class CBigEye : public CEntity
{
private:
protected:
	virtual void UpdateCollison(CEntity* _other,float _time);
	void ExecuteCollision(CEntity* _other,DirectCollision m_directCollion,float _timeEntry);
	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);

public:
	CBigEye(int _id, D3DXVECTOR3 _pos);
	~CBigEye(void);


};

#endif