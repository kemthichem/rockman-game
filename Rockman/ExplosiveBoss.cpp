#include "ExplosiveBoss.h"
#include "PLayingGameState.h"
#include "Config.h"

CExplosiveBoss::CExplosiveBoss(CSprite* _sprite)
{
	m_spriteExplosive = _sprite;
	m_timeAnimation = 0;
	m_timeExplosive = 0;
	m_dis = 3;
	m_pos = D3DXVECTOR3(0,0,0);
}

CExplosiveBoss::CExplosiveBoss()
{

}

CExplosiveBoss::~CExplosiveBoss(void)
{
	delete m_spriteExplosive;
}

void CExplosiveBoss::Update(float _deltaTime, CCamera *_camera)
{
	if (m_timeExplosive >= CConfig::ValueOf(KEY_EP_TIME_EXPLOSIVE)) 
		CPLayingGameState::g_ChangeState = (ChangeState)m_ValueChangeTo;
	else
		m_timeExplosive += _deltaTime;


	if (m_timeAnimation < CConfig::ValueOf(KEY_EP_TIME_ANIMATION)) {
		m_timeAnimation += _deltaTime;
		return;
	}

	m_spriteExplosive->Next(_deltaTime);
	m_timeAnimation = 0;
	m_dis += 2;
}

void CExplosiveBoss::Render(LPD3DXSPRITE _spriteHandler, CCamera *_camera)
{
	D3DXVECTOR3 pos = m_pos;
	//X
	//1
	pos.x -= m_dis;
	m_spriteExplosive->Render(_spriteHandler, _camera, pos);
	pos = m_pos;
	//2
	pos.x -= 2 * m_dis;
	m_spriteExplosive->Render(_spriteHandler, _camera, pos);
	pos = m_pos;
	//3
	pos.x += m_dis;
	m_spriteExplosive->Render(_spriteHandler, _camera, pos);
	pos = m_pos;
	//4
	pos.x += 2*m_dis;
	m_spriteExplosive->Render(_spriteHandler, _camera, pos);
	pos = m_pos;

	//Y
	//1
	pos.y -= m_dis;
	m_spriteExplosive->Render(_spriteHandler, _camera, pos);
	pos = m_pos;
	//2
	pos.y -= 2 * m_dis;
	m_spriteExplosive->Render(_spriteHandler, _camera, pos);
	pos = m_pos;
	//3
	pos.y += m_dis;
	m_spriteExplosive->Render(_spriteHandler, _camera, pos);
	pos = m_pos;
	//4
	pos.y += 2*m_dis;
	m_spriteExplosive->Render(_spriteHandler, _camera, pos);
	pos = m_pos;

	//Slant
	//1
	pos.x -= m_dis*1.5;
	pos.y  -= m_dis*1.5;
	m_spriteExplosive->Render(_spriteHandler, _camera, pos);
	pos = m_pos;

	//2
	pos.x += m_dis*1.5;
	pos.y  += m_dis*1.5;
	m_spriteExplosive->Render(_spriteHandler, _camera, pos);
	pos = m_pos;

	//1
	pos.x -= m_dis*1.5;
	pos.y  += m_dis*1.5;
	m_spriteExplosive->Render(_spriteHandler, _camera, pos);
	pos = m_pos;

	//1
	pos.x += m_dis*1.5;
	pos.y  -= m_dis*1.5;
	m_spriteExplosive->Render(_spriteHandler, _camera, pos);
	pos = m_pos;
}

void CExplosiveBoss::Explosive(D3DXVECTOR3 _pos, int _valueChangeTo)
{
	m_ValueChangeTo = _valueChangeTo;
	m_pos = _pos;
}
