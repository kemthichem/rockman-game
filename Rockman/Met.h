#ifndef _MET_H_
#define _MET_H_
#include "Enemy.h"
class CMet : public CEnemy
{
private:
protected:
public:
	CMet(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide);
	CMet(int _id, D3DXVECTOR3 _pos);
	~CMet(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
};

#endif