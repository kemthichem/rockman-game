#include "LandWhite.h"


CLandWhite::CLandWhite(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = LANDWHITE;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES),
		D3DXVECTOR2(857, 35), 3, 1, D3DXVECTOR2(755, 1), 
		D3DXVECTOR2(1,1),  D3DXVECTOR2(1,1));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);	

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite() * 3, m_Sprite->GetHeightRectSprite());
}


CLandWhite::~CLandWhite(void)
{
}

void CLandWhite::Update(float _time, CCamera *_camera, CInput *_input)
{
	
}


void CLandWhite::Collision()
{

}

void CLandWhite::Render(LPD3DXSPRITE _sp, CCamera* _camera)
{
	D3DXVECTOR3 pos = m_pos;
	for (int i = 0; i < 3; i++)
	{
		m_Sprite->IndexOf(i);
		pos.x = m_pos.x + i * m_Sprite->GetWidthRectSprite();
		CEntity::RenderEachSprite(_sp, _camera, pos);
	}
}
