#ifndef _FLYING_SHELL_H_
#define _FLYING_SHELL_H_
#include "Enemy.h"
#include "Bullet.h"


#define NUM_BULLET (8)

enum FlyShellStatus {
	FlyShellWait,
	FlyShellShot
};


class CFlyingShell : public CEnemy
{
private:
	CBullet *m_ListBullet[NUM_BULLET];
	int m_CurrentBullet;
	FlyShellStatus m_Status;
	float m_TimeSpent;
	float m_TimeShot;
protected:
public:
	CFlyingShell(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide, bool _isLeft);
	CFlyingShell(int _id, D3DXVECTOR3 _pos);
	~CFlyingShell(void);

	//method
	virtual void Update(float , CCamera *, CInput *,  vector<CEntity* >);
	virtual void Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera);
	void SetInjured(CEntity* _other);
	void Reset();
	void Shot();

};

#endif