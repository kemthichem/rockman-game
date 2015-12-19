#ifndef _SUPER_CUTTER_
#define _SUPER_CUTTER_

#include "Entity.h"
class CSupperCutter : public CEntity
{
private:
protected:
public:
	CSupperCutter(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide);
	CSupperCutter(int _id, D3DXVECTOR3 _pos);
	~CSupperCutter(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Draw();
};

#endif