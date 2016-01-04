#ifndef ENEMY_H_
#define  ENEMY_H_
#include "Entity.h"
#include "Item.h"

class CEnemy : public CEntity
{
private:
	long m_timeExplosive;
	
protected:
	bool m_IsLife;
	CSprite *m_spriteExplosive;
	D3DXVECTOR3 m_posOrg;
	int m_rangeItem;
	CItem* m_item;
	void CreateItem();
public:
	void GetRectInit(RECT &r);
	virtual void Reset();
	CEnemy(void);
	virtual ~CEnemy(void);

	virtual void Update(float _time, CCamera * _camare, CInput* _input, vector<CEntity*> _listOb);
	virtual void Render(LPD3DXSPRITE _spHandle, CCamera* _camera);
	virtual void SetInjured(CEntity* _other);
};
#endif // !ENEMY_H_
