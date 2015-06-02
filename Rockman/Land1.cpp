#include "Land1.h"

#define  NUMB_SPRITE 2

CLand1::CLand1(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = LAND1TYPE;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES),
		D3DXVECTOR2(721, 377), 2, 1, D3DXVECTOR2(653, 343), 
		D3DXVECTOR2(1,1),  D3DXVECTOR2(1,1));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);	

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite() * NUMB_SPRITE, m_Sprite->GetHeightRectSprite());
	UpdateRect();
}


CLand1::~CLand1(void)
{
}

void CLand1::Update(float _time, CCamera *_camera, CInput *_input)
{
	m_Sprite->IndexOf(0);
}


void CLand1::Collision()
{

}

void CLand1::Render(LPD3DXSPRITE _sp, CCamera* _camera)
{
	D3DXVECTOR3 pos = m_pos;
	for (int i = 0; i < NUMB_SPRITE; i++)
	{
		m_Sprite->IndexOf(i);
		pos.x = m_pos.x + i * m_Sprite->GetWidthRectSprite();
		CEntity::RenderEachSprite(_sp, _camera, pos);
	}
}
