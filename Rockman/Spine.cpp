#include "Spine.h"

CSpine::CSpine(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = SPINE;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(504, 208) , 2, 1, D3DXVECTOR2(352,190), D3DXVECTOR2(0,0), D3DXVECTOR2(44,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();
}

CSpine::CSpine(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide)
{
	m_Id = objID;
	m_Type = SPINE;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(504, 208) , 2, 1, D3DXVECTOR2(352,190), D3DXVECTOR2(0,0), D3DXVECTOR2(44,0));

	m_Size = D3DXVECTOR2(widthCollide, heightCollide);
	m_pos = D3DXVECTOR3(posXCollide, posYCollide, 0);
	UpdateRect();
}

CSpine::~CSpine(void)
{
}

void CSpine::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{	
	m_Sprite->Next(_deltaTime);
}
