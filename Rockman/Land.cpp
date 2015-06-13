#include "Land.h"
#define  NUMB_SPRITE 4

CLand::CLand(int _id, D3DXVECTOR3 _pos, bool _isCheckCollison)
{
	m_Id = _id;
	m_Type = _isCheckCollison ? LAND : SCENERY;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES), D3DXVECTOR2(140,35), 4, 1, D3DXVECTOR2(3,1), D3DXVECTOR2(1,1), D3DXVECTOR2(1,1));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);	

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite() * NUMB_SPRITE, m_Sprite->GetHeightRectSprite());
	UpdateRect();
}


CLand::~CLand(void)
{
}

void CLand::Update(float _deltaTime, CCamera *_camera, CInput *_input)
{
	m_Sprite->IndexOf(0);
}

void CLand::Render(LPD3DXSPRITE _sp, CCamera* _camera)
{
	D3DXVECTOR3 pos = m_pos;
	for (int i = 0; i < NUMB_SPRITE; i++)
	{
		m_Sprite->IndexOf(i);
		pos.x = m_pos.x + i * m_Sprite->GetWidthRectSprite();
		CEntity::RenderEachSprite(_sp, _camera,m_Sprite, pos);
	}
}