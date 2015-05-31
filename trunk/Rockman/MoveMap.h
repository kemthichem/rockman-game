#ifndef	_MOVEMAP_H
#define  _MOVEMAP_H

#include "Entity.h"

class CMoveMap : public CEntity
{
private:
	int m_MoveDirect;
public:
	static int g_DistanceMoveCameraY;
	static bool g_IsMovingMap;

	CMoveMap(int, D3DXVECTOR3);
	~CMoveMap(void);

	virtual void Update(float , CCamera *, CInput *, vector<CEntity*>);
	virtual void Render(LPD3DXSPRITE, CCamera*);

	void SetDirect(bool _isUp);
	bool IsCanWithDirect(bool _isUp);
};

#endif