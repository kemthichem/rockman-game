#include "LandIceberg.h"
#include "Define.h"

#define  NUMB_SPRITE 2

CLandIceberg::CLandIceberg(int _id, D3DXVECTOR3 _pos, bool _isCheckCollison)
{
	m_Id = _id;
	m_Type = _isCheckCollison ? LANDICEBERG : SCENERY;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES),
		D3DXVECTOR2(277, 162), 2, 1, D3DXVECTOR2(209,128), 
		D3DXVECTOR2(1,1),  D3DXVECTOR2(1,1));
	m_pos = _pos;
	m_pos.z = DEPTH_BLOCK;
	m_accel = D3DXVECTOR2(0,0);	

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite() * NUMB_SPRITE, m_Sprite->GetHeightRectSprite());
	UpdateRect();
}


CLandIceberg::~CLandIceberg(void)
{
}

void CLandIceberg::Update(float _time, CCamera *_camera, CInput *_input)
{
	
}


void CLandIceberg::Render(LPD3DXSPRITE _sp, CCamera* _camera)
{
	D3DXVECTOR3 pos = m_pos;
	for (int i = 0; i < NUMB_SPRITE; i++)
	{
		m_Sprite->IndexOf(i);
		pos.x = m_pos.x + i * m_Sprite->GetWidthRectSprite();
		CEntity::RenderEachSprite(_sp, _camera,m_Sprite, pos);
	}
}
