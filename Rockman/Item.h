#ifndef	_ITEM_H_
#define _ITEM_H_

#include "Entity.h"

enum Type {
	BONUS = 1,
	MANA,
	BLOOD_SMALL,
	BLOOD_BIG,
	ITEM_COUNT
};

//Item for enemies
class CItem : public CEntity
{
private:	
	D3DXVECTOR3 m_posInit;
	Type m_typeItem;

	void HaveItem(CEntity* _rockMan);
protected:
	bool m_IsActive;
	virtual void UpdateCollison(CEntity* ,float);

public:
	CItem();
	CItem(D3DXVECTOR3 _pos, Type _type);
	CItem(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide, Type _type);
	~CItem(void);

	virtual void Update(float , CCamera *, CInput *, vector<CEntity*>);
	virtual void Render(LPD3DXSPRITE, CCamera*);

	//Item
	void SetVelloc(D3DXVECTOR2 _velloc);
	void SetAccel(D3DXVECTOR2 _accel);
	void SetActive(bool _isActive);
	bool GetActive() {
		return m_IsActive;
	}
	void ExecuteCollision(CEntity* _other, DirectCollision m_directCollision, float timeEntry);
};

#endif
