#ifndef	_ITEM_H_
#define _ITEM_H_

#include "Entity.h"

//Item for enemies
class CItem : public CEntity
{
private:	
	D3DXVECTOR3 m_posInit;

protected:
	bool m_IsActive;
	virtual void UpdateCollison(CEntity* ,float);

public:
	CItem();
	CItem(D3DXVECTOR3 _pos);
	~CItem(void);

	virtual void Update(float , CCamera *, CInput *, vector<CEntity*>);
	virtual void Render(LPD3DXSPRITE, CCamera*);

	//Item
	void SetVelloc(D3DXVECTOR2 _velloc);
	void SetActive(bool _isActive);
	bool GetActive() {
		return m_IsActive;
	}
	void ExecuteCollision(CEntity* _other, DirectCollision m_directCollision, float timeEntry);
};

#endif
