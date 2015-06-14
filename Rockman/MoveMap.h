#ifndef	_MOVEMAP_H
#define  _MOVEMAP_H

#include "Entity.h"
enum TypeMove
{
	MOVEX,
	MOVEY,
	MOVENONE
};

class CMoveMap : public CEntity
{
private:
	int m_MoveDirect;
public:
	static int g_DistanceMoveCameraY;
	static int g_DistanceMoveCameraX;
	static TypeMove g_TypeMove;

	CMoveMap(int, D3DXVECTOR3);
	~CMoveMap(void);

	virtual void Update(float , CCamera *, CInput *, vector<CEntity*>);
	virtual void Render(LPD3DXSPRITE, CCamera*);

	bool IsCanWithDirect(bool _isUp);
};

#endif