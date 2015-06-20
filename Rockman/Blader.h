#ifndef _BLADER_H_
#define _BLADER_H_
#include "ResourceManager.h"
#include "Entity.h"
class CBlader : public CEntity
{
private:
	bool m_IsLife;
	D3DXVECTOR3 m_PosInit;
protected:
public:
	CBlader(int _id, D3DXVECTOR3 _pos);
	~CBlader(void);
	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera);
	void UpdateCollison(CEntity* _other, float _time);
	void SetInjured(CEntity* _other);
};

#endif