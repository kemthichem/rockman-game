#include "Beak.h"


CBeak::CBeak(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = BEAK;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(300, 450) , 1, 4, D3DXVECTOR2(300, 420), D3DXVECTOR2(40, 420), D3DXVECTOR2(0,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_velloc.x = -10;
	m_accel.y = -5.0f;

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
}


CBeak::~CBeak(void)
{

}

void CBeak::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{	

}

void CBeak::Draw()
{

}

void CBeak::Collision()
{

}

