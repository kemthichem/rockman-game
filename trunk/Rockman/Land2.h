#ifndef _Land2_H_
#define _Land2_H_
#include "ResourceManager.h"
#include "Entity.h"
class CLand2 : public CEntity
{
private:
	int m_NumSprite;
protected:

public:
	CLand2(int _id, D3DXVECTOR3 _pos, bool _isCheckCollison = true);
	~CLand2(void);

	//method
	virtual void Update(float , CCamera *, CInput *);
	virtual void Render(LPD3DXSPRITE, CCamera*);
};

#endif