#ifndef	_BLOOD_H_
#define _BLOOD_H_

#include "Entity.h"

//Blood for enemies
class CBlood : public CEntity
{
private:	
	CSprite* m_SpriteBar;
	D3DXVECTOR2 m_Offset;

	int m_TotalBlood;
	int m_CurrentBlood;
	int m_CurrentPer;
public:
	CBlood();
	CBlood(D3DXVECTOR2 _offsetPosCamera, int _totalBlood);
	~CBlood(void);

	virtual void Update(float , CCamera *, CInput *, vector<CEntity*>);
	virtual void Render(LPD3DXSPRITE, CCamera*);
	void ChangeBlood(int _num);
	bool IsOver();
	//Blood

};

#endif
