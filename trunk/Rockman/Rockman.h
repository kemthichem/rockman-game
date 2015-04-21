#ifndef	_ROCKMAN_H
#define  _ROCKMAN_H
#include "ResourceManager.h"
#include "Entity.h"

class CRockman: public CEntity
{
public:
	static D3DXVECTOR2 posInMap;

	CRockman();
	CRockman(D3DXVECTOR3 _pos);
	~CRockman();
	void Update(DWORD , CCamera *, CInput *);
};
#endif