#ifndef _FLEA_H_
#define _FLEA_H_
#include "Enemy.h"
class CFlea : public CEnemy
{
private:
protected:
public:
	CFlea(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide);
	~CFlea(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE _spHandle, CCamera* _camera);
	void UpdateCollison(CEntity* _other,float _time);
	void ExecuteCollision(CEntity* _other,DirectCollision m_directCollion,float _timeEntry);
	void SetInjured(CEntity* _other);
};

#endif