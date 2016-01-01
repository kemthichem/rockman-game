#ifndef _RAMIE_H_
#define _RAMIE_H_
#include "Entity.h"
class CRamie : public CEntity
{
private:
protected:

public:
	CRamie(int _id, D3DXVECTOR3 _pos, bool _isCheckCollison = true);
	CRamie(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide);
	~CRamie(void);

	//method
	virtual void Update(float , CCamera *, CInput *);
	void Render(LPD3DXSPRITE _sp, CCamera* _camera);
};

#endif