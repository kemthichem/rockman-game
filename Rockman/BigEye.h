#ifndef _BIGEYE_H_
#define _BIGEYE_H_
#include "Enemy.h"
class CBigEye : public CEnemy
{
private:
	int m_Blood;
protected:
	virtual void UpdateCollison(CEntity* _other,float _time);
	void ExecuteCollision(CEntity* _other,DirectCollision m_directCollion,float _timeEntry);
	//method
public:
	CBigEye(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide);
	CBigEye(int _id, D3DXVECTOR3 _pos);
	virtual void SetInjured(CEntity* _other);
	~CBigEye(void);
	void Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera);
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);

	void Reset();
};

#endif