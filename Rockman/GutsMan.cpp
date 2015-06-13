#include "GutsMan.h"

CGutsMan::CGutsMan(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = GUTSMAN;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MASTER), D3DXVECTOR2(880, 210) , 9, 1, D3DXVECTOR2(250,140), D3DXVECTOR2(0,0), D3DXVECTOR2(0,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();
}


CGutsMan::~CGutsMan(void)
{
}

void CGutsMan::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	m_Sprite->Next(_deltaTime);
}
