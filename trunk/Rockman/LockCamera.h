#ifndef	_LockCamera_H
#define  _LockCamera_H

#include "Entity.h"
class CLockCamera : public CEntity
{
public:
	static TypeMove g_TypeMove;

	CLockCamera(int, D3DXVECTOR3, bool _isLock = true);
	~CLockCamera(void);

	virtual void Update(float , CCamera *, CInput *, vector<CEntity*>);
	virtual void Render(LPD3DXSPRITE, CCamera*);
};

#endif