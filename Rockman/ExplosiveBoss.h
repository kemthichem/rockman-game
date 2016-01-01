#ifndef _EXPLOSIVE_BOSS_H
#define _EXPLOSIVE_BOSS_H
#include "Sprite.h"

class CExplosiveBoss
{
private:
	CSprite *m_spriteExplosive;
	float m_timeAnimation;
	float m_timeExplosive;
	long m_dis;
	D3DXVECTOR3 m_pos;
	int m_ValueChangeTo;

public:
	CExplosiveBoss(CSprite* _spriteEx);
	CExplosiveBoss();
	~CExplosiveBoss(void);
	void Explosive(D3DXVECTOR3 _pos, int _valueChangeTo);
	void Update(float _deltaTime, CCamera *_camera);
	void Render(LPD3DXSPRITE _spriteHandler, CCamera *_camera);
};

#endif
