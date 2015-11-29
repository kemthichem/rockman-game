#ifndef _SPINE_H_
#define _SPINE_H_
#include "ResourceManager.h"
#include "Entity.h"
class CSpine : public CEntity
{
private:
protected:
public:
	CSpine(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide);

	CSpine(int _id, D3DXVECTOR3 _pos);
	~CSpine(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
};

#endif