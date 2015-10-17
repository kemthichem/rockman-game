#include "Land1.h"
#include "Define.h"

CLand1::CLand1(int _id, D3DXVECTOR3 _pos, int _type)
{
	m_Id = _id;
	m_Type = _type >= 0  ? LAND1 : SCENERY;
	if (_type == -2) _type = 0;
	m_NumSprite = _type == 0? 1 : 2;
	D3DXVECTOR2 src = _type == 0? D3DXVECTOR2(720,376) : D3DXVECTOR2(653, 343);
	D3DXVECTOR2 des = _type == 0? D3DXVECTOR2(754, 410) : D3DXVECTOR2(721, 377);
	int countCol = _type == 0? 1 : 2;
	
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES),
		des, countCol, 1, src, 
		D3DXVECTOR2(1,1),  D3DXVECTOR2(1,1));
	m_pos = _pos;
	m_pos.z = DEPTH_BLOCK;
	m_accel = D3DXVECTOR2(0,0);	

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite() * m_NumSprite, m_Sprite->GetHeightRectSprite());
	UpdateRect();
}


CLand1::~CLand1(void)
{
}

void CLand1::Update(float _time, CCamera *_camera, CInput *_input)
{
	m_Sprite->IndexOf(0);
}


void CLand1::Render(LPD3DXSPRITE _sp, CCamera* _camera)
{
	D3DXVECTOR3 pos = m_pos;
	for (int i = 0; i < m_NumSprite; i++)
	{
		m_Sprite->IndexOf(i);
		pos.x = m_pos.x + i * m_Sprite->GetWidthRectSprite();
		CEntity::RenderEachSprite(_sp, _camera,m_Sprite, pos);
	}
}
