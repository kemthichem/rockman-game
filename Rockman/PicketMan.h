#ifndef  _PICKETMAN_H
#define  _PICKETMAN_H
#include "Enemy.h"
#include "Bullet.h"
#include "Item.h"

#define NUM_BULLET (10)

class CPicketMan : public CEnemy
{
private:
	float  m_TimeSpend;
	D3DXVECTOR2 m_vellocTemp;

public:
	CPicketMan(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide, bool _isTurnHor = true);
	CPicketMan(int _id, D3DXVECTOR3 _pos, bool _isTurnHor = true);
	~CPicketMan(void);
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	void SetInjured(CEntity* _other);
	void UpdateCollison(CEntity* _other,float _time);
	void ExecuteCollision(CEntity* _other, DirectCollision m_directCollision, float timeEntry);
};
#endif
