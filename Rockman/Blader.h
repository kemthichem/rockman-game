#ifndef _BLADER_H_
#define _BLADER_H_
#include "Enemy.h"
enum BladerState
{
	Bide,
	Back,
	Attack
};

class CBlader : public CEnemy
{
private:
	int disBack;
	bool m_isCompleteAttack;
	BladerState m_state;
	D3DXVECTOR2 m_posAttack;
protected:
public:
	CBlader(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide);
	CBlader(int _id, D3DXVECTOR3 _pos);
	~CBlader(void);
	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera);
	void UpdateCollison(CEntity* _other, float _time);
	void SetInjured(CEntity* _other);
};

#endif