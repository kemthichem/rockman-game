#include "Land2.h"

CLand2::CLand2(int _id, D3DXVECTOR3 _pos, bool _isCheckCollison)
{
	m_Id = _id;
	m_Type = _isCheckCollison ? LAND2 : SCENERY;
	m_NumSprite = 1;

	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES),
		D3DXVECTOR2(721, 377), 2, 1,  D3DXVECTOR2(653, 343), 
		D3DXVECTOR2(1,1),  D3DXVECTOR2(1,1));
	m_pos = _pos;
	m_pos.z = DEPTH_BLOCK;
	m_accel = D3DXVECTOR2(0,0);	

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite() * m_NumSprite, m_Sprite->GetHeightRectSprite());
	UpdateRect();
}


CLand2::~CLand2(void)
{
}

void CLand2::Update(float _time, CCamera *_camera, CInput *_input)
{
	m_Sprite->IndexOf(0);
}


void CLand2::Render(LPD3DXSPRITE _sp, CCamera* _camera)
{
	D3DXVECTOR3 pos = m_pos;
	for (int i = 0; i < m_NumSprite; i++)
	{
		m_Sprite->IndexOf(i);
		pos.x = m_pos.x + i * m_Sprite->GetWidthRectSprite();
		CEntity::RenderEachSprite(_sp, _camera,m_Sprite, pos);
	}
}
