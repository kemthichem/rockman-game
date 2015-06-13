#include "Flea.h"

CFlea::CFlea(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = FLEA;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(663, 296) , 2, 1, D3DXVECTOR2(513,258), D3DXVECTOR2(0,0), D3DXVECTOR2(43,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();
}


CFlea::~CFlea(void)
{
}

void CFlea::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	m_Sprite->Next(_deltaTime);
}
