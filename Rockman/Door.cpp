#include "Door.h"
#include "ResourceManager.h"
CDoor::CDoor(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	//m_Type = DOO;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES), D3DXVECTOR2(830, 50) , 2, 1, D3DXVECTOR2(670,20), D3DXVECTOR2(0,0), D3DXVECTOR2(40,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();
}

CDoor::CDoor(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide)
{
	m_Id = objID;
	m_Type = DOOR1_CUTMAN;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES), D3DXVECTOR2(130, 305) , 1, 1, D3DXVECTOR2(0, 240), D3DXVECTOR2(0,0), D3DXVECTOR2(0,0));
	m_Size = D3DXVECTOR2(widthCollide, heightCollide);
	m_pos = D3DXVECTOR3(posXCollide, posYCollide, 0);

	UpdateRect();
}


CDoor::~CDoor(void)
{
}

void CDoor::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	m_Sprite->Next(_deltaTime);
}

void CDoor::Draw()
{

}

