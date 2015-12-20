#ifndef _ROCK_H_
#define _ROCK_H_
#include "Entity.h"
class CRock : public CEntity
{
private:
protected:

public:
	CRock(int _id, D3DXVECTOR3 _pos, bool _isCheckCollison = true);
	CRock(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide);
	~CRock(void);

	//method
	virtual void Update(float , CCamera *, CInput *);
	void Render(LPD3DXSPRITE _sp, CCamera* _camera);
};

#endif