#ifndef _DOOR_H_
#define _DOOR_H_
#include "Entity.h"
class CDoor : public CEntity
{
private:
	bool m_isEndDoor;
	bool m_isActived;

protected:
public:
	void ActiveDoor();
	CDoor(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide, bool _isEndDoor = false);
	CDoor(int _id, D3DXVECTOR3 _pos);
	~CDoor(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
};

#endif