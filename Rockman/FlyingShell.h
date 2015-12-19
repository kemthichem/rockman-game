#ifndef _FLYING_SHELL_H_
#define _FLYING_SHELL_H_
#include "Entity.h"
class CFlyingShell : public CEntity
{
private:
protected:
public:
	CFlyingShell(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide);
	CFlyingShell(int _id, D3DXVECTOR3 _pos);
	~CFlyingShell(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Draw();
};

#endif