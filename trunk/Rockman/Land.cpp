#include "Land.h"


CLand::CLand(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = ObjectType::LANDTYPE;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES), D3DXVECTOR2(70,30), 1, 1);
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);	

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
}


CLand::~CLand(void)
{
}

void CLand::Update(float _deltaTime, CCamera *_camera, CInput *_input)
{
	m_Sprite->IndexOf(0);
}

void CLand::Draw()
{

}

void CLand::Collision()
{

}