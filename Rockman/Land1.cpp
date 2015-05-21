#include "Land1.h"


CLand1::CLand1(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = ObjectType::LAND1TYPE;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES), D3DXVECTOR2(70,30), 1, 1);
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);	
}


CLand1::~CLand1(void)
{
}

void CLand1::Update(float _time, CCamera *_camera, CInput *_input)
{
	m_Sprite->IndexOf(0);
}

void CLand1::Draw()
{

}

void CLand1::Collision()
{

}
