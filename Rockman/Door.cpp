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

CDoor::CDoor(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide, bool _isEndDoor)
{
	m_Id = objID;
	m_Type = DOOR1_CUTMAN;
	m_isEndDoor = _isEndDoor;

	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES), D3DXVECTOR2(160, 274) , 5, 1, D3DXVECTOR2(0, 210));
	m_Sprite->IndexOf(0);
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_pos = D3DXVECTOR3(posX - m_Size.x / 2, posY + m_Size.y / 2, 0);
	m_isActived = false;

	UpdateRect();
}


CDoor::~CDoor(void)
{
}

void CDoor::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	if (m_isActived) {
			if (m_Sprite->m_CurrentIndex < 4) {
				m_Sprite->Next(_deltaTime);
			} else
			{
				CCamera::g_IsMoving = true;
				m_isActived = false;
				m_IsCheckCollision = false;
			}
	}
	else
	{
		if (m_Sprite->m_CurrentIndex > 0) {
			m_Sprite->Next(_deltaTime);
		} else {
			m_IsCheckCollision = true;
		}
	}
}

void CDoor::ActiveDoor()
{
	m_isActived = true;
}
