#include "Flea.h"

CFlea::CFlea(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = FLEA;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(620, 370) , 1, 2, D3DXVECTOR2(510, 340), D3DXVECTOR2(0,30), D3DXVECTOR2(0,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_velloc.x = -10;
	m_accel.y = -5.0f;

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
}


CFlea::~CFlea(void)
{
}

void CFlea::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	
}

void CFlea::Draw()
{

}

void CFlea::Collision()
{

}
