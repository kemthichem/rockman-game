#ifndef  _OCTOPUS_H
#define  _OCTOPUS_H
#include "ResourceManager.h"
#include "Entity.h"
#include "Bullet.h"
#include "Item.h"

#define NUM_BULLET (10)

class COctopus : public CEntity
{
private:
	CItem *m_Item;
	float  m_TimeSpend;
	bool m_IsLife;
	float m_vellocTemp;

public:
	COctopus(int _id, D3DXVECTOR3 _pos);
	~COctopus(void);

	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	void SetInjured(CEntity* _other);
	void UpdateCollison(CEntity* _other,float _time);
	void ExecuteCollision(CEntity* _other, DirectCollision m_directCollision, float timeEntry);
};
#endif
