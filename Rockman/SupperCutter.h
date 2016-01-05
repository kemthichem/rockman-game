#ifndef _SUPER_CUTTER_
#define _SUPER_CUTTER_

#include "Enemy.h"

class CSupperCutter : public CEnemy
{
private:
	bool m_isChild;
	CSupperCutter* m_childCutter[4];
	bool m_isActive;
	float m_timeJump;

protected:
	virtual void Reset();
	virtual void UpdateCollison(CEntity* _other,float _time);
public:
	CSupperCutter(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide, bool _child = false);
	CSupperCutter(int _id, D3DXVECTOR3 _pos);
	~CSupperCutter(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE _spHandle, CCamera* _camera);
	void SetActive(bool param1);
	void SetVelloc(D3DXVECTOR2 _velloc);
};

#endif