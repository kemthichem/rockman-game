#include "Land3.h"
#include "Define.h"

#define  NUMB_SPRITE 2

CLand3::CLand3(int _id, D3DXVECTOR3 _pos, bool _isCheckCollison)
{
	m_Id = _id;
	m_Type = _isCheckCollison ? LAND3 : SCENERY;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES),
		D3DXVECTOR2(856, 478), 2, 2, D3DXVECTOR2(788, 410), 
		D3DXVECTOR2(1,1),  D3DXVECTOR2(1,1));
	m_pos = _pos;
	m_pos.z = DEPTH_BLOCK;
	m_accel = D3DXVECTOR2(0,0);	

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite() * NUMB_SPRITE, m_Sprite->GetHeightRectSprite() * NUMB_SPRITE);
	UpdateRect();
}


CLand3::~CLand3(void)
{
}

void CLand3::Update(float _time, CCamera *_camera, CInput *_input)
{
	m_Sprite->IndexOf(0);
}


void CLand3::Render(LPD3DXSPRITE _sp, CCamera* _camera)
{
	D3DXVECTOR3 pos = m_pos;
	for (int i = 0; i < NUMB_SPRITE; i++)
	{
		m_Sprite->IndexOf(i);
		pos.x = m_pos.x + i * m_Sprite->GetWidthRectSprite();
		CEntity::RenderEachSprite(_sp, _camera,m_Sprite, pos);

		//Draw frame down
		m_Sprite->IndexOf(i + NUMB_SPRITE) ;
		pos.x = m_pos.x + i * m_Sprite->GetWidthRectSprite();
		pos.y = m_pos.y - m_Sprite->GetHeightRectSprite();
		CEntity::RenderEachSprite(_sp, _camera,m_Sprite, pos);

		//reset
		pos = m_pos;			 
	}
}
