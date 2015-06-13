#include "Beak.h"


CBeak::CBeak(int _id, D3DXVECTOR3 _pos, bool _isLeft)
{
	m_Id = _id;
	m_Type = BEAK;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(360, 455) , 4, 1, D3DXVECTOR2(40,420), D3DXVECTOR2(0, 0), D3DXVECTOR2(50,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_isTurnLeft = _isLeft;

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();

}


CBeak::~CBeak(void)
{

}

void CBeak::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{	
	m_Sprite->Next(_deltaTime);
}


